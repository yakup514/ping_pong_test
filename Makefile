CFLAGS = -Wall -Werror -Wextra
ARCH = $(shell arch)
ifeq "$(ARCH)" "i386"
MYFLAGS = -lm --coverage -lgtest
endif
ifeq "$(ARCH)" "x86_64"
MYFLAGS =-L/usr/lib -lm --coverage -lgtest
endif

all: clean install run


install:
	mkdir build
	cmake CMakeLists.txt -B build
	cmake --build build

run:
	./build/ping_pong cfg.json

clean:
	rm -rf build

style:
	clang-format -i src/*.cpp
	clang-format -i include/game.hpp include/glob_var.hpp include/player.hpp

git:
	git add src/*.cpp include/*.hpp
	git add Makefile
	git add CMakeLists.txt

	
	
