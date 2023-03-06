#include <stdio.h>
#include <stdlib.h>
#include "flowardp.h"
#define PATH					//if i use the coommand define PATH then the algorith show us the path that through

void solve(int n,int **graph){
        int k,i,j,**q,**next,u,v;                               
        k=n-1;                                                  
        q=malloc(n*sizeof(int *));                              
        #ifdef PATH                                             
        next=malloc(n*sizeof(int *));                           
        if (next==NULL)                                         
              return;
        #endif
        if (q==NULL)                                            
              return;
        for (i=0;i<=n-1;i++){
                *(q+i)=malloc(n*sizeof(int));                   
                #ifdef PATH                                    
                *(next+i)=malloc(n*sizeof(int));                
                if (*(next+i)==NULL)                           
                        return;
                #endif
                if (*(q+i)==NULL)                               
                        return;
        }
        for(i=0;i<=n-1;i++)
                for(j=0;j<=n-1;j++){
                        q[i][j]=graph[i][j];                    
                        #ifdef PATH                             
                        next[i][j]=j;                           
                        #endif
                }
        p(n,graph,q,next);                                     
        for (i=1;i<n;i++){
                for (j=0;j<i;j++){
                        printf("From node  %d to node %d: Length of shortest path is %d\n",i,j,q[i][j]);        
                        #ifdef PATH                                                                             
                        u=i;                                                                                   
                        v=j;
                        printf("Shortest path is: %d ->",u);
                        while (u!=v){                                           
                                printf(" %d ",next[u][v]);                      
                                u=next[u][v];
                                if (u!=v)
                    printf("->");
                        }
                        printf("\n");
                        #endif
                }
        }
        for (i=0;i<n;i++){
            free(q[i]);                                                         
                        #ifdef PATH                                             
                        free(next[i]);                                          
                        #endif
        }
    free(q);                                                                   
        #ifdef PATH                                                             
        free(next);                                                             
        #endif
}


int p(int n,int **graph,int **q,int **next){       //i calculate the shortest path with iterative method
        int i,k,j;										
        for (k=0;k<n;k++){									
                for (i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                if(i>k&&k>j){							
                                        if (q[i][j]==-1 && (q[i][k]!=-1&&q[k][j]!=-1)){		
                                                q[i][j]=q[i][k]+q[k][j];
						#ifdef PATH							
						next[i][j]=next[i][k];				
						#endif
                                       	}else if (q[i][j]!=-1 && (q[i][k]==-1||q[k][j]==-1)){	
                                                q[i][j]=q[i][j];
                                       	}else if (q[i][j]!=-1 && (q[i][k]!=-1&&q[k][j]!=-1)){	
                                                if (q[i][j]>q[i][k]+q[k][j]){			
                                                        q[i][j]=q[i][k]+q[k][j];
							#ifdef PATH				
							next[i][j]=next[i][k];			
							#endif
						}
                                        }
                                }else if (i>k&&k<j){						
                                        if (q[i][j]==-1 && (q[i][k]!=-1&&q[j][k]!=-1)){
                                                q[i][j]=q[i][k]+q[j][k];
						#ifdef PATH					
						next[i][j]=next[i][k];				
						#endif
                                       	}else if (q[i][j]!=-1 && (q[i][k]==-1||q[j][k]==-1)){
                                                q[i][j]=q[i][j];
                                        }else if (q[i][j]!=-1 && (q[i][k]!=-1&&q[j][k]!=-1)){
                                                if (q[i][j]>q[i][k]+q[j][k]){
                                                        q[i][j]=q[i][k]+q[j][k];
							#ifdef PATH				
							next[i][j]=next[i][k];			
							#endif
						}
                                        }
                                }else if (i<k && k>j){						
                                        if (q[i][j]==-1 && (q[k][i]!=-1&&q[k][j]!=-1)){
                                                q[i][j]=q[k][i]+q[k][j];
						#ifdef PATH					
						next[i][j]=next[i][k];				
						#endif
                                        }else if (q[i][j]!=-1 && (q[k][i]==-1||q[k][j]==-1)){
                                                q[i][j]=q[i][j];
                                        }else if (q[i][j]!=-1 && (q[k][i]!=-1&&q[k][j]!=-1)){
                                                if (q[i][j]>q[k][i]+q[k][j]){
                                                        q[i][j]=q[k][i]+q[k][j];
							#ifdef PATH				
							next[i][j]=next[i][k];			
							#endif
						}
                                        }
                                }else if (i<k&&k<j){						
                                        if (q[i][j]==-1 && (q[k][i]!=-1&&q[j][k]!=-1)){
                                                q[i][j]=q[k][i]+q[j][k];
						#ifdef PATH					
						next[i][j]=next[i][k];				
						#endif	
                                        }else if (q[i][j]!=-1 && (q[k][i]==-1||q[j][k]==-1)){
                                                q[i][j]=q[i][j];
                                        }else if (q[i][j]!=-1 && (q[k][i]!=-1&&q[j][k]!=-1)){
                                                if (q[i][j]>q[k][i]+q[j][k]){
                                                        q[i][j]=q[k][i]+q[j][k];
							#ifdef PATH				
							next[i][j]=next[i][k];			
							#endif
						}
                                        }
                                }
                        }
                }
        }
}

