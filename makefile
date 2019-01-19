a.out: assignment02.o
	g++ assignment02.o -o a.out

assignment02.o: stack.h infix.h assignment02.cpp 
	g++ -c assignment02.cpp 
