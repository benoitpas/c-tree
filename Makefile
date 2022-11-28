tree:
	gcc -std=c89 tree.c -o tree

test:
	# need to add tree.c at some point, this is just to test gitlab actions
	g++ treeTest.cpp -lcppunit -o treeTest

runTest: test
	./treeTest