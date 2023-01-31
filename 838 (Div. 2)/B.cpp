#include <bits/stdc++.h>
using namespace std;

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
	    int maxsofar = arr[0];
	    vector<vector<int>> v;
	    vector<int> t;
	    for(int i=1;i<n;i++){
	        if(arr[i]<maxsofar){
	             t.push_back(i+1);
                t.push_back(maxsofar-arr[i]);
                v.push_back(t);
                t.clear();
                arr[i] = maxsofar;
	        }
	        else{
	            int d = arr[i]/maxsofar +1;
	            d = d*maxsofar;
	            int x = d-arr[i];
	            if(x!=0){
	                t.push_back(i+1);
	                t.push_back(x);
	                v.push_back(t);
	                t.clear();
	            }
	            maxsofar = arr[i] = d;
	        }
	    }
	    cout<<v.size()<<endl;
	    for(int i=0;i<v.size();i++){
	        cout<<v[i][0]<<" "<<v[i][1]<<endl;
	    }
	}
	return 0;
}