INT = $(wildcard *.h)
SRC = $(INT:.h=.cpp) main.cpp
OBJ = $(INT:.h=.o) main.o
LIBS = -lm
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -g #-DMAP
LDFLAGS = 
RM = rm
ECHO = echo
EXE = analog

$(EXE) : $(OBJ)
	g++ $(LDFLAGS) -o $(EXE) $(OBJ)

Log.o: Log.cpp Log.h
Statistic.o: Statistic.cpp Statistic.h Log.h
main.o : main.cpp Statistic.h

$(OBJ) :
	g++ -c $(CPPFLAGS) $<

clean :
	$(RM) -f $(EXE) $(OBJ) core
