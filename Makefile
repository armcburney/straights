CXX = g++ -std=c++11
CXXFLAGS = -g -Wall
OBJECTS = main.o Card.o Command.o Deck.o Player.o TurnResult.o  ComputerPlayer.o HumanPlayer.o AutomatedPlayerStrategy.o ManualPlayerStrategy.o PlayerStrategy.o Score.o Straights.o
EXEC = a.out

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
main.o : main.cpp View/View.h Controller/Controller.h Model/Card.h Global/Command.h Model/Deck.h Model/Player/Player.h Model/Player/ComputerPlayer.h Model/Player/HumanPlayer.h Model/Strategy/AutomatedPlayerStrategy.h Model/Strategy/ManualPlayerStrategy.h Model/Strategy/PlayerStrategy.h Model/Score.h Global/TurnResult.h Global/Context.h Model/Straights.h
	${CXX} ${CXXFLAGS} -c main.cpp
