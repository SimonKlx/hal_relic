#include "hal_relic/plugin_hal_relic.h"

namespace hal
{

    extern std::unique_ptr<BasePluginInterface> create_plugin_instance()
    {
        return std::make_unique<HalRelicPlugin>();
    }

    std::string HalRelicPlugin::get_name() const
    {
        return std::string("hal_relic");
    }

    std::string HalRelicPlugin::get_version() const
    {
        return std::string("0.1");
    }

    void HalRelicPlugin::initialize()
    {

    }
}
