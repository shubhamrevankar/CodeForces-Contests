#include <bits/stdc++.h>
using namespace std;
#define ll long long

//--------------TLE wala code------------------
/*

ll find(vector<ll> &v,ll k, unordered_map<ll,ll> &m){
    ll n = v.size();
    if(n==0) -1;
    if(v[0]>k) return -1;

    ll q = k/v[0];
    ll i=0;
    ll idx=-1;
    while(i<n && (k/v[i])==q){
        idx = max(idx,m[v[i]]);
        i++;
    }
    
    return idx;
}


void solve(){

    ll n;
    cin>>n;
    vector<ll> c(n);
    for(auto &x:c) cin>>x;
    ll k;
    cin>>k;

    unordered_map<ll,ll> m;
    for(int i=0;i<n;i++){
        m[c[i]] = i;
    }

    vector<ll> res(n,0);

    vector<ll> v;
    for(auto x:m) v.push_back(x.first);
    sort(v.begin(),v.end());

    while(k>0){
        ll nm = find(v,k,m);
        if(nm != -1){
            res[nm]++;
            k -= c[nm];
        }
        else{
            k=0;
        }
    }

    for(ll i=n-2;i>=0;i--){
        res[i] = res[i+1]+res[i];
    }

    for(auto x:res){
        cout<<x<<" ";
    }cout<<endl;


}

*/

//--------------Optimal wala code--------------

void solve(){

    ll n;
    cin>>n;
    vector<ll> c(n);
    for(auto &x:c) cin>>x;
    ll k;
    cin>>k;

    for(ll i=n-2;i>=0;i--){
        c[i] = min(c[i],c[i+1]);
    }

    ll q,r;

    vector<ll> res(n,0);

    q = k/c[0];
    r = k%c[0];
    res[0] = q;

    for(ll i=1;i<n;i++){
        ll dif = c[i]-c[i-1];
        ll rep;
        if(dif==0) rep=q;
        else rep = min(q,r/dif);

        res[i-1] -= rep;
        res[i] = q = rep;
        k -= dif*rep;
        r -= dif*rep;
    }
    
    for(ll i=n-2;i>=0;i--){
        res[i] = res[i]+res[i+1];
    }

    for(auto x:res){
        cout<<x<<" ";
    }cout<<endl;

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