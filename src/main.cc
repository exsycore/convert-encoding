#include "main.h"

StringView Convert::componentName() const {
    return Plugin::Instance().Name();
}

SemanticVersion Convert::componentVersion() const {
    auto [major, minor, patch] =
        Plugin::VersionToTuple(Plugin::Instance().Version());
    return SemanticVersion(0, major, minor, patch);
}

void Convert::onLoad(ICore* c) {
    core_ = c;
    getCore() = c;
}

void Convert::onInit(IComponentList* components) {
    pawn_ = components->queryComponent<IPawnComponent>();
    if (!pawn_) {
        StringView name = componentName();

        core_->logLn(LogLevel::Error,
                    "Error loading component %.*s: Pawn component not loaded",
                    name.length(), name.data());
        return;
    }

    core_->getEventDispatcher().addEventHandler(this);
    pawn_->getEventDispatcher().addEventHandler(this);

    plugin_data_[PLUGIN_DATA_LOGPRINTF] =
        reinterpret_cast<void *>(&PluginLogprintf);
    plugin_data_[PLUGIN_DATA_AMX_EXPORTS] =
        const_cast<void **>(pawn_->getAmxFunctions().data());
    
    Plugin::DoLoad(plugin_data_);
}

void Convert::onReady() {}

void Convert::onTick(Microseconds elapsed, TimePoint now) {}

void Convert::onFree(IComponent* component) {
    if (component == pawn_ || component == this) {
        Plugin::DoUnload();
        if (pawn_) {
            pawn_->getEventDispatcher().removeEventHandler(this);
            core_->getEventDispatcher().removeEventHandler(this);
        }
        pawn_ = nullptr;
    }
}

void Convert::free() {
    delete this;
}

void Convert::reset() {}

void Convert::onAmxLoad(IPawnScript& script) {
    Plugin::DoAmxLoad(static_cast<AMX *>(script.GetAMX()));
}

void Convert::onAmxUnload(IPawnScript& script) {}

Convert::~Convert() {}

void Convert::PluginLogprintf(const char* fmt, ...) {
    auto core = getCore();
    if (!core) {
        return;
    }

    va_list args{};

    va_start(args, fmt);

    core->vprintLn(fmt, args);

    va_end(args);
}

ICore *&Convert::getCore() {
    static ICore *core{};

    return core;
}

COMPONENT_ENTRY_POINT() { return new Convert(); }