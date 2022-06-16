#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "pybind11/stl_bind.h"
#include "hal_core/python_bindings/python_bindings.h"

#include "hal_relic/plugin_hal_relic.h"

namespace py = pybind11;

namespace hal
{

    // the name in PYBIND11_MODULE/PYBIND11_PLUGIN *MUST* match the filename of the output library (without extension),
    // otherwise you will get "ImportError: dynamic module does not define module export function" when importing the module

    #ifdef PYBIND11_MODULE
    PYBIND11_MODULE(hal_relic, m)
    {
        m.doc() = "hal HalRelicPlugin python bindings";
    #else
    PYBIND11_PLUGIN(hal_relic)
    {
        py::module m("hal_relic", "hal HalRelicPlugin python bindings");
    #endif    // ifdef PYBIND11_MODULE

        py::class_<HalRelicPlugin, RawPtrWrapper<HalRelicPlugin>, BasePluginInterface>(m, "HalRelicPlugin")
            .def_property_readonly("name", &HalRelicPlugin::get_name)
            .def("get_name", &HalRelicPlugin::get_name)
            .def_property_readonly("version", &HalRelicPlugin::get_version)
            .def("get_version", &HalRelicPlugin::get_version)
            ;

    #ifndef PYBIND11_MODULE
        return m.ptr();
    #endif    // PYBIND11_MODULE
    }
}
