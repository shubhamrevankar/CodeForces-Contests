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

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a){
        ll t;
        cin>>t;
        x = t-1;
    }
    vector<ll> c(n);
    for(auto &x:c) cin>>x;


    vector<ll> ind(n,0);
    for(int i=0;i<n;i++){
        ind[a[i]]++;
    }

    ll count=0;
    ll res=0;

    while(count < n){

        int k=0;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                ind[i]=-1;
                ind[a[i]]--;
                res += 2*c[i];
                k++;
                count++;
            }
        }
        if(k==0){
            ll h=0;
            while(h<n && a[h]!=0 && a[h]!=-1) h++;
            ll idx=h;
            ll inh = h;
            h = a[h];
            while(h!=inh){
                if(c[h]>c[idx]) idx = h;
                h = a[h];
            }
            ind[idx] = -1;
            ind[a[idx]]--;
            res += c[idx];
            count++;
        }

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