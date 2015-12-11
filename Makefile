all: VocabTeacher

VocabTeacher: category.o main.o
			g++ -o VocabTeacher linuxObj/category.o linuxObj/main.o

category.o: category.cpp category.hpp
			g++ -o linuxObj/category.o -c category.cpp -Wall

main.o: main.cpp category.hpp
		g++ -o linuxObj/main.o -c main.cpp -Wall

clean:
		rm -rf *.o