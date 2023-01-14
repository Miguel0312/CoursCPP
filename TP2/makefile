INT = $(wildcard *.h)
SRC = $(INT:.h=.cpp) main.cpp
OBJ = $(INT:.h=.o) main.o
LIBS = -lm
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -g #-DMAP
LDFLAGS = 
RM = rm
ECHO = echo
EXE = trajet

$(EXE) : $(OBJ)
	g++ $(LDFLAGS) -o $(EXE) $(OBJ)

Catalogue.o : Catalogue.cpp Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h ListeTrajet.h Node.h
ListeTrajet.o : ListeTrajet.cpp ListeTrajet.h Trajet.h Node.h
Node.o : Node.cpp Node.h Trajet.h
Trajet.o : Trajet.cpp Trajet.h
TrajetCompose.o : TrajetCompose.cpp TrajetCompose.h TrajetSimple.h ListeTrajet.h Node.h
TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h Trajet.h
main.o : main.cpp Catalogue.h TrajetSimple.h TrajetCompose.h

$(OBJ) :
	echo $(OBJ)
	g++ -c $(CPPFLAGS) $<

clean :
	$(RM) -f $(EXE) $(OBJ) core
