enter.out: enter.o admin.o teacher.o manager-list.o student.o
	g++ -o enter.out enter.o admin.o teacher.o manager-list.o student.o

enter.o: enter.cpp
	g++ -g -c enter.cpp -o enter.o

admin.o: admin.cpp admin.h 
	g++ -g -c admin.cpp -o admin.o

teacher.o: teacher.cpp teacher.h
	g++ -g -c teacher.cpp -o teacher.o 

manager-list.o: manager-list.cpp manager-list.h
	g++ -g -c manager-list.cpp -o manager-list.o

student.o: student.cpp student.h
	g++ -g -c student.cpp -o student.o

clean:
	rm -f enter.out enter.o admin.o teacher.o
    	
