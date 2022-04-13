CPP=g++
LD=g++


CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

LIBSDIR= #rien pour le moment

EXEC=Robothemall

all: $(EXEC)

$(EXEC) : main.o player.o renderer.o
	$(LD) $(LDFLAGS) main.o player.o renderer.o -o $(EXEC) $(LIBS)

player.o : player.cpp player.hpp renderer.hpp character.hpp
	$(CPP) $(CPPFLAGS) -c player.cpp

renderer.o : renderer.cpp renderer.hpp
	$(CPP) $(CPPFLAGS) -c renderer.cpp

main.o: main.cpp renderer.hpp player.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

#règles suplémentaires
doxy :
	doxygen Doxyfile

clean :
	rm -f *.o $(EXEC)
