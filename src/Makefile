CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
SOURCES = $(wildcard SmartCalcV1/back/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))


all: install

install: build
	cd CalcApp; make

build: s21_smart_calc.a
	rm -rf CalcApp
	mkdir CalcApp
	cd CalcApp; cmake ../SmartCalcV1

uninstall: clean
	rm -rf SmartCalcV1/CMakeLists.txt.user
	rm -rf SmartCalcV1/build
	rm -rf CalcApp

execute:
	cd CalcApp/SmartCalcV1.app/Contents/MacOS; ./SmartCalcV1
	

s21_smart_calc.a: clean $(OBJECTS)
	ar -rcs s21_smart_calc.a $(OBJECTS)
	ranlib s21_smart_calc.a
	rm -f SmartCalcV1/back/*.o


clean:
	rm -rf SmartCalcV1/back/*.o *.a *.so *.gcda *.gcno *.gch *.pdf *.tar rep.info *.html *.css test.info test.dSYM
