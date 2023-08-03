ifeq '$(findstring ;,$(PATH))' ';'
  CONAN_FLAGS = -s compiler='Visual Studio' -s compiler.version=16 -s cppstd=17 --build missing
else
  CONAN_FLAGS = -s compiler.cppstd=20 --build missing
endif

all: prepare

install_min:
	sudo apt-get install gcc g++ cmake make doxygen

install_tests: install_min
	sudo apt-get install gcovr lcov

install: install_min install_tests
	sudo apt-get install git llvm pkg-config curl zip unzip tar python3-dev clang-format clang-tidy cppcheck iwyu

install_pip:
	pip install jinja2 Pygments cmake-format pre-commit

install_doc: install_min
	sudo apt-get install doxygen
	pip install jinja2 Pygments

install_conan:
	pip install conan==1.59.0 --user
	conan user

dep-graph:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graph_deps.png

prepare:
	rm -rf build
	mkdir build

setup_conan:
	cd build && conan install .. $(CONAN_FLAGS)
