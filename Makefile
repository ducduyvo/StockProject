# src = $(shell find -type f -name '*.cpp')
# obj = $(src:.cpp=.o)
program.o: $(obj)
			g++ -Wall -o stockproject -std=gnu++11 Item.cpp ins.cpp stock.cpp Source.cpp
.PHONY: clean
clean:
		rm -f $(obj) stockproject