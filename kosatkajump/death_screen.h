#include <iostream>
#include "TXLib.h"

class DeathScreen {
    public:
        void Run() {
            bool running = true;

            HDC background = txLoadImage("data\\images\\start_background.bmp");
            HDC playButton = txLoadImage("data\\images\\play.bmp");

            while (running) {
                txBitBlt(txDC(), 0, 0, 400, 800, background, 0, 0);
                txBitBlt(txDC(), (400 - 163) / 2, 300, 400, 800, playButton, 0, 0);

                while (txMouseButtons() != 1) {
                    if ((400 + 163) / 2 >= txMouseX() and txMouseX() >= (400 - 163) / 2 and txMouseButtons() & 1) {
                        running = false;
                        break;
                    }
                }
                txSleep(2);
            }
            txDeleteDC(background);
        }
};
