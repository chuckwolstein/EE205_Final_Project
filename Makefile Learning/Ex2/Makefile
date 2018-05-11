#can declare variables inside Makefiles too
CC=g++ #this just specified which type of compiler we're using

CFLAGs =-c -Wall #this specified which types of compiler options
								 #we want to use
								 #-c is for compilation
								 #-Wall is for giving the warning

all:				 hello

hello:		main.o function1.o function2.o
	#now let's use our variables to serve as shortcuts
	$(CC) main.o function1.o function2.o -o hello

main.o:	main.cpp
		$(CC) $(CFLAGS) main.cpp

#this next targer will only compile this object file 
#function1.cpp or someHeader.h gave been
#modified.
function1.o:	function1.cpp someHeader.h

		$(CC) $(CFLAGS) function1.cpp

function2.o:	function2.cpp
		$(CC) $(CFLAGS) function2.cpp

clean:
		rm -rf *o hello
