CPP=g++
LD=g++


CPPFLAGS= -g -Wall -Wextra -std=c++14
LDFLAGS=-g -Wall -Wextra -std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

LIBSDIR= #rien pour le moment

EXEC=Robothemall

all: $(EXEC)

$(EXEC) : main.o player.o renderer.o map.o foes.o character.o bullet.o game.o
	$(LD) $(LDFLAGS) player.o game.o map.o main.o renderer.o foes.o character.o bullet.o -o $(EXEC) $(LIBS)



bullet.o : bullet.cpp bullet.hpp entity.hpp map.hpp renderer.hpp
	$(CPP) $(CPPFLAGS) -c bullet.cpp

character.o : character.cpp character.hpp entity.hpp map.hpp
	$(CPP) $(CPPFLAGS) -c character.cpp

player.o : player.cpp player.hpp renderer.hpp character.hpp
	$(CPP) $(CPPFLAGS) -c player.cpp

foes.o : foes.cpp foes.hpp renderer.hpp character.hpp player.hpp
	$(CPP) $(CPPFLAGS) -c foes.cpp

renderer.o : renderer.cpp renderer.hpp map.hpp renderer_interface.hpp
	$(CPP) $(CPPFLAGS) -c renderer.cpp

map.o : map.cpp entity.hpp map.hpp bullet.hpp
	$(CPP) $(CPPFLAGS) -c map.cpp

game.o : game.cpp renderer.hpp player.hpp map.hpp foes.hpp
	$(CPP) $(CPPFLAGS) -c game.cpp

main.o: main.cpp renderer.hpp player.hpp map.hpp foes.hpp game.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

#règles suplémentaires
doxy :
	doxygen Doxyfile

clean :
	rm -f *.o $(EXEC)

check :
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${EXEC}
