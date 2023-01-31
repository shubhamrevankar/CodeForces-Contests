#include <bits/stdc++.h>
using namespace std;
#define ll long long




void solve(){

    ll n;
    cin>>n;
    
    int a[n][n-1];

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin>>a[i][j];
        }
    }
    
    int idx=0;
    if(a[0][0]!=a[1][0] && a[0][0]!=a[n-1][0]){
        idx=0;
    }
    else{
        for(int i=1;i<n;i++){
            if(a[i][0]!=a[i-1][0]){
                idx=i;
                break;
            }
        }
    }

    if(idx==0){
        cout<<a[1][0]<<" ";
        for(int i=0;i<n-1;i++) cout<<a[idx][i]<<" ";
        cout<<endl;
    }
    else{
        cout<<a[0][0]<<" ";
        for(int i=0;i<n-1;i++) cout<<a[idx][i]<<" ";
        cout<<endl;
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