#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    ll n,m,k;
    cin>>n>>m>>k;

    if(k>3){
        cout<<"0"<<endl;
        return;
    }

    if(k==1){
        cout<<"1"<<endl;
        return;
    }

    ll div = ((m/n)-1);

    if(k==2){
        if(m<n){
            cout<<m+div+1<<endl;
        }
        else{
            cout<<n+div<<endl;
        }
        return;
    }

    if(m<n){
        cout<<"0"<<endl;
        return;
    }

    cout<<m-n-div<<endl;

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