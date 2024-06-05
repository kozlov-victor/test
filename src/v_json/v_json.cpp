
#include <Arduino.h>
#include "./v_json.h"
#include "../v_hash_table/v_hash_table.h"

/*
не перевіряємо на помилки
працюємо тільки з "пласким" json типу {string:string}
*/

VHashTable<String> VJson::parse(String source){
    bool columnAppeared = false;
    bool quouteAppeared = false;
    String currentKey = "";
    String currentValue = "";
    VHashTable<String> result;
    for (int i=0;i<source.length();i++) {
        char c = source[i];
        
        if (c==':') {
            columnAppeared = true;
            continue;
        }
        if (c=='"') {
            if (quouteAppeared) {  // закриття кавичок
                quouteAppeared = false;
                if (columnAppeared) { // закрилось значення
                    result.put(currentKey,currentValue);
                    currentKey = "";
                    currentValue = "";
                    columnAppeared = false;
                }
                // інакше закрився ключ
            }
            else { // відкриття кавичок
                quouteAppeared = true;
            }
            continue;
        }

        if (quouteAppeared) { // накопичуємо текст 
            if (columnAppeared) { // значення
                currentValue+=c;
            }
            else { // ключа
                currentKey+=c;
            }
        }   
        // інакше проміжні символи {}, space, return - ігноруємо
    }
    return result;
}

String VJson::stringify(VHashTable<String> &table)
{
    String result = "{";
    int cnt = 0;
    size_t size = table.size();
    table.forEach([&result, &cnt, size](const String key, const String value) {
        result += "\"" + key + "\":" + "\"" + value + "\"";
        if (cnt < size - 1) {
            result += ",";
        }
        cnt++;
    });
    result += "}";
    return result;
}