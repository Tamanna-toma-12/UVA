#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    bool y=0;
    while(t--){
      if(y)  cout<<endl;
        int n;
        cin>>n;
        y=1;
       vector<pair<double,double>>v(n);
       for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
       vector<pair<long long,double>>adj[n];
       for(int i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            long long x=pow(abs(v[i].first-v[j].first),2)+pow(abs(v[i].second-v[j].second),2);
            double d=sqrt(x*1.0);
            adj[i].push_back({j,d});

        }
       }
    /*   for(int i=0;i<n;i++){
        cout<<i<<" :";
        for(auto u:adj[i]){
            cout<<u.first<<" "<<u.second<<endl;
        }
       }*/
       priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>q;
       q.push({0,0});
       double sum=0;
       vector<int>vis(n,0);
     //  vis[0]=1;
       while(!q.empty()){
        int node=q.top().second;
        double d=q.top().first;
        q.pop();
        if(vis[node]==1)continue;
        vis[node]=1;
        sum+=d;
        //cout<<node<<" "<<d<<endl;
        for(auto u:adj[node]){
          q.push({u.second,u.first});
        }
       }
     cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}
