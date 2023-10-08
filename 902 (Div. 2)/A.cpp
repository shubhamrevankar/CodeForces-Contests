#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    ll n;
    cin>>n;
    n--;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    ll sum =0 ;
    
    for(ll i=0;i<n;i++) sum += a[i];

    cout<<-sum<<endl;

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