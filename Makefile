all: myiterator.o 

myiterator.o: myiterator.cpp
	@echo Building target $@
	g++ --std=c++14 -o $@ myiterator.cpp

run: myiterator.o
	@echo Running target $@
	./myiterator.o

clean:
	@echo Running target $@
	rm -f *.o
