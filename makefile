hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/BSTNode.o -c ./src/BSTNode.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./lib/ListNode.o -c ./src/ListNode.cpp
	g++ -I ./include/ -o ./bin/Main ./src/main.cpp ./lib/*.o
	
calistir:
	./bin/Main