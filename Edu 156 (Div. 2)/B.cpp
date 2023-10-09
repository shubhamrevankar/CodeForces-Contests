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


double distance(int x1, int y1, int x2, int y2) 
{ 
    // Calculating distance 
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0); 
} 

void solve(){

    ll px,py,ax,ay,bx,by;
    cin>>px>>py>>ax>>ay>>bx>>by;

    double AO = distance(ax,ay,0,0);
    double BO = distance(bx,by,0,0);
    double AP = distance(ax,ay,px,py);
    double BP = distance(bx,by,px,py);

    double touch = distance(ax,ay,bx,by)/2;

    double d1 = max(AO,AP);
    double d2 = max(BO,BP);
    double d3 = max(max(AO,BP),touch);
    double d4 = max(max(BO,AP),touch);


    double res = min(min(d1,d2),min(d3,d4));

    printf("%0.6f",res);
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