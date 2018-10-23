example: example.cpp unalias.hpp
	g++ --std=c++17 example.cpp -o example

.PHONY: clean
clean:
	rm -f example
