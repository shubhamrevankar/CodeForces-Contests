#include <bits/stdc++.h>
using namespace std;





void solve(){



long long n;
cin>>n;


long long arr[n];
vector<long long> odd;
vector<long long> even;
for(long long i=0;i<n;i++){
    long long tm;
    cin>>tm;
    if(tm%2==1){ 
        arr[i] = 1;
        odd.push_back(i+1);
    }
    else{
        arr[i] = 0;
        even.push_back(i+1);
    }
}

if(n==3){
    if((arr[0]+arr[1]+arr[2])%2==1){
        cout<<"YES"<<endl;
        cout<<"1 2 3"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}

if(odd.size()==0){
    cout<<"NO"<<endl;
    return;
}

if(odd.size()>=3){
    cout<<"YES"<<endl;
    cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2]<<endl;
    return;
}


vector<long long> res;

res.push_back(odd[0]);
res.push_back(even[0]);
res.push_back(even[1]);


cout<<"YES"<<endl;
cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;

}






int main() {
	long long t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
	return 0;
}