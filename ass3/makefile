all: EKTApp

EKTApp: EKTApp.o EtoK.o BstNode.o Translator.o 
	g++ -Wall -o EKTApp BstNode.o EKTApp.o Translator.o EtoK.o 

###############################################################
EKTApp.o: EKTApp.cpp Translator.h EtoK.h BstNode.h 
	g++ -Wall -c EKTApp.cpp

Translator.o: Translator.cpp Translator.h BstNode.h EtoK.h
	g++ -Wall -c Translator.cpp

BstNode.o: BstNode.cpp BstNode.h EtoK.h
	g++ -Wall -c BstNode.cpp

EtoK.o: EtoK.cpp EtoK.h BstNode.h
	g++ -Wall -c EtoK.cpp

clean:
	rm -f EKTApp *.o
