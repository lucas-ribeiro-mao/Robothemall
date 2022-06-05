CPP=g++
LD=g++

CPPFLAGS= -g -Wall -Wextra -std=c++17
LDFLAGS=-g -Wall -Wextra -std=c++17
LIBS=-lsfml-graphics -lsfml-window -lsfml-system #-lsfml-network -lsfml-audio

LIBSDIR= #rien pour le moment

EXEC=Robothemall
TEST=tests_catch

all: $(EXEC) $(TEST)

# GAME
robot: $(EXEC)

$(EXEC) : main.o player.o renderer.o map.o foes.o character.o bullet.o game.o entity.o
	$(LD) $(LDFLAGS) $^ -o $@ $(LIBS)

bullet.o : bullet.cpp bullet.hpp entity.hpp map.hpp renderer.hpp
	$(CPP) $(CPPFLAGS) -c $<

character.o : character.cpp character.hpp entity.hpp map.hpp
	$(CPP) $(CPPFLAGS) -c $<

entity.o : entity.cpp entity.hpp
	$(CPP) $(CPPFLAGS) -c $<

player.o : player.cpp player.hpp renderer.hpp character.hpp
	$(CPP) $(CPPFLAGS) -c $<

foes.o : foes.cpp foes.hpp renderer.hpp character.hpp player.hpp
	$(CPP) $(CPPFLAGS) -c $<

renderer.o : renderer.cpp renderer.hpp map.hpp renderer_interface.hpp
	$(CPP) $(CPPFLAGS) -c $<

map.o : map.cpp entity.hpp map.hpp bullet.hpp
	$(CPP) $(CPPFLAGS) -c $<

game.o : game.cpp renderer.hpp player.hpp map.hpp foes.hpp
	$(CPP) $(CPPFLAGS) -c $<

main.o: main.cpp renderer.hpp player.hpp map.hpp foes.hpp game.hpp
	$(CPP) $(CPPFLAGS) -c $<

# TESTS
test: $(TEST)

$(TEST): tests_catch_bullet.o tests_catch_player.o tests_catch_foes.o tests_catch_map.o player.o renderer.o map.o foes.o character.o bullet.o game.o entity.o
	$(LD) $(LDFLAGS) $^ -o $@ $(LIBS)

tests_catch_bullet.o : tests_catch_bullet.cpp bullet.hpp entity.hpp map.hpp renderer.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c $<

tests_catch_player.o : tests_catch_player.cpp player.hpp renderer.hpp character.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c $<

tests_catch_foes.o : tests_catch_foes.cpp foes.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c $<

tests_catch_map.o : tests_catch_map.cpp map.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c $<


#règles suplémentaires
clean :
	rm -f *.o $(EXEC) $(TEST)

check :
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${EXEC}
