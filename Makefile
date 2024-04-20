flag = -pedantic-errors -std=c++11
obj = draw_main.o draw.o keyboard.o object.o player.o 

%.o: %.cpp *.h
	g++ $(flag) -c $<

main: $(obj)
	g++ $(flag) $^ -o $@

clean:
	rm -rf $(obj) main

.PHONY: clean
