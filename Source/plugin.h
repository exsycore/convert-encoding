#ifndef PLUGIN_H
#define PLUGIN_H

#include "script.h"

class Plugin : public ptl::AbstractPlugin<Plugin, Script> {
public:
    const char* Name();
    int Version();
    bool OnLoad();
    void OnUnload();
};

#endif