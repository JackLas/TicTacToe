FLAGS = -lsfml-system -lsfml-window -lsfml-graphics -IHeader -Wall -std=c++14

MAIN_FILES = main.o Loader.o RAWdata.o Player.o Board.o Cell.o WinnerLine.o Timer.o GameScene.o

main.exe: $(MAIN_FILES)
	g++ $(MAIN_FILES) $(FLAGS) -o main.exe

main.o: Source\main.cpp Source\Loader.cpp Header\Loader.hpp Source\RAWdata.cpp Header\RAWdata.hpp Source\GameScene.cpp Header\GameScene.hpp
	g++ Source\main.cpp $(FLAGS) -c

Loader.o: Source\Loader.cpp Header\Loader.hpp
	g++ Source\Loader.cpp $(FLAGS) -c

RAWdata.o: Source\RAWdata.cpp Header\RAWdata.hpp
	g++ Source\RAWdata.cpp $(FLAGS) -c

Timer.o: Source\Timer.cpp Header\Timer.hpp
	g++ Source\Timer.cpp $(FLAGS) -c

Board.o: Source\Board.cpp Header\Board.hpp Source\Cell.cpp Header\Cell.hpp Source\WinnerLine.cpp Header\WinnerLine.hpp Source\Player.cpp Header\Player.hpp
	g++ Source\Board.cpp $(FLAGS) -c

Cell.o: Source\Cell.cpp Header\Cell.hpp
	g++ Source\Cell.cpp $(FLAGS) -c

Player.o: Source\Player.cpp Header\Player.hpp Source\Board.cpp Header\Board.hpp
	g++ Source\Player.cpp $(FLAGS) -c

WinnerLine.o: Source\WinnerLine.cpp Header\WinnerLine.hpp
	g++ Source\WinnerLine.cpp $(FLAGS) -c

#Scenes
GameScene.o: Source\GameScene.cpp Header\GameScene.hpp Source\Board.cpp Header\Board.hpp Source\Timer.cpp Header\Timer.hpp Source\WinnerLine.cpp Header\WinnerLine.hpp
	g++ Source\GameScene.cpp $(FLAGS) -c


#
#MAIN_FILES = main.o Entity.o Cell.o Board.o Player.o WinnerLine.o Timer.o GameScene.o Loader.o RAWdata.o
#
#main.exe: $(MAIN_FILES)
#	g++ $(MAIN_FILES) $(FLAGS) -o main.exe
#
#main.o: Source\main.cpp Source\GameScene.cpp Header\GameScene.hpp Source\MainMenuScene.cpp Header\MainMenuScene.hpp
#	g++ Source\main.cpp $(FLAGS) -c
#
#Entity.o: Source\Entity.cpp Header\Entity.hpp 
#	g++ Source\Entity.cpp $(FLAGS) -c
#
#Cell.o: Source\Cell.cpp Header\Cell.hpp Source\Entity.cpp Header\Entity.hpp
#	g++ Source\Cell.cpp $(FLAGS) -c
#
#Board.o: Source\Board.cpp Header\Board.hpp Source\Entity.cpp Header\Entity.hpp Source\Cell.cpp Header\Cell.hpp
#	g++ Source\Board.cpp $(FLAGS) -c
#
#Player.o: Source\Player.cpp Header\Player.hpp
#	g++ Source\Player.cpp $(FLAGS) -c
#
#WinnerLine.o: Source\WinnerLine.cpp Header\WinnerLine.hpp Source\Entity.cpp Header\Entity.hpp
#	g++ Source\WinnerLine.cpp $(FLAGS) -c
#
#Timer.o: Source\Timer.cpp Header\Timer.hpp
#	g++ Source\Timer.cpp $(FLAGS) -c
#
#Loader.o: Source\Loader.cpp Header\Loader.hpp
#	g++ Source\Loader.cpp $(FLAGS) -c
#
#RAWdata.o: Source\RAWdata.cpp Header\RAWdata.hpp
#	g++ Source\RAWdata.cpp $(FLAGS) -c
#
#Scenes
#GameScene.o: Source\GameScene.cpp Header\GameScene.hpp Source\Button.cpp Header\Button.hpp Source\Entity.cpp Header\Entity.hpp Source\Timer.cpp Header\Timer.hpp Source\Board.cpp Header\Board.hpp Source\Player.cpp Header\Player.hpp Source\WinnerLine.cpp Header\WinnerLine.hpp
#	g++ Source\GameScene.cpp $(FLAGS) -c