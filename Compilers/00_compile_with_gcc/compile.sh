g++ -c Class.h              # Compile the header to look for errors
g++ -c Class.cpp            # Compile the implementation to produce the -o file
g++ -c main.cpp             # Compile the main routine
g++ -o main main.o Class.o  # Put them together
rm *.o                      # Remove temp files
rm *.*.gch
