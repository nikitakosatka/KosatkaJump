#include <iostream>
#include "TXLib.h"

class DisappearingPlatform {
    public:
        HDC platform = txLoadImage("data\\images\\disappearing_platform.bmp");
        double x;
        double y;

        DisappearingPlatform(int X, double Y) {
            x = X;
            y = Y;
        }

        DisappearingPlatform(int y) {
            x = rand() & 200;
        }

        DisappearingPlatform() {
            x = rand() & 200;
            y = -100;
        }

        void spawn() {
            txTransparentBlt(txDC(), x, y, 77, 16, platform, 0, 0, RGB(255, 255, 255));
        }

        void update(double speeding) {
            if (y > 800) {
                y = -100;
            }

            y += speeding;
            txTransparentBlt(txDC(), x, y, 77, 16, platform, 0, 0, RGB(255, 255, 255));
        }

        void disappear() {
            x = -100;
            y = -100;
        }
};

