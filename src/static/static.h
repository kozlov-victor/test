#include <Arduino.h>

struct V_FILE
{
    String mime;
    String content;
    V_FILE(const String& mimeType, const String& fileContent) 
        : mime(mimeType), content(fileContent) {}
};


const V_FILE static_index_html
(
    String("text/html"),
    String(
        R"html(
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <title>TEST</title>
        </head>
        <style type="text/css">
        </style>
        <body>
            test123
            <script src="index.js"></script>
        </body>
        </html>
        )html"
    )    
);

const V_FILE static_index_js
(
    String("text/javascript"),
    String(
        R"html(
        console.log(42);
        )html"
    )    
);