#include<stdio.h>
int directions1[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int directions2[] = {0, +1, 0, -1, +1, -1, +1, -1};
char adjacency_matrix[200][200];
int visited[200][200];
void dfs(int row,int column,int number_of_row,int number_of_column)
{
    visited[row][column]=1;
    int x,new_row,new_column;
    for(x=0;x<8;x++){
        new_row=row+directions1[x];
        new_column=column+directions2[x];
        if(new_row>=0&&new_row<number_of_row&&new_column>=0&&new_column<number_of_column&&adjacency_matrix[new_row][new_column]=='1'&&visited[new_row][new_column]==0){
            dfs(new_row,new_column,number_of_row,number_of_column);
        }
    }

}
int main()
{
    int number_of_row,number_of_column;
    int t=1;
    while(scanf("%d",&number_of_row)!=EOF)
          {
              number_of_column=number_of_row;
    int i,j;
    for(i=0;i<number_of_row;i++){
       scanf("%s",adjacency_matrix[i]);
    }
    for(i=0;i<number_of_row;i++){
        for(j=0;j<number_of_column;j++){
            visited[i][j]=0;
        }
    }
    int count=0;
    for(i=0;i<number_of_row;i++){
        for(j=0;j<number_of_column;j++){
            if(visited[i][j]==0&&adjacency_matrix[i][j]=='1'){
               count++;
               dfs(i,j,number_of_row,number_of_column);
            }
        }
    }
    printf("Image number %d contains %d war eagles.\n",t,count);
    t++;
}
    return 0;
}
