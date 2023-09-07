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
    string s;
    cin>>s;
    n = s.length();

    int status = 0; // -1 => unsorted , 0 => neutral , 1 => sorted

    int c=0;

    for(int i=0;i<n;i++){
        if(s[i]=='-'){
            c--;
            if(c<=1) status = 0;
        }
        else if(s[i] == '+'){
            c++;
        }
        else if(s[i]=='1'){
            if(status==-1){
                cout<<"NO"<<endl;
                return;
            }
            if(c>1) status = 1;
        }
        else{
            if(status==1 || c<=1){
                cout<<"NO"<<endl;
                return;
            }
            status = -1;
        }
    }

    cout<<"YES"<<endl;




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