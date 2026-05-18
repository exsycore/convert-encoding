#ifndef MAIN_H
#define MAIN_H

#include "script.h"
#include "plugin.h"

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData);
PLUGIN_EXPORT void PLUGIN_CALL Unload();
PLUGIN_EXPORT void PLUGIN_CALL AmxLoad(AMX *amx);
PLUGIN_EXPORT void PLUGIN_CALL AmxUnload(AMX *amx);
PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports();

#endif