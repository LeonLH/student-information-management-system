enter.out: enter.o admin.o teacher.o student.o person.o
	g++ -o enter.out enter.o admin.o teacher.o student.o person.o

enter.o: enter.cpp
	g++ -g -c enter.cpp -o enter.o

admin.o: admin.cpp admin.h 
	g++ -g -c admin.cpp -o admin.o

teacher.o: teacher.cpp teacher.h
	g++ -g -c teacher.cpp -o teacher.o 

student.o: student.cpp student.h
	g++ -g -c student.cpp -o student.o

person.o: person.cpp person.h
	g++ -g -c person.cpp -o person.o

clean:
	rm -f enter.out enter.o admin.o teacher.o manager.o student.o person.o
    	
