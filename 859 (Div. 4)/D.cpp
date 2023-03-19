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

    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    if(a[0]%2==0){
        a[0]=0;
    }
    else{
        a[0]=1;
    }

    for(int i=1;i<n;i++){
        if(a[i]%2==0){
            a[i] = a[i-1];
        }
        else{
            a[i] = (a[i-1]+1)%2;
        }
    }

    vector<int> ans;

    while(q--){
        int flag;
        ll l,r,k;
        cin>>l>>r>>k;
        l--;r--;
        if(l==0){
            if(a[r]==0){
                if(((r-l+1)*k)%2==0){
                    flag=a[n-1];
                }
                else{
                    flag=(a[n-1]+1)%2;
                }
            }
            else{
                if(((r-l+1)*k)%2==1){
                    flag=a[n-1];
                }
                else{
                    flag=(a[n-1]+1)%2;
                }
            }
        }
        else if(a[l-1]==a[r]){
            if(((r-l+1)*k)%2==0){
                flag=a[n-1];
            }
            else{
                flag=(a[n-1]+1)%2;
            }
        }
        else{
            if(((r-l+1)*k)%2==1){
                flag=a[n-1];
            }
            else{
                flag=(a[n-1]+1)%2;
            }
        }
        ans.push_back(flag);
    }

    for(auto x:ans){
        if(x==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }




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