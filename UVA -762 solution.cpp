#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll  long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define  endl "\n"
#include<ext/pb_ds/assoc_container.hpp>
#define lcm(a,b) a/__gcd(a,b)*b
/*using namespace __gnu_pbds;
//typedef tree< long long, null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update >ordered_set;//for set
///less er jaigay greater dile boro theke choto set
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;//for multiset
///less er jaigay greater dile boro theke choto multiset
///cout<<x(name of set or multiset).order_of_key(-5(parameter))<<endl;//number of items in a set that are stricly smaller than
///our item*/
const ll mx=2e5+123;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 map<string,vector<string>>adj;
    vector<pair<string,string>>ans;
     map<string,string>parent;
int main()
{
    optimize();
    ll c=0;
    ll n;
    bool y=0;
    while(cin>>n){
            if(y)cout<<endl;
          y=1;
            adj.clear();
       string s,t;
      ans.clear();
      parent.clear();
       for(int i=0;i<n;i++){
        cin>>s>>t;
        adj[s].pb(t);
        adj[t].pb(s);
       }
       cin>>s>>t;
       queue<string>q;
       q.push(s);
       map<string,int>vis;
       vis[s]=1;
       while(!q.empty()){
        string node=q.front();
        q.pop();
        for(auto u:adj[node]){
            if(vis[u]==0){
                vis[u]=1;
                parent[u]=node;
                q.push(u);
            }
        }

       }
       if(vis[t]==0)cout<<"No route"<<endl;
        else{
            string p=parent[t];
            string node=t;

            while(!parent[t].empty()){
                ans.pb({parent[t],t});
                t=parent[t];
            }
            reverse(all(ans));
            for(auto u:ans){
                cout<<u.first<<" "<<u.second<<endl;
            }
        }


    }
    return 0;
}
