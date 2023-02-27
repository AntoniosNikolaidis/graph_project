#include <stdio.h>
#include <stdlib.h>
#include "flowarmem.h"

void solve(int n,int **graph){
        int k,i,j,***p3=(int***)malloc(n*sizeof(int**));       //i create the 3-d matrix 
        if (p3==NULL)                                           
                 return;
        for(i=0;i<n;i++){
                p3[i]=(int**)malloc(n*sizeof(int*));            
                if (p3[i]==NULL)                               
                         return;
                for (j=0;j<n;j++){
                        p3[i][j]=(int*)malloc(n*sizeof(int));           
                        if (p3[i][j]==NULL)                             
                                 return;
                }
        }
        for (i=0;i<n;i++){
                for (k=0;k<n;k++){
                        for (j=0;j<n;j++)
                                p3[i][j][k]=-2;                 
                }
        }
        k=n-1;                                                  
        for (i=1;i<n;i++)                                      
                for (j=0;j<i;j++)
                        printf("From node  %d to node %d: Length of shortest path is %d\n",i,j,p(i,j,k,graph,p3));
        for (i=0;i<n;i++){
                for (j=0;j<n;j++){
                        free(p3[i][j]);                         
                }
                free(p3[i]);                                    
        }
        free(p3);                                              
}

int p(int i,int j,int k,int **graph,int ***p3){     // i calculate the shortest path with recursive and a matrix
        int sum,sum1,sum2,sum3,l;				
        if (k==-1){					
                if (graph[i][j]==0)				
                        return graph[j][i];
                else
                        return graph[i][j];
        }else if (k>=0){					
                if (i==j)					
                        return 0;
		if (p3[k][j][k]!=-2)				
			l=p3[k][j][k];
		else{						
            l=p(k,j,k-1,graph,p3);				
			p3[k][j][k]=l;
		}
		if (p3[i][k][k]!=-2)				
			sum3=p3[i][k][k];
		else{						
            sum3=p(i,k,k-1,graph,p3);				
			p3[i][k][k]=sum3;
		}
                if (l==-1||sum3==-1)				
                        sum1=-1;
                else
                        sum1=l+sum3;				
		if (p3[i][j][k]!=-2)				
			sum=p3[i][j][k];
		else{						
            sum=p(i,j,k-1,graph,p3);				
			p3[i][j][k]=sum;
		}
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
