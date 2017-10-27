CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = play_game.o RPSGame.o HelperFunctions.o Menu.o Paper.o Rock.o \
Scissors.o Tool.o

SRCS = play_game.cpp RPSGame.cpp HelperFunctions.cpp Menu.cpp Paper.cpp \
Rock.cpp Scissors.cpp Tool.cpp 

HEADERS = RPSGame.h HelperFunctions.hpp Menu.hpp Paper.h Rock.h Scissors.h \
Tool.h

RockPaperScissors: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o RockPaperScissors

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o RockPaperScissors
