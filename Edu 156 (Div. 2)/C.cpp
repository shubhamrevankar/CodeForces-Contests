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

    ll n,k;
    string s;
    cin>>s;
    n = s.length();
    cin>>k;

    ll c=0;

    while(k>n){
        k-=n;
        n--;
        c++;
    }

    // string s1 = s;
    // sort(s1.begin(),s1.end());

    // vector<ll> count(27,0);

    // for(ll i=0;i<n;i++){
    //     count[s1[i]-'a']++;
    // }

    string res=s;

    n = s.length();

    // while (c>0)
    // {
    //     for (ll i = 0; i < res.length(); i++)
    //     {
    //         if(c>0 && (i==res.length()-1 || res[i]>res[i+1])){
    //             ll j=i;
    //             while(j>=0 && c>0 && res[j]>res[i+1]) j--, c--;
    //             res.erase(j+1,i-j);
    //             break;
    //         }
    //     }
    // }

    stack<char> st;
    st.push('a'-1);
    ll j=-1;

    for(ll i=0;i<n;i++){
        if(s[i]>st.top()){
            st.push(s[i]);
        }
        else{
            while(st.size()>1 && c>0 && s[i]<st.top()){
                st.pop();
                c--;
            }
            st.push(s[i]);
            if(c==0){
                j=i+1;
                break;
            }
        }
    }

    string ans="";

    while(st.size()>1){
        ans += (char)st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    
    if(j!=-1)
    ans = ans + res.substr(j);
    else
    ans = ans.substr(0,n-c);
    
    cout<<ans[k-1];


}




    // for(ll i=s.length()-1;i>=0;i--){
    //     if(count[s[i]-'a']>0){
    //         res += s[i];
    //         count[s[i]-'a']--;
    //     }
    // }
    // reverse(res.begin(),res.end());

    // cout<<res[k-1];


int main() {
	ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
	return 0;
}