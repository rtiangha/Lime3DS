#!/bin/sh -ex

if [ "$TARGET" = "msvc" ]; then
    export EXTRA_CMAKE_FLAGS=(-DCMAKE_CXX_FLAGS="/O2" -DCMAKE_C_FLAGS="/O2")
else
    export EXTRA_CMAKE_FLAGS=(-DCMAKE_CXX_FLAGS="-O2" -DCMAKE_C_FLAGS="-O2")
fi

mkdir build && cd build
cmake .. -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER_LAUNCHER=ccache \
    -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
    -DENABLE_QT_TRANSLATION=ON \
    -DCITRA_ENABLE_COMPATIBILITY_REPORTING=ON \
    -DENABLE_COMPATIBILITY_LIST_DOWNLOAD=ON \
    -DUSE_DISCORD_PRESENCE=ON
ninja
ninja bundle
strip -s bundle/*.exe

ccache -s -v

ctest -VV -C Release || echo "::error ::Test error occurred on Windows build"
