#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool res=true;

void dfs(vector<vector<ll>> &adj,ll i, vector<bool> &vis, ll c,ll k, vector<ll> &cnt,ll p){

    vis[i]=true;
    cnt[i] = c;

    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(adj,x,vis,c+1,k,cnt,i);
        }
        else if(x!=p){
            if((abs(c-cnt[x])+1)!=k){
                res = false;
            }
        }
    }
}


void solve(){

    res = true;

    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    if(k==1){
        for(ll i=0;i<n;i++){
            if(a[i]!=i+1){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }

    vector<vector<ll>> adj(n+1);

    for(ll i=0;i<n;i++){
        adj[a[i]].push_back(i+1);
        adj[i+1].push_back(a[i]);
    }

    vector<bool> vis(n+1,false);
    vector<ll> cnt(n+1,0);

    for(ll i=1;i<=n;i++){
        if(!vis[i])
            dfs(adj,i,vis,1,k,cnt,-1);
    }
    
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}






int main() {
	ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
	return 0;
}