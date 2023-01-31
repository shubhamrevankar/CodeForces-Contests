#include <bits/stdc++.h>
using namespace std;
#define ll long long




void solve(){

    int n,s,r;
    cin>>n>>s>>r;


    int picked = s-r;

    vector<int> v(n,0);

    int each = r/(n-1);
    int rem = r%(n-1);


    for(int i=0;i<n-1;i++){

        v[i] += each;
        if(rem>0){
            v[i]++;
            rem--;
        }

    }
    v[n-1] = picked;
    
    for(auto x:v) cout<<x<<" ";
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