#ifndef HELPER_H_
#define HELPER_H_

#include "czech.h"
#include <stdint.h>
#include <stdio.h>

prázdno tiskni_řešení(neměnný znak* den, neměnné číslo64_t první_část, neměnné číslo64_t druhá_část) {
    tisknif("Advent kódu 2020, den %s%c", den, KŘ);
    tisknif("První část: %lld%c", první_část, KŘ);
    tisknif("Druhá část: %lld%c", druhá_část, KŘ);
    tisknif("%c", KŘ);
}

#endif
