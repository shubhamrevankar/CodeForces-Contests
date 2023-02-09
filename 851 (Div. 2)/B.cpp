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
    vector<ll> a;
    ll n1=n;
    while(n1!=0){
        a.push_back(n1%10);
        n1 /= 10;
    }
    ll size = a.size();
    vector<ll> x(size);
    vector<ll> y(size);

    ll c=0;
    for(ll i=0;i<size;i++){
        if(a[i]%2==0){
            x[i] = y[i] = (a[i]/2);
        }
        else{
            if(c%2==0){
                x[i] = y[i] = (a[i]/2);
                x[i]++;
            }
            else{
                x[i] = y[i] = (a[i]/2);
                y[i]++;
            }
            c++;
        }
    }

    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());


    ll X=0,Y=0;

    for(ll i=0;i<size;i++){
        X = 10*X + x[i];
        Y = 10*Y + y[i];
    }

    cout<<X<<" "<<Y<<endl;




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