FLAGS = -pedantic-errors -std=c++11

keyboard.o: keyboard.cpp keyboard.h
	g++ $(FLAGS) $^ -o $@

player.o: player.cpp player.h
  g++ $(FLAGS) $^ -o $@

object.o: object.cpp object.o
  g++ $(FLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f *.o 

.PHONY: clean	
