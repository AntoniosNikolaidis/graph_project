I made 3 algorithms with the purpose of finding the shortest path from one point to
all the other ones. My input was txt file and I tested my algorithms with 3
different files (demo.txt,demo1.txt,demo2.txt) which contain a lower triangular
array. The first data is the size of the array (number of points). If the value of
the data were to be -1 then I wouldn&#39;t have a direct connection from the point I’m
currently at to the point that I want to go. Therefore, I would have to find a
different path. In all 3 algorithms I used same main.c and solve.h.
1. In the first algorithm, I used the file flowarre.c/.h which uses a
recursive algorithm in order to find the shortest path and print the distance. For
the compilation I wrote the command gcc -o example main.c flowarrec.c and run it as
the following ./example &lt; demo.txt or with the other demo files.
2. In the second algorithm, I used the file flowarmem.c/.h which is the
evolution of the first algorithm, since the first one is too slow for big inputs.
Therefore, I created an algorithm with a three-dimensional array that uses
recursive but every time I found a path I saved it in the array. I completed this
so whenever I would need it again, I wouldn’t have to calculate again but instead
it would take it directly from the array. gcc -o example main.c flowarmem.c and run
it like this ./example &lt; demo.txt or with the other demo files.
3. In the third algorithm, I used an iterative method in order to find the
shortest path as well as the path to reach the final point. The path was printing
when I wrote in the start of the file #define PATH else the algorithm prints only
the best distance. gcc -o example main.c flowardp.c and run it like this ./example
&lt; demo.txt or with the other demo files
