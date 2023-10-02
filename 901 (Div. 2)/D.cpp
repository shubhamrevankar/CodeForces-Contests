#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int M=1e9+7;
long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}

ll fun(ll i,ll mex, vector<vector<int>> &dp,unordered_map<ll,ll> &freq){
    if(i==0){
        return (freq[0]-1)*mex;
    }
    if(dp[i][mex]!=-1) return dp[i][mex];
    return dp[i][mex] = min(fun(i-1,mex,dp,freq),(freq[i]-1)*mex + i + fun(i-1,i,dp,freq));
}


void solve(){

    ll n;
    cin>>n;
    vector<ll> a(n);
    unordered_map<ll,ll> freq;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    ll mex;
    for(ll i=0;i<=n;i++){
        if(freq[i]==0){
            mex = i;
            break;
        }
    }
    
    if(mex==0){
        cout<<"0"<<endl;
        return;
    }

    vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

    cout<<fun(mex-1,mex,dp,freq)<<endl;


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