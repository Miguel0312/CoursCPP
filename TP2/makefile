INT = Ensemble.h
SRC = $(INT:.h=.cpp) tests.cpp
OBJ = $(INT:.h=.o) tests.o
LIBS = -lm
CPPFLAGS = -ansi -pedantic -Wall -std=c++11
LDFLAGS = 
RM = rm
ECHO = echo
EXE = tests.exe

#demo : demo.h

$(EXE) : $(OBJ)
	g++ $(LDFLAGS) -o $(EXE) $(OBJ)

%.o:%.cpp
	g++ -c $(CFLAGS) $<

tests.o : tests.cpp
	g++ $(CFLAGS) -c tests.cpp $(LIBS)

clean :
	$(RM) -f $(EXE) $(OBJ) core
