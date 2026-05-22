# cpp-project-template

C++ GitHub template repository using CMake with GoogleTest, GoogleMock, and FFF for unit testing. Includes clang-format, pre-commit hooks, Conventional Commit validation, and CI pipelines for automated testing and code quality checks. Designed to simplify the creation of clean, maintainable, and production-ready C++ projects.

## Setup

### Google Test

Google test can be added to your git repo as a git submodule.

```console
$ git submodule add https://github.com/google/googletest.git ./vendor/gtest
```

Also if we are using C++20 in our project, we have to ensure that C++20 is used adding the following line in the root CMakeList file

```cmake
set(CMAKE_CXX_STANDARD 20)
```

### Fake Function Framework (FFF)

Fake Function Framework can be added to your git repo as a git submodule.

```console
$ git submodule add https://github.com/meekrosoft/fff.git ./vendor/fff
```

and then adding it to the CMakeList

```cmake
add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/fff")
```

### Valgrind

#### Installation

```console
sudo apt-get update
sudo apt-get -y install valgrind
```

### clang-format

The `clang-format` tool will be used to format the c++ files. To install clang-format:

```console
sudo apt install clang-format
```

There some default styles when formatting, but you can modify them using the `.clang-format` configuration file and the option `-style=file`

It will be used to format the c++ files before commiting them to the repo. To manually run it:

```console
find ./src -iname '*.h' -o -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i -style=file
```

## Build

### Release

To build the release, first we launch CMake and then make.

```console
cmake . -H. -Bbuild
cd build
make -j3
```

All in one line:

```console
cmake . -H. -Bbuild; cd build; make -j3; cd ..
```

### Unitary Testing

The unit tests will be launched using **ctest**

To build the unitary tests, first we launch CMake with the UTEST custom option and then make.

```console
cmake . -DUTEST=ON -H. -Bbuildtest
cd buildtest
make -j3
```

To launch **all** the tests:

```console
ctest -VV;
```

To launch only a testsuite:

```console
ctest -R "testsuite_name" -VV
```

To use **valgrind** for checking memory leaks:

```console
ctest -T memcheck -VV
```

All in one line:

```console
cmake . -DUTEST=ON -H. -Bbuildtest; cd buildtest; make -j3 && ctest -T memcheck -VV; cd ..
```
