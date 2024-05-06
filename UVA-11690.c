#include<stdio.h>
int parent[10034];
 int money[10034];
int Rank[10034];
void make(int x){
    int i;
    for( i=0;i<x;i++)
        {
  parent[i]=i;
  money[i]=0;
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
        if(money[a]<money[b]){
            int temp=a;
            a=b;
            b=temp;
        }
        parent[b]=a;
        money[a]+=money[b];
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
    int t;
    scanf("%d",&t);
    while(t--){
           int n,m;
    scanf("%d %d",&n,&m);
 int a[n];
    int i,j,k,x,y;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    make(n);
    for(i=0;i<n;i++)money[i]=a[i];
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        if(Find(x)!=Find(y))UnionBySize(x,y);
    }
     int d=1;
     for(i=0;i<n;i++){
        if(parent[i]==i&&money[i]!=0){
            d=0;
            break;
        }
     }
     if(d==1)printf("POSSIBLE\n");
     else printf("IMPOSSIBLE\n");
    }

    return 0;
}


