#include <Arduino.h>
#include "./v_strings.h"

VArrayList<String> VStrings::splitBy(String source, char delimiter) {
    VArrayList<String> result;
    String current;
    for (size_t i = 0;i<source.length();i++) {
        if (source[i]==delimiter) {
            if (current.length()>0) {
                result.add(current);
            }
            current = "";
        }
        else {
            current+=source[i];
        }
    }
    // Don't forget to add the last part
    if (current.length() > 0) {
        result.add(current);
    }
    return result;
}