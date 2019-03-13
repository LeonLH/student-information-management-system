Enter.out: Enter.o Admin.o Student.o
	g++ -o Enter.out Enter.o Admin.o Student.o 

Enter.o: Enter.cpp
	g++ -g -c Enter.cpp -o Enter.o

Admin.o: Admin.cpp Admin.h 
	g++ -g -c Admin.cpp -o Admin.o

Student.o: Student.cpp Student.h
	g++ -g -c Student.cpp -o Student.o 

clean:
	rm -f Enter.out Enter.o Admin.o Student.o
    	
