INT = $(wildcard *.h)
SRC = $(INT:.h=.cpp) main.cpp
OBJ = $(INT:.h=.o) main.o
LIBS = -lm
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -g #-D MAP
LDFLAGS = 
RM = rm
ECHO = echo
EXE = trajet

$(EXE) : $(OBJ)
	g++ $(LDFLAGS) -o $(EXE) $(OBJ)

%.o:%.cpp
	g++ -c $(CPPFLAGS) $<

clean :
	$(RM) -f $(EXE) $(OBJ) core
