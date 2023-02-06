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

tree98Test: tree98Test.o tree98.h
	g++ $(CFLAGS) tree98Test.o -lcppunit -o tree98Test

tree98Test: tree98Test.o tree98.h
	g++ $(CFLAGS) -std=c++98 tree98Test.o -lcppunit -o tree98Test

tree03Test: tree03Test.o tree03.h
	g++ $(CFLAGS) -std=c++03 tree03Test.o -lcppunit -o tree03Test

allTests: stackTest treeTest tree98Test tree03Test
	./stackTest
	./treeTest
	./tree98Test
