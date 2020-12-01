#include "czech.h"
#include <stdio.h>
#include <stdlib.h>

číslo* rozparsuj_účtenku(znak* jméno_souboru, číslo délka) {
    SOUBOR* soubor = sotevři(jméno_souboru, ČTENÍ);
    číslo* účtenka = ppřiděl(délka * velikost(číslo));

    pro(velikost_t i = 0; i < délka; ++i) {
        sčtif(soubor, "%d", &účtenka[i]);
    }

    szavři(soubor);
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

číslo hlavní(číslo argp, znak** argv) {
    číslo délka = 200;
    číslo suma = 2020;

    číslo* účtenka = rozparsuj_účtenku(argv[1], délka);

    číslo násobek1 = spočti_násobek_dvou(účtenka, délka, suma);
    číslo násobek2 = spočti_násobek_tří(účtenka, délka, suma);

    tisknif("Advent kódu 2020, den 01\n");
    tisknif("První část: %d\n", násobek1);
    tisknif("Druhá část: %d\n", násobek2);

    osvoboď(účtenka);
    vrať 0;
}