mergesort:
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=gnu++11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o mergesort.o mergesort.cpp -lstdc++ # I took this from Iharob Al Asimi <https://stackoverflow.com/q/28995731>
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=gnu11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o write.o write.c
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=gnu++11 -o mergesort mergesort.o write.o -lstdc++ -lm
