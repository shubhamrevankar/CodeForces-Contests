#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    if(n==1){
        cout<<"0"<<endl;
        return;
    }

    ll res=0;

    // ll trend=1;

    if(a[0]>a[1]){
        res++;
        // trend=-1;
    }
    // ll c=1;

    for(ll i=1;i<n;i++){



        






        // if((a[i]==a[i-1])||(((i+1)<n) && a[i]>a[i-1] && a[i]>a[i+1])) res++;
        // if((trend && a[i-1]>a[i]) || (!trend && a[i-1]>a[i]) || (a[i]==a[i-1]))

        // if(trend!=-1 && a[i-1]>a[i]){
        //     if(c!=0) res++;
        //     c=0;
        //     trend=-1;
        // }
        // else if(trend!=1 && a[i-1]<a[i]){
        //     if(c!=0) res++;
        //     c=0;
        //     trend=1;
        // }
        // else if(trend!=0 && a[i]==a[i-1]){
        //     if(c!=0) res++;
        //     c=0;
        //     trend=0;
        // }
        // else{
        //     c++;
        // }

        // if(a[i-1]<a[i]) trend=1;
        // else if(a[i-1]==a[i]) res++, trend=0;
        // else{
        //     c++;
        //     if(trend!=-1){
        //         trend=-1;
        //         c=0;
        //     }
        //     if(c==1) res++;
            
        // }
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