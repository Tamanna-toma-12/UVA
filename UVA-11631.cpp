#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,m;
    while(cin>>n>>m){
      if(n==0&&m==0)break;
      vector<pair<ll,ll>>adj[n];
      ll sum=0;
      for(int i=0;i<m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
        sum+=w;
      }
      ll ans=0;
      priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
      q.push({0,0});
      vector<int>vis(n,0);
      while(!q.empty()){
        int node=q.top().second;
        ll d=q.top().first;
        q.pop();
        if(vis[node]==1)continue;
        vis[node]=1;
        ans+=d;
        for(auto u:adj[node]){
            q.push({u.second,u.first});
        }
      }
      cout<<sum-ans<<endl;

    }
    return 0;
}
