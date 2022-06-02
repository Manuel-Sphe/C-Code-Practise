#This is a Makefile 
CC=g++                  #the compiler name
CCFLAGS=-std=c++2a      #flags passed to compiler
TARGET= file.exe        #executable file
OBJECT= *.o             #binary file(s) 
SOURCE= *.cpp           #cc++ file(s)

#linking rules
$(TARGET): $(OBJECT)
	$(CC)	$(OBJECT)	-o	$(TARGET)	$(CCFLAGS)

#building rule
$(OBJECT): $(SOURCE)
	$(CC)	-c	$(SOURCE)	$(CCFLAGS)

#execution rule 
run:
	./file.exe	$(args)

#clean rule     
clean:
	@rm	-f	*.o 
	@rm	-f	*.exe