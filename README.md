# OpenGL Template

Copy/paste this repository to quickly get up and running with OpenGL. CMake is used for building and vcpkg for package management.

### Windows

This project builds out of the box in Visual Studio 2022 with an integrated
installation of vcpkg.

### Linux

##### Installing vcpkg

```shell
mkdir -p ~/tools && cd ~/tools
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh -disableMetrics
```

##### Configure vcpkg in CLion

1. Go to `File -> Settings -> Build, Execution, Deployment -> CMake`.
2. Find `CMake Options`.
3. Insert `-DCMAKE_TOOLCHAIN_FILE=~/tools/vcpkg/scripts/buildsystems/vcpkg.cmake`.
