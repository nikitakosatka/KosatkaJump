#include <iostream>
#include "TXLib.h"

class Player {
    public:
        HDC player = txLoadImage("data\\images\\ball.bmp");
        int x = 200;
        double y = 900;
        double speeding = 5;
        double minY = 350;
        bool moving = false;

        void update() {
            if (y > minY) {
                moving = false;
            }
            else {
                moving = true;
            }
            if (!moving or speeding < 0)
                y -= speeding;
            speeding -= 0.02;

            control();

            txBitBlt(txDC(), x, y, 400, 800, player, 0, 0);
        }

        void control() {
            if (GetAsyncKeyState(VK_LEFT)) {
                x -= 2;
                if (x < -39)
                    x = 360;
            }

            if (GetAsyncKeyState(VK_RIGHT)) {
                x += 2;
                if (x > 361)
                    x = -38;
            }
        }
};

