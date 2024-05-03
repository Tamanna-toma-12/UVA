
#include<stdio.h>
int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};
char a[200][200];
int vis[200][200];
void dfs(int i,int j,int n,int m)
{
    vis[i][j]=1;
    int x,y,z;
    for(x=0;x<8;x++){
        y=i+dx[x];
        z=j+dy[x];
        if(y>=0&&y<n&&z>=0&&z<m&&a[y][z]=='@'&&vis[y][z]==0){
            dfs(y,z,n,m);
        }
    }

}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
          {
    if(m==0)break;
    int i,j;
    for(i=0;i<n;i++){
       scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vis[i][j]=0;
        }
    }
    int c=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(vis[i][j]==0&&a[i][j]=='@'){
               c++;
               dfs(i,j,n,m);
            }
        }
    }
    printf("%d\n",c);
}
    return 0;
}
