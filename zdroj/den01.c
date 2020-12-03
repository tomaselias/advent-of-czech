#include "../knihovna/czech.h"
#include "../knihovna/helper.h"
#include <stdio.h>
#include <stdlib.h>

#define DEN "01"

číslo* rozparsuj_účtenku(číslo délka) {
    číslo* účtenka = ppřiděl(délka * velikost(číslo));

    pro(velikost_t i = 0; i < délka; ++i) {
        čtif("%d", &účtenka[i]);
    }

    vrať účtenka;
}

číslo spočti_násobek_dvou(číslo* účtenka, číslo délka, číslo suma) {
    pro(velikost_t i = 0; i < délka; ++i) {
        pro(velikost_t j = i + 1; j < délka; ++j) {
            jestliže(účtenka[i] + účtenka[j] == suma) {
                vrať účtenka[i] * účtenka[j];
            }
        }
    }
    vrať 0;
}

číslo spočti_násobek_tří(číslo* účtenka, číslo délka, číslo suma) {
    pro(velikost_t i = 0; i < délka; ++i) {
        pro(velikost_t j = i + 1; j < délka; ++j) {
            pro(velikost_t k = j + 1; k < délka; ++k) {
                jestliže(účtenka[i] + účtenka[j] + účtenka[k] == suma) {
                    vrať účtenka[i] * účtenka[j] * účtenka[k];
                }
            }
        }
    }
    vrať 0;
}

číslo hlavní(prázdno) {
    číslo délka = 200;
    číslo suma = 2020;

    číslo* účtenka = rozparsuj_účtenku(délka);

    číslo násobek1 = spočti_násobek_dvou(účtenka, délka, suma);
    číslo násobek2 = spočti_násobek_tří(účtenka, délka, suma);

    tiskni_řešení(DEN, násobek1, násobek2);

    osvoboď(účtenka);
    vrať 0;
}
