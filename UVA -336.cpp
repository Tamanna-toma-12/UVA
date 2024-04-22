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
int main()
{
    optimize();
    ll c=0;
    ll n;
    while(cin>>n){
        if(n==0)break;
        map<ll,vector<ll>>adj;
        map<ll,ll>dis;
        for(int i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
            dis[x]=100000000;
            dis[y]=100000000;
        }
        ll p,t;
        while(cin>>p>>t){
            if(p==0&&t==0)break;
            c++;
            cout<<"Case "<<c<<": ";
            queue<ll>q;
            map<ll,ll>vis;
            ll co=1;
            q.push(p);
            vis[p]=1;
            dis[p]=0;
            while(!q.empty()){
                ll node=q.front();
                q.pop();
                for(auto u:adj[node]){
                   if(vis[u]==0&&dis[node]+1<=t){
                    vis[u]=1;
                    q.push(u);
                    dis[u]=dis[node]+1;
                    co++;
                   }
                }

            }
            ll s=adj.size();
            cout<<s-co<<" nodes not reachable from node "<<p<<" with TTL = "<<t<<"."<<endl;
        }
    }
    return 0;
}
