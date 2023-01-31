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






void primeFactors(int n,unordered_map<ll,ll,custom_hash> &m)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
}






static bool comp(const vector<ll> &a,const vector<ll> &b){
    return a[1]<=b[1];
}




void solve(){

    ll n;
    cin>>n;

    unordered_map<ll,ll,custom_hash> m;

    primeFactors(n,m);

    // for(auto x:m){
    //     cout<<x.first<<" "<<x.second<<endl;
    // } 

    vector<vector<ll>> v;
    for(auto x:m){
        v.push_back({x.first,x.second});
    }

    sort(v.begin(),v.end(),comp);

    // for(auto x:v){
    //     cout<<x[0]<<" "<<x[1]<<endl;
    // } 

    ll res = 0;

    for(ll i=0;i<v.size();i++){
        if(v[i][1]>0){
            ll tmp =1;
            ll fre = v[i][1];
            v[i][1] =0;
            tmp *= fre;
            tmp *= v[i][0];
            for(ll j=i+1;j<v.size();j++){
                v[j][1] -= fre;
                tmp *= v[j][0];
            }
            res += tmp;
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