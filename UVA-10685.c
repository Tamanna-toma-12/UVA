#include<stdio.h>
int parent[30034];
int siz[30034];
int Rank[30034];
void make(int x){
    int i;
    for( i=1;i<=x;i++)
        {
  parent[i]=i;
  siz[i]=1;
    }
}
int Find (int x){
 if (parent[x]==x)return x;
 return parent[x]=Find(parent[x]);
}
void UnionBySize(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a!=b){
        if(siz[a]<siz[b]){
            int temp=a;
            a=b;
            b=temp;
        }
        parent[b]=a;
        siz[a]+=siz[b];
    }
}
void UnionByRank(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a==b)return;
    if(Rank[a]<Rank[b]){
        parent[a]=b;
    }
    else if(Rank[a]>Rank[b]){
      parent[b]=a;
    }
    else{
        parent[a]=b;
        Rank[b]++;
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)){
        int i,j,k,x,y;
        if(n==0&&m==0)break;
        for(i=0;i<n;i++){
                parent[i]=i;
                siz[i]=1;
        }
        char creature[n][50];
        for(i=0;i<n;i++){
                scanf("%s",creature[i]);
        }
        char c1[50];
        char c2[50];
        for(i=0;i<m;i++){
            scanf("%s",c1);
            scanf("%s",c2);
            for(j=0;j<n;j++){
                if(strcmp(c1,creature[j])==0){
                    x=j;
                    break;
                }
            }
             for(j=0;j<n;j++){
                if(strcmp(c2,creature[j])==0){
                    y=j;
                    break;
                }
             }
            if(Find(x)!=Find(y)){
                UnionBySize(x,y);
            }
        }
     int ans=0;
     int count[n+1];
     for(i=0;i<n;i++)count[i]=0;
     for(i=0;i<n;i++){
        j=Find(i);
        count[j]++;
     }

     for( i=0;i<n;i++){
        if(count[i]>ans)ans=count[i];
     }
     printf("%d\n",ans);
    }

    return 0;
}

