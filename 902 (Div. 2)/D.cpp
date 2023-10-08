#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int M=998244353;
long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}

ll res=0;


void rec(vector<ll> &a, ll n, ll mx){
    if(n<=0){
        res = add(res,mx);
        return;
    }

    rec(a,n-1,max(mx,a[n]));
    rec(a,n-1,mx);

}


void solve(){

    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];

    for(ll i=n;i>=1;i--){
        ll j=i;
        while(j<=n){
            a[i] = max(a[i],a[j]);
            j += i;
        }
    }
    res=0;

    // vector<vector<ll>> dp()

    rec(a,n,0);


    cout<<res<<endl;

}



    // for(auto x:a){
    //     cout<<x<<" ";
    // }cout<<endl;



int main() {
	// ll t;
    // cin>>t;
    // while (t--)
    // {
        solve();
    // }
    
	return 0;
}