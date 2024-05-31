#ifndef JSON_H
#define JSON_H

#include <Arduino.h>
#include "../v_hash_table/v_hash_table.h"

class VJSon {
private:
    
public:
    static VHashTable<String> parse(String source);
    static String stringify(VHashTable<String> &table);
};


#endif