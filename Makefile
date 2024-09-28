CC = g++
CXXFLAGS = -g -Wall -Wextra -o3 -pedantic

teste_map:	testes/map.o
	$(CC) -o $@ $^

bst: testes/BST.o
	$(CC) -o $@ $^

clean : 
	rm -rf testes/*.o teste_map bst