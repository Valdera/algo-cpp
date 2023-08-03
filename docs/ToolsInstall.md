# Required Tools Installation

## Mandatory Tools

Required tools to be installed.

For Ubuntu:

- Install Python3 (>=3.4)
- Install these packages

    ```bash
    sudo apt-get install gcc
    sudo apt-get install g++
    sudo apt-get install gdb
    sudo apt-get install make
    sudo apt-get install cmake
    sudo apt-get install git
    sudo apt-get install doxygen
    ```

For MacOS:

- Install Python3 (>=3.4)
- Install [Homebrew](https://brew.sh/)
- Install these packages

    ```bash
    brew install git
    brew install make
    brew install cmake
    brew install doxygen
    ```

For Windows:

- Install Python3 (>=3.4)
- Install [Chocolatey](https://chocolatey.org/)
- Install these packages

    ```bash
    choco install cmake
    choco install git
    choco install doxygen.install
    choco install python
    choco install make
    choco install llvm
    ```

## Conan Package Manager

Official installation guide is [here](https://docs.conan.io/en/latest/installation.html). The conan database is [here](https://conan.io/center/).

For Ubuntu:

1. Install Python3 (>=3.4)
2. Type ``pip install --user conan==1.59`` into the terminal
3. Append conan to the PATH by: ``source ~/.profile``
4. Type ``conan user`` into the terminal
5. Run the conan command: ``conan``

For MacOS:

1. Install Python3 (>=3.4)
2. Type ``pip install --user conan==1.59`` into the terminal
3. Append conan to the PATH by: ``source ~/.profile``
4. Type ``conan user`` into the terminal
5. Run the conan command: ``conan``

For Windows:

1. Install Python3 (>=3.4)
2. Type ``pip install --user conan==1.59`` into the terminal
3. Type ``conan user`` into the terminal
4. Run the conan command: ``conan``

## VCPKG

Official Link: <https://vcpkg.io/en/index.html>

For Linux and MacOS:

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
```

For Windows:

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
```

## LTO and CCache

- [LTO](https://llvm.org/docs/LinkTimeOptimization.html): Link Time Optimization (LTO) is another name for intermodular optimization when performed during the link stage.

- [Ccache](https://github.com/ccache/ccache): Ccache (or “ccache”) is a compiler cache. It speeds up recompilation by caching previous compilations and detecting when the same compilation is being done again.

For Ubuntu:

```bash
sudo apt-get install ccache
```

For MacOS:

```bash
brew install ccache
```

For Windows:

```bash
choco install ccache
```

## Formatter and Static Analyzer

- [Clang-Format](https://clang.llvm.org/docs/ClangFormat.html): Formatting tool for your C/C++ code
- [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/): Static linting tool for your C/C++ code
- [Cppcheck](https://github.com/danmar/cppcheck): Static linting tool for your C/C++ code

For Ubuntu:

```bash
sudo apt-get install clang-format
sudo apt-get install clang-tidy
sudo apt-get install cppcheck
```

For MacOS:

```bash
brew install clang-format
brew install clang-tidy
brew install cppcheck
```

For Windows:

```bash
choco install llvm
choco install cppcheck
```

## Code Coverage

Tools only for linux and mac.

For Ubuntu:

```bash
sudo apt-get install gcovr
sudo apt-get install lcov
```

For MacOS:

```bash
brew install gcovr
brew install lcov
```
