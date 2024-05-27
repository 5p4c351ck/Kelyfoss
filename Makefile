executable = kelyfoss
objs = get_input.o main.o

all: $(executable)

$(executable) : $(objs)
	gcc $(objs) -o $(executable)

get_input.o : get_input.c
	gcc -c get_input.c -o get_input.o


main.o : main.c
	gcc -c main.c -o main.o


clean:
	rm *.o