flag = -pedantic-errors -std=c++11
main = maintest
objs = draw.o format.o player.o keyboard.o maps.o window.o progress.o Hero.o Girl.o menu.o chat.o

$(main): $(main).o $(objs)
	g++ -o $@ $(flag) $^

%.o: %.cpp %.h
	g++ -c $(flag) $<

clean:
	rm -rf $(objs) $(main) $(main).o

test:
	./$(main)

.PHONY: clean, test
