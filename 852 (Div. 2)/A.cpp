#include <bits/stdc++.h>
using namespace std;
#define ll long long



void solve(){

    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    ll f = m*a;
    ll res=0;

    ll mn=min(a,b);


    ll c=n/(m+1);
    ll mo = n%(m+1);

    ll ff = c*a*m+mo*mn;
    if(ff < mn*n){
        res += ff;
    }
    else{
        res += mn*n;
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