CPP=g++
LD=g++


CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

LIBSDIR= #rien pour le moment

EXEC=Robothemall

all: $(EXEC)

$(EXEC) : main.o player.o renderer.o map.o foes.o character.o
	$(LD) $(LDFLAGS) player.o map.o main.o renderer.o foes.o character.o -o $(EXEC) $(LIBS)

character.o : character.cpp character.hpp entity.hpp map.hpp
	$(CPP) $(CPPFLAGS) -c character.cpp

player.o : player.cpp player.hpp renderer.hpp character.hpp
	$(CPP) $(CPPFLAGS) -c player.cpp

foes.o : foes.cpp foes.hpp renderer.hpp character.hpp player.hpp
	$(CPP) $(CPPFLAGS) -c foes.cpp

renderer.o : renderer.cpp renderer.hpp map.hpp renderer_interface.hpp
	$(CPP) $(CPPFLAGS) -c renderer.cpp

map.o : map.cpp entity.hpp map.hpp
	$(CPP) $(CPPFLAGS) -c map.cpp

main.o: main.cpp renderer.hpp player.hpp map.hpp foes.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

#règles suplémentaires
doxy :
	doxygen Doxyfile

clean :
	rm -f *.o $(EXEC)
