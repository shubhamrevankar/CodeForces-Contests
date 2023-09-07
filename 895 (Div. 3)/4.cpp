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


 
// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


void solve(){

    ll n,x,y;
    cin>>n>>x>>y;

    ll res = 0;

    // ll p=1;
    // ll q=1;

    // for(ll i=1;i<=n;i++){
    //     if((i%y==0) && (i%x!=0)){
    //         res -= p;
    //         p++;
    //     }
    //     if((i%x==0) && (i%y!=0)){
    //         res += q;
    //         q++;
    //     }
    // }

    ll both = n/(lcm(x,y));

    ll first = n/x - both;
    ll second = n/y - both;

    ll g = n-first;

    res += (first*(first+1))/2 + g*first;

    res -= (second*(second+1))/2;


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