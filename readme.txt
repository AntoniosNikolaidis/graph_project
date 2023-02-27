We use 3 different ways to find the best path from any graph to all the others.Our input is 
a txt file and I test it with 3 files (demo.txt,demo1.txt,demo2.txt) that contain a lower 
triangular matrix and the first data is the size of the matrix (number of graphs ). 
If the value of the data is -1 then we don’t have direct connection from the graph that 
we are and the graph that we want to go so we have to find another path . 
In all ways we use the same main.c and solve.h . 
    1.    In the first way I use the file flowarre.c/.h that use a recursive algorithm to 
find the best path and print the distance. For the compilation write the command 
gcc -o example main.c flowarrec.c and run it like this ./example < demo.txt or with the other demo files
    2.    In the second way I use the file flowarmem.c/.h this algorithm is the evolve of 
the 1. algorithm because the first algorithm is too slow for big inputs . So I create a 
algorithm with a three-dimensional matrix that use recursive but everytime i find a path 
i save it in the matrix so when I will need it again I will not calculate it again but 
I will take it directly from the matrix . gcc -o example main.c flowarmem.c and run it 
like this ./example < demo.txt or with the other demo files
    3.    In the third way I use an iterative method to find the best path and i calculate 
also the path that i through to reach the final graph. The path is printing if i write in 
the start of file #define PATH else the algorithm print only the best distance. 
gcc -o example main.c flowardp.c and run it like this ./example < demo.txt or with the other demo files