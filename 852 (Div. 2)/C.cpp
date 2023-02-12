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


void solve(){

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    vector<ll> llf(n),hlf(n),lr(n),hr(n);

    llf[0] = hlf[0] = a[0];
    for(int i=1;i<n;i++){
        llf[i] = min(llf[i-1],a[i]);
        hlf[i] = max(hlf[i-1],a[i]);
    }

    lr[n-1] = hr[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        lr[i] = min(lr[i+1],a[i]);
        hr[i] = max(hr[i+1],a[i]);
    }

    ll left=0;

    for(int i=0;i<n;i++){
        if(a[i]!=lr[i] && a[i]!=hr[i]){
            left=i;
            break;
        }
    }

    ll right=n-1;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=llf[i] && a[i]!=hlf[i]){
            right=i;
            break;
        }
    }

    if(left>=right){
        cout<<"-1"<<endl;
    }
    else{
        cout<<left+1<<" "<<right+1<<endl;
    }



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