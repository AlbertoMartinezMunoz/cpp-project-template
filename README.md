# cpp-project-template

C++ GitHub template repository using CMake with GoogleTest, GoogleMock, and FFF for unit testing. Includes clang-format, pre-commit hooks, Conventional Commit validation, and CI pipelines for automated testing and code quality checks. Designed to simplify the creation of clean, maintainable, and production-ready C++ projects.

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
