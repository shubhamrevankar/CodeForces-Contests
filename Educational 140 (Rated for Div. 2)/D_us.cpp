#include <bits/stdc++.h>
using namespace std;


int main() {
    
	    long long n;
	    cin>>n;
	    string s;
	    cin>>s;
	    long long ones=count(s.begin(), s.end(), '1'),zeros=count(s.begin(), s.end(), '0');
	   // for(auto x:s){
	   //     if(x=='0') zeros++;
	   //     else ones++;
	   // }
	    long long l=pow(2,ones),r=pow(2,n)-(pow(2,zeros)-1);
	    for(long long i=l;i<=r;i++){
	        cout<<i<<" ";
	    }cout<<endl;
	    
	return 0;
}