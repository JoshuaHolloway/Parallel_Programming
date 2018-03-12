readme.txt - Josh Holloway

Instructions from here:
https://www.youtube.com/watch?v=4qSzOv1pcsM


# Method 1 - Full command line method

# Compile any seperate files (e.g. a class called CLASS with a corresponding header file):
$ g++ -c Class.h
$ g++ -c Class.cpp

# Acter compilation, the intermediate output file (.o) and another intermediate file (.gch) are created.

# Compile and link (naming the program main)
$ g++ -c main.cpp
$ g++ -o main main.o Class.o

# Run the program
$ ./main

#===============================

# Method 2 - Build compile script

# The contents of compile.sh has the following:
g++ -c Class.h              # Compile the header to look for errors
g++ -c Class.cpp            # Compile the implementation to produce the -o file
g++ -c main.cpp             # Compile the main routine
g++ -o main main.o Class.o  # Put them together
rm *.o                      # Remove temp files
rm *.*.gch

# To run the script you may need to change permistions:
$ chmod +x compile.sh
$ ./compile.sh
$ ./main
