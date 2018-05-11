#by default, 'make' executes the first target

#this target will compile all the files
all:	hello #this one sees the target 'hello' as a
						#dependency, so it executes that first
	g++ main.cpp function1.cpp function 2.cpp -o hello


  #this target sees 3 other targets as dependencies,
	#so it will execute those before running itself
hello:	main.o function1.o function2.o

	#link object files together into an executable
	g++ main.o function1.o funcion2.o -o hello

#main.o has the dependency main.cpp
main.o: main.cpp:
	#and when you call main.o, it executes the following commands,
	#and it will check first whether it fulfills the requirement
	#or dependency of main.cpp.  Therefore, you should have
	#main.cpp listed first
	g++ -c main.cpp


function1.o:	function1.cpp someHeader.h
	#this will only compile this object file whenever
	#function1.cpp or someHeader.h gave been
	#modified.
	g++ -c function1.cpp

function2.o:	function2.cpp
	g++ -c function2.cpp

clean: #now we're going to remove all of the executables
			 #and all of the object files
	rm -rf *o hello
