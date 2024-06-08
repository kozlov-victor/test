#ifndef V_REQUEST_H
#define V_REQUEST_H

#include <Arduino.h>
#include "../v_hash_table/v_hash_table.h"

class VRequest {
public:
    String method;
    VHashTable<String> *headers;
    VHashTable<String> *params;

    VRequest(String method, VHashTable<String> *headers, VHashTable<String> *params);

};

#endif