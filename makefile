CFLAGS=-W -Wall -ansi -pedantic


all: DM

DM: eleve.o ue.o main.o
	g++ -o DM eleve.o ue.o main.o

eleve.o: eleve.cpp ue.h eleve.h
	g++ -o eleve.o -c eleve.cpp $(LDFLAGS)
	
ue.o: ue.cpp ue.h
	g++ -std=c++11 -o ue.o -c ue.cpp $(LDFLAGS)

main.o: main.cpp ue.h eleve.h
	g++ -std=c++11 -o main.o -c main.cpp $(LDFLAGS)
	
clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello
