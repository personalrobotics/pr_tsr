# prtsr_py

This folder contains cpp files for generating `pr_tsrpy` using pybind11. All cpp files are generated using [chimera](https://github.com/personalrobotics/chimera).

## Installation

0. The installation guide have been tested on sudo apt installed python 2.7 and python 3.4. Ensure you have `python2.7-dev` or `python3-dev` correspondingly, or:

1. Install [pybind11](https://github.com/pybind/pybind11.git) **from source** following this [instruction](https://pybind11.readthedocs.io/en/master/basics.html#compiling-the-test-cases), version >=2.2.0.


2. Catkin build `pr_tsr` and source catkin.
```
cd ~/workspace-path/pr_tsr
catkin build pr_tsr
source ../devel/setup.bash
```

3. Create a separate build directory `src/pr_tsr/build` and build with python option.
```
mkdir build
cd build
cmake .. -DBUILD_PYTHON=ON -DPR_TSRPY_PYTHON_VERSINO=3.4
```

4. Make install.
```
make
sudo make install
```
Read the output of `sudo make install` and ensure that `pr_tsrpy.so` get installed in desired location.

5. Now you can import `pr_tsrpy`.
```
python3
>>> import pr_tsrpy
>>> import aikidopy
>>> canTSR = pr_tsrpy.getDefaultCanTSR() # Need to have `aikidopy` installed to use this
```

