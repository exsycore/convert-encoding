#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <samp-ptl/ptl.h>

class Script : public ptl::AbstractScript<Script> {
public:
    cell ConvertEncoding(std::string input, std::string from, std::string to, cell* output, cell size);
};

#endif