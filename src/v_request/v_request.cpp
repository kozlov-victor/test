#include <Arduino.h>
#include "v_request.h"
#include "../v_hash_table/v_hash_table.h"

VRequest::VRequest(String method, VHashTable<String> *headers, VHashTable<String> *params)  {
    this->method = method;
    this->headers = headers;
    this->params = params;
}