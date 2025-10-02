#include "script.h"

#include <iostream>
#include <string>
#include <windows.h>

#define TIS620  "TIS-620"
#define UTF8    "UTF-8"

std::string TIS620ToUTF8(const std::string &tis) {
    int wlen = MultiByteToWideChar(874, 0, tis.c_str(), -1, nullptr, 0);
    std::wstring wstr(wlen, L'\0');
    MultiByteToWideChar(874, 0, tis.c_str(), -1, &wstr[0], wlen);

    int utf8len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string utf8(utf8len, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &utf8[0], utf8len, nullptr, nullptr);
    return utf8;
}

std::string UTF8ToTIS620(const std::string &utf8) {
    int wlen = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, nullptr, 0);
    std::wstring wstr(wlen, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &wstr[0], wlen);

    int tislen = WideCharToMultiByte(874, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string tis(tislen, '\0');
    WideCharToMultiByte(874, 0, wstr.c_str(), -1, &tis[0], tislen, nullptr, nullptr);
    return tis;
}

cell Script::ConvertEncoding(std::string input, std::string from, std::string to, cell* output, cell size) {
    if (from == TIS620 && to == UTF8) {
        std::string utf8 = TIS620ToUTF8(input);
        SetString(output, utf8, size);
        return 1;
    } else if (from == UTF8 && to == TIS620) {
        std::string tis = UTF8ToTIS620(input);
        SetString(output, tis, size);
        return 1;
    } else {
        return 0;
    }
    return 0;
}