#include "../knihovna/czech.h"
#include "../knihovna/helper.h"
#include <stdlib.h>

#define DEN "05"
#define POČET_BIT 10
#define DÉLKA_VSTUPU 885

číslo porovnej(neměnné prázdno* a, neměnné prázdno* b) {
    vrať(číslo)(*(číslo64_t*)a - *(číslo64_t*)b);
}

číslo hlavní(prázdno) {
    znak sedadlo[POČET_BIT];
    číslo64_t maximum = INT64_MIN;
    číslo64_t sedadlá[DÉLKA_VSTUPU];
    číslo64_t početSedadel = 0;

    zatímco(čtif("%s", sedadlo) > 0) {
        pro(znak* aktuální_znak = sedadlo; *aktuální_znak; ++aktuální_znak) {
            přepínač(*aktuální_znak) {
                případ 'F' : * aktuální_znak = '0';
                break;
                případ 'B' : * aktuální_znak = '1';
                break;
                případ 'L' : * aktuální_znak = '0';
                break;
                případ 'R' : * aktuální_znak = '1';
                break;
            }
        }

        číslo64_t čísloSedadla = řeťnad(sedadlo, NULA, 2);
        maximum = čísloSedadla > maximum ? čísloSedadla : maximum;
        sedadlá[početSedadel] = čísloSedadla;
        ++početSedadel;
    }

    číslo64_t mojeSedadlo = -1;
    qsort(sedadlá, početSedadel, velikost(číslo64_t), porovnej);
    pro(číslo64_t index = 0; index < početSedadel - 2; ++index) {
        číslo64_t současné = sedadlá[index];
        pokud(sedadlá[index + 1] == současné + 2) {
            mojeSedadlo = současné + 1;
            rozbij;
        }
    }

    tiskni_řešení(DEN, maximum, mojeSedadlo);
}
