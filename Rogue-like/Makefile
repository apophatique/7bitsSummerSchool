all: clean reload lint build exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build:
	cd cmake-build-debug;make

exec:
	./cmake-build-debug/gaziz_sattarov_game2

clean:
	rm -rf cmake-build-debug

reload: mkdir_build
	cd cmake-build-debug;cmake ..


fast_build:
	cd cmake-build-debug;make

run: fast_build exec

lint:
	cd cmake-build-debug;make lint

debug-server: fast_build
	gdbserver :1234 ./cmake-build-debug/ncurses_cmake_demo

reformat:
	clang-format -i -style=file src/*.h
	clang-format -i -style=file src/*.cpp

debug: fast_build debug_server

debug_server:
	gdbserver :1234 ./cmake-build-debug/gaziz_sattarov_game2

osx_dep:
	brew install ncurses

linux_dep:
	sudo apt install libncurses5-dev
