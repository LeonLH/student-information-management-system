enter.out: enter.o admin.o student-list.o manager-list.o
	g++ -o enter.out enter.o admin.o student-list.o manager-list.o

enter.o: enter.cpp
	g++ -g -c enter.cpp -o enter.o

admin.o: admin.cpp admin.h 
	g++ -g -c admin.cpp -o admin.o

student-list.o: student-list.cpp student-list.h
	g++ -g -c student-list.cpp -o student-list.o 

manager-list.o: manager-list.cpp manager-list.h
	g++ -g -c manager-list.cpp -o manager-list.o

clean:
	rm -f enter.out enter.o admin.o student-list.o
    	
