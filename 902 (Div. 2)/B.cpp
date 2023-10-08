#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b){
    return a.second<b.second;
}


void solve(){

    ll n,P;
    cin>>n>>P;
    vector<pair<ll,ll>> a(n);
    for(auto &x:a) cin>>x.first;
    for(auto &x:a) cin>>x.second;

    sort(a.begin(),a.end(),comp);

    ll res=P;
    ll p=1;

    for(ll i=0;i<n;i++){
        if(a[i].second<P){
            if(p+a[i].first<n){
                p += a[i].first;
                res += a[i].first*a[i].second;
            }
            else{
                res += a[i].second*(n-p);
                p=n;
            }
        }
    }

    res += P*(n-p);

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