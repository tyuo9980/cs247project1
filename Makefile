CXX = g++ # variables and initialization
CXXFLAGS = -g -Wall -MMD -std=c++0x  `pkg-config gtkmm-2.4 --cflags` # builds dependency lists in .d ﬁles
OBJECTS = main.o ./controller/Controller.o ./view/View.o ./model/Card.o ./model/Player.o ./model/ComputerPlayer.o ./model/HumanPlayer.o ./model/Table.o ./model/Deck.o ./model/Model.o ./model/Subject.o ./view/Gui.o 
DEPENDS = ${OBJECTS:.o=.d} # substitute ".o" with ".d"
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean : # separate target; cleans directory
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}