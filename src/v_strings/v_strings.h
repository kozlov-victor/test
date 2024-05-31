#ifndef V_STRINGS_H
#define V_STRINGS_H

#include <Arduino.h>
#include "../v_array_list/v_array_list.h"

class VStrings {
public:
    static VArrayList<String> splitBy(String source, char delimiter);
};

#endif;