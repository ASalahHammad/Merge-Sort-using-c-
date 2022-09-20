Merge Sort using c++

There are two scripts in this repository:
The "write.c" program generates one hundred random numbers between 0 and 100 in a text file called "nums".
The "mergesort.cpp" can take no input when called from the terminal, it shall then print a random ordered array -defined in the file itself- and then print it again after it has been sorted
Or it can take another input from the terminal, which shall be the name of a file written in binary that carries some numbers that need to be sorted

/////// Very important note note:
        the file should be written in binary as double precision numbers
        Otherwise the script I wrote won't work
        You can solve this by replacing every "double" word in "mergesort.cpp" to the type you have written your file in.
///////

You can also run the function "time" before calling "mergesort" to see the time it took

Example: Enter the line below in the terminal
time mergesort nums

After sorting the numbers in a file, sorted data are put in a new file with the name "sorted"