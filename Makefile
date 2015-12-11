all: VocabTeacher

VocabTeacher: category.o main.o
			g++ -o VocabTeacher category.o main.o

category.o: category.cpp category.hpp
			g++ -o category.o -c category.cpp -Wall

main.o: main.cpp category.hpp
		g++ -o main.o -c main.cpp -Wall

clean:
		rm -rf *.o