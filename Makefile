CC = gcc
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV = --coverage
UNIT = model_tests.out
OS = $(shell uname -s)
GT_FLAGS = -lgtest_main -lgtest -lm -lstdc++ -pthread -lm -g
MACRO := -DTESTS_OBJ_PATH='"$(shell pwd)/src/tests/obj"'

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

all: clean install

install: clean
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake CONFIG+=qtquickcompiler ../src/ogl/ogl.pro && make
	make open

clean:
	rm -rf *.o *.a *.gc* *.info build report *dSYM $(UNIT) *tgz gcov_test $(BUILD_DIR)/*

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

clang:
	clang-format -style=file:./materials/linters/.clang-format -n ./*.cc $(FOLDERS)
	clang-format -style=file:./materials/linters/.clang-format -i ./*.cc $(FOLDERS)
