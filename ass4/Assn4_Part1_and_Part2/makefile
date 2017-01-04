all: EKTAppV2

EKTAppV2: EKTAppV2.o EtoK.o TranslatorV2.o Hash.o
	g++ -Wall -o EKTAppV2 EKTAppV2.o  EtoK.o TranslatorV2.o Hash.o

###############################################################
EKTAppV2.o: EKTAppV2.cpp EtoK.h TranslatorV2.h Hash.h
	g++ -Wall -c EKTAppV2.cpp

Hash.o: Hash.cpp Hash.h EtoK.h
	g++ -Wall -c Hash.cpp

TranslatorV2.o: TranslatorV2.cpp TranslatorV2.h EtoK.h
	g++ -Wall -c TranslatorV2.cpp

EtoK.o: EtoK.cpp EtoK.h 
	g++ -Wall -c EtoK.cpp

clean:
	rm -f EKTAppV2 *.o
