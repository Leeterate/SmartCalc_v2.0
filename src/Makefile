.PHONY: all clean tests gcov_report
SHELL := /bin/bash
OPEN= xdg-open report/index.html
PROJECT_NAME = smartcalc
INSTALL_PATH=./Build
CC = g++
EXTRAWARN_FLAGS = -Wpedantic -Wshadow -Wuninitialized 
WARN_FLAGS= -Wall -Werror -Wextra
CFLAGS = -std=c++17 -lstdc++ $(WARN_FLAGS)
DEBUG_FLAG = -g
GCOVFLAG = --coverage
LDFLAGS = -lgtest
TEST_SRCS = tests.cc
SRCS = model.cc controller.cc mainwindow.cc model.h controller.h mainwindow.h
VERSION = v2.0
FILENAME = $(PROJECT_NAME)_$(VERSION)
READMENAME = SmartCalc_v2_readme
CLIBS=  -lm -lsubunit -lpthread -lrt  -lgtest -g #-D_GNU_SOURCE
OS := $(shell uname)

ifeq ($(OS), Linux)
LDFLAGS += -lgtest_main -lpthread
LCOV=$(shell which lcov)
GENHTML=$(shell which genhtml)
endif

ifeq ($(OS),Darwin)
BREW := ${HOME}/homebrew/brew/bin/brew
ifeq ($(shell test -e $(BREW) && echo -n yes),yes)
LCOV=$(shell which lcov)
GENHTML=$(shell which genhtml)
else
LCOV=/opt/goinfre/$(USER)/brew/bin/lcov
GENHTML=/opt/goinfre/$(USER)/brew/bin/genhtml
endif
endif

all: install tests
	
tests: clean
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LDFLAGS) model.cc -o tests.out
	./tests.out

install: clean
	qmake $(PROJECT_NAME).pro -o Qmakefile
	make -f Qmakefile install INSTALL_ROOT=$(INSTALL_PATH)
	rm -rf $(FILENAME).app
	make  dvi
	open $(INSTALL_PATH)

uninstall:
	rm -rf Build

dist:
	tar -czf smartcalc_v2.0.tar ./*
dvi:
	makeinfo --html --no-split -o README.html smartcalc.texi --force
	mkdir -p $(INSTALL_PATH)/$(READMENAME)/
	cp README.html $(INSTALL_PATH)/$(READMENAME)/
	rm README.html

clean:
	qmake $(PROJECT_NAME).pro -o Qmakefile
	make -f Qmakefile clean
	rm -rf *.o *.a *.gcno test ./report ./*.dSYM test.info *.out *.gcda gcov_report *.info .clang-format *.user .qmake.stash
	rm -R -f ../.DS_Store .DS_Store *.dSYM
	rm -rf .DS_Store DS_Store *.tmp

gcov_report: tests
ifeq ($(OS),Darwin)
	@$(CC) -std=c++17 --coverage model.cc tests.cc -o test_report -lm -lpthread -lgtest -g
	./test_report
	lcov --ignore-errors inconsistent -t "tests" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open report/index.html
endif
ifeq ($(OS), Linux)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LDFLAGS) model.cc $(GCOVFLAG) -o tests.out
	./tests.out
	ls tests.out
	$(LCOV) -t tests.out -o tests.info -c -d . --no-external
	$(GENHTML) tests.info -o report
	open report/index.html
endif

style_check: clang-format cppcheck

cppcheck:
	cppcheck --enable=all --language=c++ --std=c++17 --suppress=unusedFunction --suppress=missingInclude --suppress=unknownMacro --suppress=unmatchedSuppression $(SRCS)

clang-format:
	clang-format -i --style=Google *.cc *.h
	clang-format -n --style=Google *.cc *.h

leaks: tests
	CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./tests.out
