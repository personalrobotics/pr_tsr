

#include "../../chimera/chimera.hpp"

#include <pybind11/pybind11.h>


void _ZN6pr_tsr18getDefaultBlockTSREv(pybind11::module& m)
{
    auto sm = m;

    auto attr = sm;

    attr.def("getDefaultBlockTSR", +[]() -> aikido::constraint::dart::TSR { return pr_tsr::getDefaultBlockTSR(); });
}




