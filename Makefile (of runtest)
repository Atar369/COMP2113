flag = -pedantic-errors -std=c++11
main = runtest

$(main): runtest.o player.o keyboard.o draw.o format.o
	g++ -o $@ $(flag) $^

format.o: format.cpp format.h
	g++ $(flag) -c $< -o $@

keyboard.o: keyboard.cpp keyboard.h
	g++ $(flag) -c $< -o $@

player.o: player.cpp player.h keyboard.h constant.h
	g++ $(flag) -c $< -o $@

draw.o: draw.cpp draw.h player.h format.h
	g++ $(flag) -c $< -o $@

runtest.o: runtest.cpp draw.h
	g++ $(flag) -c $< -o $@

clean:
	rm -rf *.o $(main)

test:
	./runtest

.PHONY: clean, test
