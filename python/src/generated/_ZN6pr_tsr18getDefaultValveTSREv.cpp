

#include "../../chimera/chimera.cpp"

#include <pybind11/pybind11.h>


void _ZN6pr_tsr18getDefaultValveTSREv(pybind11::module& m)
{
    auto sm = m;

    auto attr = sm;

    attr.def("getDefaultValveTSR", +[]() -> aikido::constraint::dart::TSR { return pr_tsr::getDefaultValveTSR(); });
}



