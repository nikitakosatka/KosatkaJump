#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "TXLib.h"

class Player {
    public:
        HDC player = txLoadImage("data\\images\\ball.bmp");
        int x = 200;
        double y = 900;
        double speeding = 4.5;
        double minY = 350;
        bool moving = false;
        int score = 0;
        int highScore = 0;
        char strScore[1024];
        char strHighScore[1024];

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

            if (speeding > 0) {
                if (score % 1 == 0)
                    score += (int) speeding;
                    if (score > highScore)
                        highScore = score;
                itoa(score, strScore, 10);
                itoa(highScore, strHighScore, 10);
            }
            txTransparentBlt(txDC(), x, y, 45, 45, player, 0, 0, RGB(255, 255, 255));
        }

        void control() {
            if (GetAsyncKeyState(VK_LEFT)) {
                x -= 2;
                if (x < -22)
                    x = 377;
            }

            if (GetAsyncKeyState(VK_RIGHT)) {
                x += 2;
                if (x > 378)
                    x = -22;
            }
        }
};

