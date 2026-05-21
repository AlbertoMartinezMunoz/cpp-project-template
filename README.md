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
