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


ll smallestNonTrivialDivisor(ll n) {
    if (n <= 1) return -1;  // Invalid input
    if (n <= 3) return -1;  // No non-trivial divisor for 2 and 3

    if (n % 2 == 0) return 2;  // Smallest non-trivial divisor for even numbers

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return i;
    }

    return -1;  // If no non-trivial divisor is found, return -1
}


void solve(){

    ll l,r;
    cin>>l>>r;

    if(l==r){
        ll gg = smallestNonTrivialDivisor(l);
        if(gg==-1){
            cout<<"-1"<<endl;
        }
        else{
            cout<<gg<<" "<<l-gg<<endl;
        }
        return;
    }

    for(ll i=l;i<=r;i++){
        if(i!=2 && i%2==0){
            cout<<"2 "<<i-2<<endl;
            return;
        }
    }

    cout<<"-1"<<endl;



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