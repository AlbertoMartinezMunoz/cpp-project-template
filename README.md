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

### pre-commit

The `pre-commit` tool runs hooks on every commit to automatically point out issues in code such as missing semicolons, trailing whitespace, and debug statements. To install pre-commit:

```console
pip install pre-commit
```

To configure it:

1. Create a file named .pre-commit-config.yaml you can generate a very basic configuration using

```console
pre-commit sample-config > .pre-commit-config.yaml
```

2. Run the hooks against all of the files

```console
pre-commit run --all-files
```

3. Install the git hook scripts

```console
pre-commit install
```

The whole documentation in on the website [pre-commit](https://pre-commit.com/)

### Python

Install Python3

```shell
sudo apt update
sudo apt install python3
```

Install pip3

```shell
sudo apt-get install python3-pip
python3 -m pip install --user --upgrade pip
```

#### Python Virtual Environment

Install venv

```shell
sudo apt-get install python3-venv
```

The scripts in this folder are designed to be set up using a Python virtual environment (`venv`). The first time you want to set up the application on Linux, execute the steps below on a shell:

```sh
# Set up a virtual environment
python3 -m venv .venv

# Activate it
. .venv/bin/activate

# Install necessary packages and upgrade
pip install -r requirements.txt --upgrade
```

Please do _not_ use `sudo` within a virtual environment; it will not work as intended. Instead, set up your system correctly so that you do not need root access to run the script.

On Windows Command Prompt, the commands are slightly different:

```bat
REM Set up a virtual environment
python3 -m venv .venv

REM Activate it
CALL .venv\Scripts\activate.bat

REM Install necessary packages and upgrade
pip install -r requirements.txt --upgrade
```

For more information, e.g., using `venv` with Windows PowerShell, see the [official Python venv documentation](https://docs.python.org/3/library/venv.html).

To use the application again at a later time, you only need to perform the activation step.

#### Create/Update Requirements File
You can use the following code to generate a requirements.txt file:

```sh
pip freeze > requirements.txt
```

Instead of adding all the dependencies to the `requirements.txt` file, we can append only the packages we need to install without deppendencies:

```sh
pip freeze | grep "PACKAGE_NAME==" >> requirements.txt
```

To start intalling libraries again for fresh, you can update the dependencies list and then uninstall all the dependencies:

```sh
pip freeze > requirements.txt
pip uninstall -y -r requirements.txt
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

### Acceptance Testing

Acceptance/Integration tests will be carried on using **pytest**

To run the tests:

```console
pytest --html=./buildatest/report.html --self-contained-html ./atest
```

More information in [pytest: helps you write better programs](https://docs.pytest.org/en/stable/)

### Build UML Diagrams

The C4 diagrams are made using [PlantUML](https://plantuml.com/). First, you have to install the `plantuml` package:

```console
sudo apt-get update
sudo apt-get install plantuml
```

Then, to build the diagrams, you only have to run the `plantuml` command:

```console
plantuml -tpng <path-to-the-files>
```
