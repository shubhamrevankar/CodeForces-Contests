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

    ll n,a,q;
    cin>>n>>a>>q;
    string s;
    cin>>s;

    if(a>=n){
        cout<<"YES"<<endl;
        return;
    }
    int y=0,inita=a;
    for(int i=0;i<q;i++){
        if(s[i]=='+'){
            y++;
            a++;
        }
        else{
            a--;
        }
        if(a>=n){
            cout<<"YES"<<endl;
            return;
        }
    }

    if(y+inita >=n ){
        cout<<"MAYBE"<<endl;
        return;
    }

    cout<<"NO"<<endl;




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