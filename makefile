hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/bst.o -c ./src/bst.cpp
	g++ -I ./include/ -o ./lib/bstnode.o -c ./src/bstnode.cpp
	g++ -I ./include/ -o ./lib/stack.o -c ./src/stack.cpp


	g++ -I ./include/ -o ./bin/main ./lib/bst.o ./lib/bstnode.o ./lib/stack.o ./src/main.cpp

calistir:
	./bin/main