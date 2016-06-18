CXX = g++ -std=c++11
CXXFLAGS = -g -Wall
OBJECTS = Card.o Command.o Deck.o HumanPlayer.o ManualStrategy.o PlayerStrategy.o Score.o Straights.o
EXEC = a.out

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
main.o : main.cpp Card.h Command.h Deck.h HumanPlayer.h ManualStrategy.h PlayerStrategy.h Score.h Straights.h
	${CXX} ${CXXFLAGS} -c GraphTestHarness.cpp
