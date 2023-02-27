#include <stdio.h>
#include <stdlib.h>
#include "flowarrec.h"

void solve(int n,int **graph){
        int k,i,j;                                      
        k=n-1;                                          
        for (i=1;i<n;i++){                              
                for (j=0;j<i;j++){
                        printf("From node  %d to node %d: Length of shortest path is %d\n",i,j,p(i,j,k,graph)); 
                }
        }
}

int p(int i,int j,int k,int **graph){ //i calculate the shortest path with recursive
	int sum,sum1,sum2,sum3,l;			
	if (k==-1){					
                if (graph[i][j]==0)			
                        return graph[j][i];
                else
                        return graph[i][j];
        }else if (k>=0){				
                if (i==j)				
                        return 0;
                l=p(k,j,k-1,graph);			
                sum3=p(i,k,k-1,graph);			
                if (l==-1||sum3==-1)			
                        sum1=-1;
                else					
                        sum1=l+sum3;
                sum=p(i,j,k-1,graph);			
                if (sum==-1&&sum1<0)			
                        return -1;
                else if (sum!=-1&&sum1<0)		
                        return sum;
                else if (sum==-1&&sum1>=0)	
                        return sum1;
                else if (sum!=-1&&sum1>=0){		
                        if (sum<sum1)			
                                return sum;
                        else
                                return sum1;
                }
        }
}
