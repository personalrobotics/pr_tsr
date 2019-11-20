


#include <pybind11/pybind11.h>


void _ZN6pr_tsr18getDefaultBlockTSREv(pybind11::module& m);
void _ZN6pr_tsr21getDefaultBlockBinTSREv(pybind11::module& m);
void _ZN6pr_tsr16getDefaultCanTSREv(pybind11::module& m);
void _ZN6pr_tsr21getDefaultFoodItemTSREv(pybind11::module& m);
void _ZN6pr_tsr17getDefaultFuzeTSREv(pybind11::module& m);
void _ZN6pr_tsr18getDefaultGlassTSREv(pybind11::module& m);
void _ZN6pr_tsr18getDefaultPlateTSREv(pybind11::module& m);
void _ZN6pr_tsr18getDefaultTableTSREv(pybind11::module& m);
void _ZN6pr_tsr18getDefaultValveTSREv(pybind11::module& m);

PYBIND11_MODULE(pr_tsrpy, m)
{
    _ZN6pr_tsr18getDefaultBlockTSREv(m);
    _ZN6pr_tsr21getDefaultBlockBinTSREv(m);
    _ZN6pr_tsr16getDefaultCanTSREv(m);
    _ZN6pr_tsr21getDefaultFoodItemTSREv(m);
    _ZN6pr_tsr17getDefaultFuzeTSREv(m);
    _ZN6pr_tsr18getDefaultGlassTSREv(m);
    _ZN6pr_tsr18getDefaultPlateTSREv(m);
    _ZN6pr_tsr18getDefaultTableTSREv(m);
    _ZN6pr_tsr18getDefaultValveTSREv(m);

}


