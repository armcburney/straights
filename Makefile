CXX = g++ -std=c++11
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-3.0 gmodule-2.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 gmodule-2.0 --libs`
OBJECTS = main.cpp Controller/Controller.o Model/Card.o Global/Command.o Model/Deck.o Model/Player/Player.o Model/Player/ComputerPlayer.o Model/Player/HumanPlayer.o Model/Strategy/AutomatedPlayerStrategy.o Model/Strategy/ManualPlayerStrategy.o Model/Score.o Global/TurnResult.o Global/Context.o Global/Subject.o Model/Straights.o View/GameView.o View/InitializationView.o View/TextView.o
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${LDFLAGS} -o ${EXEC}

clean:
	rm $(EXEC) $(OBJS)
