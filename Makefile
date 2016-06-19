CXX = g++ -std=c++11
CXXFLAGS = -g -Wall
OBJECTS = main.cpp View/View.o Controller/Controller.o Model/Card.o Global/Command.o Model/Deck.o Model/Player/Player.o Model/Player/ComputerPlayer.o Model/Player/HumanPlayer.o Model/Strategy/AutomatedPlayerStrategy.o Model/Strategy/ManualPlayerStrategy.o Model/Score.o Global/TurnResult.o Global/Context.o Model/Straights.o
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
