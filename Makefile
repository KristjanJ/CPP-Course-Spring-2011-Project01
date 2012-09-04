# To compile, run 'make' in the same directory as this file 

# Declare the name of our program (in Windows, the compiler adds .exe) 
PROGRAM = program 

# The needed object files (we make these from the source code) 
OBJ = main.o functions.o 

# Compiler flags (-Wall shows all warnings when compiling, always use this!) 
CFLAGS = -Wall 

# This is the first target. It will be built when you run 'make' or 'make all' 
all: $(PROGRAM) doc

# Rule for linking IMPORTANT! The space in front of $(CC) is a TABULATOR! 
$(PROGRAM): $(OBJ) 
	$(CXX) $(OBJ) -o $(PROGRAM) 

# Rules for compiling 
main.o: main.cpp 
	$(CXX) -c main.cpp -o main.o $(CFLAGS) 

functions.o: functions.cpp 
	$(CXX) -c functions.cpp -o functions.o $(CFLAGS)

#TARGET CLEAN
clean:
	rm -rf docs
	rm -f *.o
	rm -f program

#TARGET DOC
doc:
	doxygen Doxyfile