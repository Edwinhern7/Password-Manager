exe: Main.o Password.o Passwords.o
	g++ -o exe Main.o Password.o Passwords.o
Password.o: password.cpp password.h
	g++ -c password.cpp
Passwords.o: passwords.cpp passwords.h password.h
	g++ -c passwords.cpp
Main.o: main.cpp password.h passwords.h
	g++ -c main.cpp
clean:
	rm *.o
	rm ./exe