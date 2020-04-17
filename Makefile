main: main.o base.o extras.o
	gcc -o main main.o base.o extras.o
main.o: main.c
	gcc -c main.c
base.o: base.c
	gcc -c base.c
extras.o: extras.c
	gcc -c extras.c
clean:
	rm main.o base.o extras.o

