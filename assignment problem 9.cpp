#include<bits/stdc++.h>
using namespace std;
int diff(vector<int>a , int n){
	sort(a.begin(),a.end());
	return a[n-1]-a[0];
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<diff(a,n)<<endl;
}
