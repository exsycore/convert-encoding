#ifndef MAIN_H
#define MAIN_H

#include <sdk.hpp>
#include <Server/Components/Pawn/pawn.hpp>

#ifdef THISCALL
#undef THISCALL
#endif

#ifdef _WIN32
#define THISCALL __thiscall
#else
#define THISCALL
#endif

#include "script.h"
#include "plugin.h"

class Convert final : public IComponent, public CoreEventHandler, public PawnEventHandler {
public:
    PROVIDE_UID(0xBA284FB180FCD75A);

    StringView componentName() const override;

    SemanticVersion componentVersion() const override;

    void onLoad(ICore *c) override;

    void onInit(IComponentList *components) override;

    void onReady() override;

    void onTick(Microseconds elapsed, TimePoint now) override;

    void onFree(IComponent *component) override;

    void free() override;

    void reset() override;

    void onAmxLoad(IPawnScript& script) override;

    void onAmxUnload(IPawnScript& script) override;

    static void PluginLogprintf(const char *fmt, ...);
    
    static ICore *&getCore();

    ~Convert();

private:
    ICore *core_ = nullptr;
    IPawnComponent* pawn_{};

    void *plugin_data_[MAX_PLUGIN_DATA]{};
};

#endif