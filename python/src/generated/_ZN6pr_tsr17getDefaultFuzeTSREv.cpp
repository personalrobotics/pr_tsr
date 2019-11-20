

#include <chimera/chimera.hpp>

#include <pybind11/pybind11.h>


void _ZN6pr_tsr17getDefaultFuzeTSREv(pybind11::module& m)
{
    auto sm = m;

    auto attr = sm;

    attr.def("getDefaultFuzeTSR", +[]() -> aikido::constraint::dart::TSR { return pr_tsr::getDefaultFuzeTSR(); });
}




