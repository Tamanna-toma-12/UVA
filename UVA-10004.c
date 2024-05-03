#include<stdio.h>
int main()
{
    int number_of_node;
    while(scanf("%d",&number_of_node))
    {
        if(number_of_node==0)break;
        int number_of_edge;
        scanf("%d",&number_of_edge);
        int i,j;
        int adjacency_matrix[number_of_node][number_of_node];
        for(i=0;i<number_of_node;i++){
            for(j=0;j<number_of_node;j++){
                adjacency_matrix[i][j]=0;
            }
        }
        int x,y;
        for(i=0;i<number_of_edge;i++){
            scanf("%d %d",&x,&y);
            adjacency_matrix[x][y]=1;
            adjacency_matrix[y][x]=1;
        }
        int queue[number_of_node+5];
        queue[0]=0;
        j=0;
        int k;
        int ans=0;
        int colour[number_of_node];
        for( i=0;i<number_of_node;i++)colour[i]=-1;
        colour[0]=1;
        int node,node_colour,adjacent_colour;
        for( i=0;i<number_of_node;i++){
                node=i;
             node_colour=colour[i];
        if(node_colour==1)adjacent_colour=2;
        else adjacent_colour=1;
        for(k=0;k<number_of_node;k++){
            if(adjacency_matrix[node][k]==1){
                if(colour[k]==-1){
                        colour[k]=adjacent_colour;
                        j++;
                        queue[j]=k;
                }

                else if(colour[k]==node_colour){
                    ans=-1;
                    break;
                }
            }
        }
        }
        if(ans==-1)printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");
    }

    return 0;
}
/*
6 6
0 1
1 2
2 3
3 4
4 5
0 5
*/
