#include "plugin.h"

const char* Plugin::Name() { return "encore Plugin (samp)"; }
int Plugin::Version() { return PACK_PLUGIN_VERSION(2, 0, 0); }

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
    Log("encore v2.0 (samp) unloaded");
}