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
    for(auto &x:a) cin>>x;
    string s;
    cin>>s;


    ll zerowala =0, onewala=0;

    vector<ll> xorpre(n,0);
    ll xxor=0;

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zerowala ^= a[i];
        }
        else{
            onewala ^= a[i];
        }
        xxor ^= a[i];
        xorpre[i] = xxor;
    }


    ll q;
    cin>>q;

    vector<ll> res;

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            ll l,r;
            cin>>l>>r;
            l--;r--;
            zerowala ^= xorpre[r];
            onewala ^= xorpre[r];
            if(l>0){
                zerowala ^= xorpre[l-1];
                onewala ^= xorpre[l-1];
            }
        }
        else{
            ll g;
            cin>>g;
            if(g==0){
                res.push_back(zerowala);
            }
            else{
                res.push_back(onewala);
            }
        }
    }

    for(auto x:res){
        cout<<x<<" ";
    }
    cout<<endl;



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