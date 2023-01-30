#include <bits/stdc++.h>
using namespace std;

int fun(int arr[],int n,int count){
    
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    if(sum%2==0) return count;
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            int temp=arr[i];
            arr[i] /=2;
            res = min(res,fun(arr,n,count+1));
            arr[i]=temp;
        }
        
    }
    return res;
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int res = fun(arr,n,0);
	    cout<<res<<endl;
	}
	return 0;
}