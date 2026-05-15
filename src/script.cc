#include "script.h"

#include <tis620.h>

#define TIS620  "TIS-620"
#define UTF8    "UTF-8"

cell Script::ConvertEncoding(std::string input, std::string from, std::string to, cell* output, cell size) {
    if (from == TIS620 && to == UTF8) {
        std::string utf8 = tis620::to_utf8(input);
        SetString(output, utf8, size);
        return 1;
    } else if (from == UTF8 && to == TIS620) {
        std::string tis = tis620::from_utf8(input);
        SetString(output, tis, size);
        return 1;
    } else {
        return 0;
    }
    return 0;
}