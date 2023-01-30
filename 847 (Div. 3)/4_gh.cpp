#include <bits/stdc++.h>
using namespace std;
#define ll long long


// -----------Hash map causes collisions which makes all operations O(n^2) instead of O(n)---------//
//------------------------So to avoid hacking we should use this custom hash-----------------------//
//-------------------------------------the method to use it is-------------------------------------//
// unordered_map<ll,ll,custom_hash> m;
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


void solve(){

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;
    sort(a.begin(),a.end());
    

    unordered_map<ll,ll> m;

    for(ll i=0;i<n;i++){
        if(m[a[i]-1]!=0){
            m[a[i]-1]--;
        }
        m[a[i]]++;
    }

    ll count=0;

    for(auto x:m){
        count += x.second;
    }

    cout<<count<<endl;

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