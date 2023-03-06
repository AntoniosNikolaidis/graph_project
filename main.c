#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main(){
	int n,i,j,**graph;				
	scanf("%d",&n);					//i am taking from the file the size of array.
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
				scanf("%d",&graph[i][j]);         //i am taking all the data from input file
	for (i=0;i<=n-1;i++)
		graph[i][i]=0;				
	solve(n,graph);		//i am calling one of the 3 algorithms it depends from the compilation	
	for (i=0;i<n;i++){
		free(graph[i]);				
	}
	free(graph);					
}


