#include "../knihovna/czech.h"
#include "../knihovna/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEN "02"

číslo hlavní(prázdno) {
    znak heslo[99], písmeno[1];
    číslo min[1], max[1];
    číslo první_část, druhá_část = 0;

    zatímco(čtif("%d-%d %c: %s", min, max, písmeno, heslo) > 0) {
        číslo počet_výskytů = 0;
        pro(znak* aktuální_znak = heslo; *aktuální_znak; ++aktuální_znak) {
            počet_výskytů += *aktuální_znak == *písmeno;
        }

        první_část += *min <= počet_výskytů && počet_výskytů <= *max;
        druhá_část += (heslo[*min - 1] == *písmeno) ^ (heslo[*max - 1] == *písmeno);
    }

    tiskni_řešení(DEN, první_část, druhá_část);
    vrať 0;
}
