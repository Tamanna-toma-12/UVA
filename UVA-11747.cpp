#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
int parent[1200];
int siz[1200];
int Rank[1200];
void make(int x){
  parent[x]=x;
  siz[x]=1;
}
int Find (ll x){
 if (parent[x]==x)return x;
 return parent[x]=Find(parent[x]);
}
void UnionBySize(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a!=b){
        if(siz[a]<siz[b]){
            swap(a,b);
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
    optimize();
    ll n,m;
    bool y=0;
    while(cin>>n>>m){
      if(n==0&&m==0)break;
      vector<pair<ll,pair<ll,ll>>>v;
      for(int i=0;i<m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        v.pb({w,{x,y}});
      }
      for(int i=0;i<n;i++)parent[i]=i;
      vector<ll>ans;
      sort(v.begin(),v.end());
      for(auto u:v){
        if(Find(u.second.first)!=Find(u.second.second)){
            UnionByRank(u.second.first,u.second.second);
        }
        else ans.pb(u.first);
      }
      sort(ans.begin(),ans.end());
      if(ans.size()==0)cout<<"forest"<<endl;
      else{
       for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1)cout<<" ";
       }
        cout<<endl;
      }
    }
    return 0;
}
