CC=gcc

# name of the lib being built
TARG=blockqueue

# source files
SRCFILES=\
		 ${TARG}.c\
		 ${TARG}.h\
		 queue.c\
		 queue.h\

# test files
TESTFILES=\
		 ${TARG}_test.c\
		 queue_test.c\

# object files
OBJFILES=\
		 ${TARG}.o\
		 ${TARG}_test.o\
		 queue.o\
		 queue_test.o\

OPTFLAGS=-O0
DEBUGFLAGS=-g

CFLAGS=\
	   ${OPTFLAGS}\
	   ${DEBUGFLAGS}\

# build executable file
#main: ${OBJFILES} 
	#${CC} ${OBJFILES} -o $@ 
	#@echo "Done. Executable is: $@"

queue: queue.o queue_test.o
	${CC} queue.o queue_test.o -o $@ 
	@echo "Done. Executable is: $@"

blockqueue: ${OBJFILES}
	${CC} blockqueue.o queue.o blockqueue_test.o -o $@ -lpthread
	@echo "Done. Executable is: $@"

clean:
		rm -f *.o main
	
.c.o:
	${CC} ${CFLAGS} -c $<
