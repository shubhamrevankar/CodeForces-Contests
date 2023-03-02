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


void fun(int i,int n,vector<int> &a,int sum, stack<int> &s, int &res){

    if(i==n){
        res = max(res,sum);
        return;
    }

    if(a[i]!=0){

        s.push(a[i]);
        fun(i+1,n,a,sum,s,res);
        if(!s.empty())
            s.pop();
        fun(i+1,n,a,sum,s,res);

    }
    else{
        int t = 0;
        if(!s.empty()){
            t += s.top();
            s.pop();
        }
        sum += t;
        fun(i+1,n,a,sum,s,res);
        if(t!=0){
            s.push(t);
        }

    }

}


void solve(){

    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;

    stack<int> s;
    int res=0;
    
    fun(0,n,a,0,s,res);

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