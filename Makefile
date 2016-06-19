CXX = g++ -std=c++11
CXXFLAGS = -g -Wall
OBJECTS = main.o Card.o Command.o Deck.o Player.o ComputerPlayer.o HumanPlayer.o AutomatedPlayerStrategy.o ManualPlayerStrategy.o PlayerStrategy.o Score.o Straights.o
EXEC = a.out

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
main.o : main.cpp Card.h Command.h Deck.h Player.h ComputerPlayer.h HumanPlayer.h AutomatedPlayerStrategy.h ManualPlayerStrategy.h PlayerStrategy.h Score.h Straights.h
	${CXX} ${CXXFLAGS} -c main.cpp
