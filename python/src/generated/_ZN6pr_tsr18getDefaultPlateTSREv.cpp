

#include </home/gilwoo/School_Workspace/herbpy_ws/src/pr_tsr/python/chimera/chimera.cpp>

#include <pybind11/pybind11.h>


void _ZN6pr_tsr18getDefaultPlateTSREv(pybind11::module& m)
{
    auto sm = m;

    auto attr = sm;

    attr.def("getDefaultPlateTSR", +[]() -> aikido::constraint::dart::TSR { return pr_tsr::getDefaultPlateTSR(); });
}




