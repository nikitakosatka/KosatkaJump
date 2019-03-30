#include <iostream>
#include "TXLib.h"
#include "player.h"
#include "game.h"

class StartScreen {
    public:
        void Run() {
            bool running = true;

            HDC logo = txLoadImage("data\\images\\logo.bmp");
            HDC background = txLoadImage("data\\images\\start_background.bmp");
            HDC playButton = txLoadImage("data\\images\\play.bmp");

            while (running) {
                txBitBlt(txDC(), 0, 0, 400, 800, background, 0, 0);
                txTransparentBlt(txDC(), (400 - 163) / 2, 300, 163, 78, playButton, 0, 0, RGB(255, 255, 255));
                txTransparentBlt(txDC(), (400 - 285) / 2, 100, 285, 152, logo, 0, 0, RGB(255, 255, 255));

                while (txMouseButtons() != 1) {
                    if ((400 + 163) / 2 >= txMouseX() and txMouseX() >= (400 - 163) / 2 and txMouseButtons() & 1
                        and txMouseY() >= 300 and txMouseY() <= 463) {
                        running = false;
                        break;
                    }
                }
                txSleep(1);
            }
            txDeleteDC(background);
        }
};
