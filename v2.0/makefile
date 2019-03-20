enter.out: enter.o admin.o student-list.o
	g++ -o enter.out enter.o admin.o student-list.o 

enter.o: enter.cpp
	g++ -g -c enter.cpp -o enter.o

admin.o: admin.cpp admin.h 
	g++ -g -c admin.cpp -o admin.o

student.o: student-list.cpp student-list.h
	g++ -g -c student-list.cpp -o student-list.o 

clean:
	rm -f enter.out enter.o admin.o student-list.o
    	
