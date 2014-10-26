##
##
## simple makefile
##
##

CXX= g++
RM= /bin/rm -f
PROGNAME= main
CXXFLAGS =  -Wall -g -I.  
CPP_SRC= Coordinates.cpp Dot.cpp Spiral.cpp main.cpp
OBJS = $(CPP_SRC:.cpp=.o)

all: $(PROGNAME)

$(PROGNAME): $(AUX_TARG) $(OBJS)
	$(CXX) $(OBJS) -o $(PROGNAME)

.SUFFIXES:      .cpp .hh .o 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)
clean:
	$(RM) $(OBJS) $(PROGNAME) core
