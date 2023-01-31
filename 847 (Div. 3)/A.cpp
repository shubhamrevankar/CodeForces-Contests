#include <bits/stdc++.h>
using namespace std;
#define ll long long




void solve(){

    string pi = "314159265358979323846264338327";

    string s;
    cin>>s;

    int res=0;

    int n = s.length();

    for(int i=0;i<n;i++){
        if(s[i]==pi[i]) res++;
        else break;
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