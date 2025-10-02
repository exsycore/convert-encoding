#include "plugin.h"

const char* Plugin::Name() { return "C2U Plugin (open.mp)"; }
int Plugin::Version() { return PACK_PLUGIN_VERSION(1, 0, 0); }

bool Plugin::OnLoad() {
    RegisterNative<&Script::ConvertEncoding>("ConvertEncoding");

    Log("\n"
        " |----------------------------------------------------|\n"
        " |               ConvertEncoding (Windows)            |\n"
        " |                  Author: EasyCore                  |\n"
        " |----------------------------------------------------|\n"
    );
    return true;
}

void Plugin::OnUnload() {
    Log("C2U v1.0 (open.mp) unloaded");
}