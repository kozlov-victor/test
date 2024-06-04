
#include "../src/v_array_list/v_array_list.h"
#include "../src/v_strings/v_strings.h"
#include "../src/v_hash_table/v_hash_table.h"
#include "../src/v_json/v_json.h"

void doTest() {
    VArrayList<String> list;
    list.add("test1");
    list.add("test2");
    list.add("test3");
    list.add("test4");
    list.add("test5");
    list.add("test6");
    list.add("test7");
    list.add("test8");
    list.add("test9");
    list.add("test10");
    list.add("test11");
    list.add("test12");
    list.add("test13");
    list.add("test14");
    list.addAt("inserted",1);
    list.removeAt(0);
    Serial.println(list.size());
    Serial.println(list.indexOf("test9"));
    Serial.println(list.has("test9"));
    Serial.println(list.has("test91"));
    Serial.println(list.empty());
    for (size_t i = 0;i<list.size();i++) {
        Serial.println(list.getAt(i));
    }
    VArrayList<String> parts = VStrings::splitBy("test1+test2,,,,test3,last,WWW,123",',');
    for (size_t i = 0;i<parts.size();i++) {
        Serial.println(parts.getAt(i));
    }
    VHashTable<String> table;
    table["key1"] = "value1";
    table["key1"] = "value1_new";
    table.put("key2","value2");
    table.put("key2","value2_new");
    table.put("key3","value3");
    table.put("key3","value3_new");
    table.remove("key2");
    table.remove("key2_____");
    Serial.println(table.has("key2"));
    table.forEach([](const String key, const String value) {
        Serial.print("Key: ");
        Serial.print(key);
        Serial.print(", Value: ");
        Serial.println(value);
    });
    Serial.println(VJson::stringify(table));

    VHashTable<String> json = VJson::parse("{\"key1\":\"value1\",\"key2\":\"value2\",\"key3\":{\"value3\"}}");
    Serial.println("---json---");
    Serial.println(json.size());
    json.forEach([](const String key, const String value) {
        Serial.print("Key: ");
        Serial.print(key);
        Serial.print(", Value: ");
        Serial.println(value);
    });
    Serial.println(VJson::stringify(json));
}