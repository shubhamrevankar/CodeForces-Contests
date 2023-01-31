#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    n--;
	    int arr[n];
	    int first;
	    cin>>first;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++){
	        if(first<arr[i]){
	            if((first+arr[i])%2==1){
	                int t = (first+arr[i])/2 +1;
    	            arr[i] = (first+arr[i])/2;
    	            first = t;
	            }
	            else{
	                int t = (first+arr[i])/2;
    	            arr[i] = (first+arr[i])/2;
    	            first = t;
	            }
	        }
	    }
	    cout<<first<<endl;
	}
	return 0;
}