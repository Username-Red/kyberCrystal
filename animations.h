#include "core.h"

class SmoothAnimation : public Animation {
  public:
    void ignite() override {
      const uint8_t steps = 50;
      for (uint8_t i = 0; i <= steps; ++i) {
        rgbColor tgt = owner->crystalColor;
        rgbColor lvl( (tgt.r * i) / steps,
                      (tgt.g * i) / steps,
                      (tgt.b * i) / steps );
        owner->crystalLed.setColor(lvl);
        delay(8);
      }
    }

    void hum() override {
      static unsigned long lastFlicker = 0;
      const unsigned long flickerInterval = 30; // flicker every 30ms
      unsigned long now = millis();

      if (now - lastFlicker >= flickerInterval) {
        lastFlicker = now;

        rgbColor tgt = owner->crystalColor;

        // Random flicker: +/- 10% of brightness
        float flicker = random(90, 111) / 100.0;

        rgbColor flickerColor(
          min(255, (int)(tgt.r * flicker)),
          min(255, (int)(tgt.g * flicker)),
          min(255, (int)(tgt.b * flicker))
        );

        owner->crystalLed.setColor(flickerColor);
      }
    }


    void deactivate() override {
      const uint8_t steps = 50;
      for (int i = steps; i >= 0; --i) {
        rgbColor tgt = owner->crystalColor;
        rgbColor lvl( (tgt.r * i) / steps,
                      (tgt.g * i) / steps,
                      (tgt.b * i) / steps );
        owner->crystalLed.setColor(lvl);
        delay(8);
      }
    }

};



// Quick Animation
class QuickAnimation : public Animation {
  public:
    void ignite() override {
      const uint8_t steps = 50;
      for (uint8_t i = 0; i <= steps; ++i) {
        rgbColor tgt = owner->crystalColor;
        rgbColor lvl( (tgt.r * i) / steps,
                      (tgt.g * i) / steps,
                      (tgt.b * i) / steps );
        owner->crystalLed.setColor(lvl);
        delay(2);
      }
    }

    void hum() override {
      static unsigned long lastUpdate = 0;
      const unsigned long updateInterval = random(10, 50); // rapid chaotic flicker
      unsigned long now = millis();

      if (now - lastUpdate >= updateInterval) {
        lastUpdate = now;

        rgbColor tgt = owner->crystalColor;

        // Intensity randomly varies between 70% and 120%
        float intensity = random(70, 121) / 100.0;

        // Add occasional red surges or "sparks"
        bool surge = random(0, 10) > 8; // 20% chance to surge

        int r = min(255, (int)(tgt.r * intensity + (surge ? random(30, 100) : 0)));
        int g = min(255, (int)(tgt.g * intensity - (surge ? random(10, 50) : 0)));
        int b = min(255, (int)(tgt.b * intensity - (surge ? random(10, 50) : 0)));

        // Clamp color
        r = constrain(r, 0, 255);
        g = constrain(g, 0, 255);
        b = constrain(b, 0, 255);

        rgbColor unstable(r, g, b);
        owner->crystalLed.setColor(unstable);
      }
    }



    void deactivate() override {
      const uint8_t steps = 50;
      for (int i = steps; i >= 0; --i) {
        rgbColor tgt = owner->crystalColor;
        rgbColor lvl( (tgt.r * i) / steps,
                      (tgt.g * i) / steps,
                      (tgt.b * i) / steps );
        owner->crystalLed.setColor(lvl);
        delay(2);
      }
    }

};



// Slow Animation
class SlowAnimation : public Animation {
  public:
    void ignite() override {
      const uint8_t steps = 50;
      for (uint8_t i = 0; i <= steps; ++i) {
        rgbColor tgt = owner->crystalColor;
        rgbColor lvl( (tgt.r * i) / steps,
                      (tgt.g * i) / steps,
                      (tgt.b * i) / steps );
        owner->crystalLed.setColor(lvl);
        delay(24);
      }
    }

    void hum() override {
      static unsigned long lastFlicker = 0;
      const unsigned long flickerInterval = 80; // flicker every 80ms
      unsigned long now = millis();

      if (now - lastFlicker >= flickerInterval) {
        lastFlicker = now;

        rgbColor tgt = owner->crystalColor;

        // Random flicker: +/- 20% of brightness
        float flicker = random(80, 111) / 100.0;

        rgbColor flickerColor(
          min(255, (int)(tgt.r * flicker)),
          min(255, (int)(tgt.g * flicker)),
          min(255, (int)(tgt.b * flicker))
        );

        owner->crystalLed.setColor(flickerColor);
      }
    }


    void deactivate() override {
      const uint8_t steps = 50;
      for (int i = steps; i >= 0; --i) {
        rgbColor tgt = owner->crystalColor;
        rgbColor lvl( (tgt.r * i) / steps,
                      (tgt.g * i) / steps,
                      (tgt.b * i) / steps );
        owner->crystalLed.setColor(lvl);
        delay(24);
      }
    }

};