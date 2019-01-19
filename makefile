a.out: assignment02.o
	g++ assignment02.o -o a.out

assignment02.o: infix.h stack.h assignment02.cpp 
	g++ -c assignment02.cpp 
