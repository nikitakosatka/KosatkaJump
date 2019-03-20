#include <iostream>
#include "TXLib.h"

class Platform {
    public:
        HDC platform = txLoadImage("data\\images\\platform.bmp");
        int x;
        double y;

        Platform(int X, double Y) {
            x = X;
            y = Y;
        }

        Platform(int y) {
            x = rand() & 200;
        }

        Platform() {
            x = rand() & 200;
            y = -100;
        }

        void spawn() {
            txBitBlt(txDC(), x, y, 400, 800, platform, 0, 0);
        }

        void update(double speeding) {
            if (y > 800) {
                y = -100;
            }

            y += speeding;
            txBitBlt(txDC(), x, y, 400, 800, platform, 0, 0);
        }
};
