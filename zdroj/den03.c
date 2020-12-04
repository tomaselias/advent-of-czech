#include "../knihovna/czech.h"
#include "../knihovna/helper.h"
#include <stdint.h>
#include <stdio.h>

#define DEN "03"

#define DÉLKA 323
#define ŠÍŘKA 31
#define STROM '#'

číslo64_t počet_stromů(znak les[DÉLKA][ŠÍŘKA], číslo x, číslo y) {
    číslo64_t počet_stromů = 0;

    číslo souřadnice_x = 0;
    číslo souřadnice_y = 0;

    dokud(souřadnice_y < DÉLKA) {
        počet_stromů += les[souřadnice_y][souřadnice_x] == STROM;

        souřadnice_x = (souřadnice_x + x) % ŠÍŘKA;
        souřadnice_y += y;
    }

    vrať počet_stromů;
}

číslo hlavní(prázdno) {
    znak les[DÉLKA][ŠÍŘKA];

    pro(velikost_t i = 0; i < DÉLKA; ++i) {
        čtif("%s", les[i]);
    }

    číslo směr[5][2] = { { 1, 1 }, { 3, 1 }, { 5, 1 }, { 7, 1 }, { 1, 2 } };

    číslo64_t první_část = počet_stromů(les, směr[1][0], směr[1][1]);

    číslo64_t druhá_část = 1;
    pro(velikost_t i = 0; i < 5; i++) {
        druhá_část *= počet_stromů(les, směr[i][0], směr[i][1]);
    }

    tiskni_řešení(DEN, první_část, druhá_část);
    vrať 0;
}
