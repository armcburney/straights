CXX = g++ -std=c++11
CXXFLAGS = -g -Wall `pkg-config gtkmm-3.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 --libs`
OBJECTS = main.cpp View/View.o Controller/Controller.o Model/Card.o Global/Command.o Model/Deck.o Model/Player/Player.o Model/Player/ComputerPlayer.o Model/Player/HumanPlayer.o Model/Strategy/AutomatedPlayerStrategy.o Model/Strategy/ManualPlayerStrategy.o Model/Score.o Global/TurnResult.o Global/Context.o Model/Straights.o
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${OBJECTS} -o ${EXEC}
