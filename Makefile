clean:
	rm -f *.o
	rm -f tree treeTest

tree:
	gcc -std=c89 tree.c -o tree

tree.o: tree.c tree.h
	gcc -c -DUNIT_TEST tree.c

treeTest.o: treeTest.cpp tree.h
	g++ -c treeTest.cpp

test: tree.o treeTest.o
	g++ treeTest.o tree.o -lcppunit -o treeTest

treeTest: test
	ls -l /usr/include
	./treeTest