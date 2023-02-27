#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main(){
	int n,i,j,**graph;				
	scanf("%d",&n);					//i take from the file the size of matrix 
	graph=malloc(n*sizeof(int *));			
	if (graph==NULL)				
		return-1;
	for (i=0;i<=n-1;i++){				
		*(graph+i)=malloc(n*sizeof(int));
		if (*(graph+i)==NULL)			
			return -1;
	}
	for(i=0;i<=n-1;i++)
		for(j=0;j<=n-1;j++)
			if (i>j)			
				scanf("%d",&graph[i][j]); //i take all the data from input file
	for (i=0;i<=n-1;i++)
		graph[i][i]=0;				
	solve(n,graph);		//i call one of the 3 algorithm it depends from the compilation	
	for (i=0;i<n;i++){
		free(graph[i]);				
	}
	free(graph);					
}


