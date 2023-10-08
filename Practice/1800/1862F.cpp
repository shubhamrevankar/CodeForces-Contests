#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll,ll> m;

ll rec(vector<ll> &s,ll i, ll sum,ll l, ll h, ll n,unordered_map<ll,ll> &dp){
    if(sum>=l && sum<=h) return 1;
    if(sum>h || i>=n) return 0;

    if(m.find(sum)!=m.end()) return m[sum];

    for(ll j=i;j<n;j++){
        if(rec(s,j+1,sum+s[j],l,h,n,dp)) return m[sum] = 1;
    }
    return m[sum] = 0;
}

ll fun(vector<ll> &s,ll sum,ll w, ll f, ll n){
    m.clear();
    return rec(s,0,0,sum-f,w,n,m);
}

void solve(){

    

    ll w,f,n,W,F;
    cin>>w>>f;
    W=w;F=f;
    cin>>n;
    vector<ll> s(n);
    for(auto &x:s) cin>>x;

    ll res=1,sum=0;

    for(ll i=0;i<n;i++){
        sum += s[i];
    }

    while((w+f)<sum){
        w += W;
        f += F;
        res++;
    }

    while(!fun(s,sum,w,f,n)){
        w += W;
        f += F;
        res++;
    }

    cout<<res<<endl;


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