CFLAGS = -g

clean:
	rm -f *.o
	rm -f treeMain treeTest

treeMain: main.o tree.o stack.o
	g++ $(CFLAGS) main.o tree.o stack.o -o treeMain

stackTest: stackTest.o stack.o
	g++ $(CFLAGS) stackTest.o stack.o -lcppunit -o stackTest

treeTest.o: treeTest.cpp tree.h

treeTest: tree.o treeTest.o stack.o
	g++ $(CFLAGS) treeTest.o tree.o stack.o -lcppunit -o treeTest

tree98Test: tree98Test.o
	g++ $(CFLAGS) tree98Test.o -lcppunit -o tree98Test

allTests: stackTest treeTest tree98Test
	./stackTest
	./treeTest
	./tree98Test
