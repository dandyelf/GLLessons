# Project based on Qt lib on Qt Creator
# On Ubumtu some lib need to install
# sudo apt install build-essential mesa-common-dev cmake clang qtcreator 
# qt6-base-dev qml-qt6
# Some commands must be used
# sudo update-alternatives --install /usr/bin/qmake qmake /usr/bin/qmake6 100
# sudo update-alternatives --config qmake
# 
# 
# 
# 

CC = gcc
CXXFLAGS = -std=c++17 -DTESTS_OBJ_PATH='"$(shell pwd)/src/tests/obj"' -Wall -Werror -Wextra
GCOV = --coverage
UNIT = model_tests.out
OS = $(shell uname -s)
GT_FLAGS = -lgtest_main -lgtest -lm -lstdc++ -pthread -lm -g

#  Project files and directories
BUILD_DIR = build
FOLDERS = src/controller/*.h src/model/*.h src/model/*.cc src/tests/*.cc src/ogl/*.h src/ogl/*.cc

ifeq ($(OS), Darwin)
    LIBS := -lcheck
	APPLICATION = ogl.app
	OPEN = open $(APPLICATION)
else
    LIBS := -lgtest -lstdc++ -lcheck_pic -lrt -lpthread -lsubunit -lm -g
	APPLICATION = ogl
	OPEN = ./$(APPLICATION)
endif

all: install

install:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake CONFIG+=qtquickcompiler ../src/ogl/ogl.pro && make
	make open

clean:
	rm -r ./$(BUILD_DIR)

open:
	cd $(BUILD_DIR) && $(OPEN)

tests:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(MACRO) $(GT_FLAGS) src/model/*.cc src/tests/*.cc -o $(BUILD_DIR)/$(UNIT)
	./$(BUILD_DIR)/$(UNIT)

t:
	./$(BUILD_DIR)/$(UNIT)

valgrind: tests
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(UNIT)

v: install
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(APPLICATION)

clang:
	clang-format -style=file:./materials/linters/.clang-format -n $(FOLDERS)
	clang-format -style=file:./materials/linters/.clang-format -i $(FOLDERS)
