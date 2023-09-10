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
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    vector<ll> c(n);
    for(auto &x:c) cin>>x;


    vector<ll> ind(n,0);
    for(int i=0;i<n;i++){
        ind[a[i]]++;
    }

    ll count=0;
    ll res=0;
    vector<ll> ans;
    bool loopstart = false;

    while(count < n){

        int k=0;
        if(!loopstart){
            for(int i=0;i<n;i++){
                if(ind[i]==0){
                    int j=i;
                    while(ind[j]==0){
                        ans.push_back(j+1);
                        ind[j]=-1;
                        ind[a[j]]--;
                        res += 2*c[j];
                        k++;
                        count++;
                        j=a[j];
                    }
                }
            }
        }
        if(k==0){
            loopstart=true;
            ll h=0;
            while(h<n && (ind[h]==0 || ind[h]==-1)) h++;
            if(h==n) break;
            ll mn = h;
            ll inh = h;
            res += 2*c[h];
            ind[h]=-1;
            h = a[h];
            count++;
            while(h!=inh){
                // res += 2*c[h];
                if(c[mn]>c[h]) mn = h;
                ind[h]=-1;
                h = a[h];
                count++;
            }
            ll mninit = mn;
            mn = a[mn];

            while(mn!=mninit){
                ans.push_back(mn+1);
                mn = a[mn];
            }
            ans.push_back(mn+1);

            // res -= mn;
        }

    }

    for(auto x:ans){
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