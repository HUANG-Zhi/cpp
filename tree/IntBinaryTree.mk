IntBinaryTree.o:IntBinaryTree.cpp
	g++ -c IntBinaryTree.cpp

TestIntBinaryTree.o:TestIntBinaryTree.cpp
	g++ -c TestIntBinaryTree.cpp

tbt:IntBinaryTree.o TestIntBinaryTree.o
	g++ -o tbt IntBinaryTree.o TestIntBinaryTree.o

clean:
	rm *.o