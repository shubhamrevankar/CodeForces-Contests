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


void solve(){

    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;
    vector<ll> b(m);
    for(auto &x:b) cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll suma=0,sumb=0;

    for(auto x:a) suma += x;
    for(auto x:b) sumb += x;

    ll mn = min(a[0],b[0]);
    ll mx = max(a[n-1],b[m-1]);


    if(k==1){
        ll k1 = max(a[0],b[m-1]);
        cout<<suma+k1-a[0]<<endl;
        return;
    }

    if(a[0]<b[m-1]){
        swap(a[0],b[m-1]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(b[0]<a[n-1]){
        swap(b[0],a[n-1]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());


    suma=0;
    for(auto x:a) suma += x;

    if(k%2==0){
        cout<<suma<<endl;
        return;
    }
    else{
        cout<<suma+mx-mn<<endl;
        return;
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