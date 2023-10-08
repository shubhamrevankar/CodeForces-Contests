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

// ll rec(vector<ll> &a, ll n, ll mx,unordered_map<ll,ll> &dp){
//     if(n<=0){
//         // res = add(res,mx);
//         return mx;
//     }

//     if(dp.find((n)*100002 + (mx)) != dp.end()){
//         return dp[(n)*100002 + (mx)];
//     }

//     // if( dp.find((n-1)*100002 + (max(mx,a[n]))) == dp.end()){
//     //     rec(a,n-1,max(mx,a[n]),dp);
//     // }
//     // if( dp.find((n-1)*100002 + (mx)) == dp.end()){
//     //     rec(a,n-1,mx,dp);
//     // }

//     return dp[(n)*100002 + (mx)] = (add(rec(a,n-1,max(mx,a[n]),dp),rec(a,n-1,mx,dp)));

// }

ll pow2(ll n){
    if(n==0) return 1;
    if(n==1) return 2;
    ll nby2 = pow2(n/2);
    if(n%2==1) return mul(mul(nby2,nby2),2);
    return mul(nby2,nby2);
}


void solve(){

    ll n;
    cin>>n;
    vector<ll> a(n+1);
    ll maxele= INT_MIN;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        maxele = max(maxele,a[i]);
    }

    for(ll i=n;i>=1;i--){
        ll j=i;
        while(j<=n){
            a[i-1] = max(a[i-1],a[j-1]);
            j += i;
        }
    }
    ll res=0;

    sort(a.begin(),a.end(),greater<ll>());

    for(ll i=0;i<n;i++){
        res = add(res,mul(pow2(n-i-1),a[i]));
    }

    // unordered_map<ll,ll> dp;

    // vector<vector<ll>> dp(n+5,vector<ll>(maxele+5,-1));

    // rec(a,n,0,dp);

    // cout<<rec(a,n,0,dp)<<endl;

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