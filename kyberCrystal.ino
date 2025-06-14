#include <Bounce2.h>
#include "core.h"
#include "animations.h"

int bluePin = 9;
int greenPin = 10;
int redPin = 11;
int btnPin = 4;

led led(redPin, greenPin, bluePin);

rgbColor red(255, 0, 0);
rgbColor green(0, 255, 0);
rgbColor blue(0, 0, 255);
rgbColor purple(255, 0, 255);
rgbColor cyan(0, 255, 255);
rgbColor yellow(255, 255, 0);

Crystal maul(led, red, new SlowAnimation());
Crystal quigon(led, green, new SmoothAnimation());
Crystal kenobi(led, blue, new QuickAnimation());
Crystal windu(led, purple, new SlowAnimation());
Crystal anakin(led, cyan, new SmoothAnimation());
Crystal rey(led, yellow, new QuickAnimation());

Crystal* crystals[] = {&maul, &quigon, &kenobi, &windu, &anakin, &rey};
int crystalIndex = 0;
Crystal* selectedCrystal = crystals[crystalIndex];
const int numCrystals = sizeof(crystals) / sizeof(crystals[0]);

Bounce button = Bounce();

bool on = false;

// For click detection
unsigned long lastClickTime = 0;
int clickCount = 0;
const unsigned long doubleClickDelay = 300; // ms

void setup() {
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);

  button.attach(btnPin);
  button.interval(25);
}

void loop() {
  button.update();

  if (button.fell()) {
    unsigned long now = millis();
    if (now - lastClickTime < doubleClickDelay) {
      clickCount++;
    } else {
      clickCount = 1;
    }
    lastClickTime = now;
  }

  // Check if it's time to process the clicks
  if (clickCount > 0 && millis() - lastClickTime > doubleClickDelay) {
    if (clickCount == 1) {
      // Single click: toggle saber on/off
      if (!on) {
        on = true;
        selectedCrystal->ignite();
      } else {
        selectedCrystal->deactivate();
        on = false;
      }
    } else if (clickCount == 2) {
      // Double click: change crystal
      // if (on) {
      //   selectedCrystal->deactivate();
      //   on = false;
      // }
      selectedCrystal->deactivate();
      crystalIndex = (crystalIndex + 1) % numCrystals;
      selectedCrystal = crystals[crystalIndex];
      selectedCrystal->ignite();
    }

    clickCount = 0;
  }

  // Saber hum
  if (on) {
    selectedCrystal->hum();
  }
}
