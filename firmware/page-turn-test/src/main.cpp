#include <Arduino.h>
#include <SPI.h>
#include <GxEPD2_BW.h>

// E Ink display pins
#define EPD_MOSI 11
#define EPD_SCK  12
#define EPD_CS   13
#define EPD_DC   14
#define EPD_RST  15
#define EPD_BUSY 16

// Navigation wheel pins
#define BUTTON_RIGHT 6
#define BUTTON_LEFT  8
#define ENCODER_A    9
#define ENCODER_B    10

// Our 5.76-inch Good Display panel
GxEPD2_BW<GxEPD2_576_GDEH0576T81, 64> display(
    GxEPD2_576_GDEH0576T81(
        EPD_CS, EPD_DC, EPD_RST, EPD_BUSY
    )
);

// Two pages of sample text
const char* page1[] = {
    "The old observatory stood above town.",
    "No one had used its telescope in years.",
    "",
    "One afternoon, a light appeared in the",
    "dome. It moved slowly, sweeping across",
    "the hills as the sun went down.",
    "",
    "Mara climbed the path to investigate.",
    "Inside, the air smelled of cedar and",
    "dust. A notebook rested on a desk.",
    "",
    "The first page was dated tomorrow.",
    "",
    "Beside the date, someone had written:",
    "",
    "'Look toward the eastern horizon.'"
};

const char* page2[] = {
    "She waited until the sky turned dark.",
    "Then, above the farthest hill, a small",
    "white light flickered into view.",
    "",
    "It was too steady to be an airplane.",
    "Too bright to be an ordinary star.",
    "",
    "Mara opened the notebook again.",
    "The next page contained a diagram of",
    "three circles surrounding a point.",
    "",
    "She adjusted the telescope and looked.",
    "",
    "What she saw would keep her awake",
    "for a very long time.",
    "",
    "THE END"
};

const int linesPerPage = 16;
int currentPage = 0;

int lastA;
bool wasLeftPressed;
bool wasRightPressed;

unsigned long lastTurn = 0;

// Draw the selected page
void showPage() {
    Serial.print("Displaying page ");
    Serial.println(currentPage + 1);

    const char* const* lines =
        (currentPage == 0) ? page1 : page2;

    display.setFullWindow();
    display.firstPage();

    do {
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);

        // Book title
        display.setTextSize(3);
        display.setCursor(45, 85);
        display.print("THE OBSERVATORY");

        // Line underneath the title
        display.drawLine(
            45, 120,
            display.width() - 45, 120,
            GxEPD_BLACK
        );

        // Body text
        display.setTextSize(2);

        for (int i = 0; i < linesPerPage; i++) {
            display.setCursor(45, 190 + i * 36);
            display.print(lines[i]);
        }

        // Footer
        display.drawLine(
            45, display.height() - 90,
            display.width() - 45,
            display.height() - 90,
            GxEPD_BLACK
        );

        display.setTextSize(2);
        display.setCursor(45, display.height() - 55);
        display.print("Page ");
        display.print(currentPage + 1);
        display.print(" of 2");

    } while (display.nextPage());

    Serial.println("Page refresh completed");
}

void setup() {
    Serial.begin(115200);
    delay(1500);

    Serial.println("=== E-READER PAGE TEST ===");

    // Input configuration
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(ENCODER_A, INPUT_PULLUP);
    pinMode(ENCODER_B, INPUT_PULLUP);

    // SPI and E Ink initialization
    SPI.begin(EPD_SCK, -1, EPD_MOSI, EPD_CS);

    display.init(115200);

    // Portrait orientation
    display.setRotation(1);

    Serial.println("Display ready");

    // Draw the first page
    showPage();

    // Record current input states
    lastA = digitalRead(ENCODER_A);
    wasLeftPressed = (digitalRead(BUTTON_LEFT) == LOW);
    wasRightPressed = (digitalRead(BUTTON_RIGHT) == LOW);

    lastTurn = millis();
}

void loop() {
    int direction = 0;

    // Check Left and Right buttons
    bool leftPressed =
        (digitalRead(BUTTON_LEFT) == LOW);

    bool rightPressed =
        (digitalRead(BUTTON_RIGHT) == LOW);

    if (rightPressed && !wasRightPressed) {
        direction = 1;
    }
    else if (leftPressed && !wasLeftPressed) {
        direction = -1;
    }

    wasLeftPressed = leftPressed;
    wasRightPressed = rightPressed;

    // Check rotary wheel
    int currentA = digitalRead(ENCODER_A);

    if (direction == 0 &&
        currentA != lastA &&
        currentA == LOW) {

        if (digitalRead(ENCODER_B) == HIGH) {
            direction = 1;
        } else {
            direction = -1;
        }
    }

    lastA = currentA;

    // Turn page, with a short debounce delay
    if (direction != 0 &&
        millis() - lastTurn >= 180) {

        int nextPage = currentPage + direction;

        if (nextPage >= 0 && nextPage < 2) {
            currentPage = nextPage;
            showPage();
        }

        // Recheck inputs after screen refresh
        lastA = digitalRead(ENCODER_A);
        wasLeftPressed =
            (digitalRead(BUTTON_LEFT) == LOW);
        wasRightPressed =
            (digitalRead(BUTTON_RIGHT) == LOW);

        lastTurn = millis();
    }

    delay(3);
}
