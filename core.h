#ifndef CORE_H
#define CORE_H

class rgbColor {
  public:
    int r, g, b;

    // Constructor to quickly define colors
    rgbColor(int red, int green, int blue) {
        r = red;
        g = green;
        b = blue;
    }
};

class led {
  public: 
    int redPin, greenPin, bluePin;

    led(int rPin, int gPin, int bPin);

    void setColor(struct rgbColor color);
};

class Crystal;

class Animation {
  protected:
    Crystal *owner = nullptr;          

  public:
    virtual ~Animation() {}

    // called by Crystal after construction
    void attach(Crystal *c) { owner = c; }

    virtual void ignite()      = 0;    
    virtual void hum()         = 0;
    virtual void deactivate()  = 0;
};

class Crystal {
  public:
    led crystalLed;
    rgbColor crystalColor;
    Animation *animation;

    Crystal(led &LED, rgbColor color, Animation *anim):
      crystalLed(LED), crystalColor(color), animation(anim) {
        if (animation) animation->attach(this);
    }

  inline void ignite()     { if (animation) animation->ignite();     }
  inline void deactivate() { if (animation) animation->deactivate(); }
  inline void hum()        { if (animation) animation->hum();        }
};



#endif