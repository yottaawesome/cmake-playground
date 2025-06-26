Ubuntu Ubuntu 24.04.2 LTS (WSL2)
cmake 4.0.3
Ninja 1.11.1
clang 18.1.3

Needed to install libc++-dev and possibly clang-extra-tools

Configure: `cmake -S . -B build/ -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS="-stdlib=libc++" -DCMAKE_EXE_LINKER_FLAGS="-stdlib=libc++ -lc++abi"`

Build : `cmake --build ./build`