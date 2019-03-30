#include <iostream>
#include <ctime>
#include "TXLib.h"
#include "start_screen.h"
#include "platform.h"
#include "player.h"
#include "death_screen.h"
#include "disappearing_platform.h"

class Game {
    public:
        Game() {
            txCreateWindow(400, 800);
        }

        void Run() {
            HDC background = txLoadImage("data\\images\\background.bmp");

            double coordinates[2] = {0, -800};

            StartScreen start;
            start.Run();

            //Platform platforms[5];

            Platform platform1(rand() & 200, 100);
            Platform platform2(rand() & 200, 300);
            Platform platform3(rand() & 200, 500);
            Platform platform4(rand() & 200, 700);
            Platform platform5(rand() & 200, -100);

            DisappearingPlatform disPlatform(rand() & 200, -50);

            Player player;

            txBegin();

            while (true) {
                txBitBlt(txDC(), 0, coordinates[0], 400, 800, background, 0, 0);
                txBitBlt(txDC(), 0, coordinates[1], 400, 800, background, 0, 0);

                //for (int i = 0; i <= 5; i++) {
                    //platforms[i].spawn();
                //}

                platform1.spawn();
                platform2.spawn();
                platform3.spawn();
                platform4.spawn();
                platform5.spawn();
                disPlatform.spawn();

                if (coordinates[0] >= 800) {
                    coordinates[0] = 0;
                    coordinates[1] = -800;
                }

                else if (player.moving and player.speeding > 0) {
                    //for (int i = 0; i <= 5; i++) {
                    //    platforms[i].update();
                    //}

                    platform1.update(player.speeding);
                    platform2.update(player.speeding);
                    platform3.update(player.speeding);
                    platform4.update(player.speeding);
                    platform5.update(player.speeding);
                    disPlatform.update(player.speeding);

                    coordinates[0] += player.speeding / 2;
                    coordinates[1] += player.speeding / 2;
                }

                player.update();

                if (player.speeding < 0 and ((player.y + 38 > platform1.y and player.y + 38 < platform1.y + 15 and
                                              player.x + 20 > platform1.x and player.x + 20 < platform1.x + 40) or
                                             (player.y + 38 > platform2.y and player.y + 38 < platform2.y + 15 and
                                              player.x + 20 > platform2.x and player.x + 20 < platform2.x + 40) or
                                             (player.y + 38 > platform3.y and player.y + 38 < platform3.y + 15 and
                                              player.x + 20 > platform3.x and player.x + 20 < platform3.x + 40) or
                                             (player.y + 38 > platform4.y and player.y + 38 < platform4.y + 5 and
                                              player.x + 20 > platform4.x and player.x + 20 < platform4.x + 40) or
                                             (player.y + 38 > platform5.y and player.y + 38 < platform5.y + 15 and
                                              player.x + 20 > platform5.x and player.x + 20 < platform5.x + 40) or
                                             (player.y + 38 > disPlatform.y and player.y + 38 < disPlatform.y + 15 and
                                              player.x + 20 > disPlatform.x and player.x + 20 < disPlatform.x + 40))) {
                    player.speeding = 4.5;
                    if (player.y + 38 > disPlatform.y and player.y + 38 < disPlatform.y + 15
                        and player.x + 20 > disPlatform.x and player.x + 20 < disPlatform.x + 40) {
                            disPlatform.disappear();
                        }
                }

                txSetColor(RGB(255, 0, 125));
                txSelectFont("Impact", 34);
                txTextOut(10, 40, "Score:");
                txTextOut(60, 40, player.strScore);

                if (player.y > 810 and player.speeding < 0)
                    death();

                txSleep(2);
                txClear();
            }

            txDeleteDC(background);

            txEnd();
        }


        void death() {
            DeathScreen death;
            death.Run();
        }
};
