#include<bits/stdc++.h>
using namespace std;
bool alpha(string s){
	for(int i=0;i<s.length();i++){
		if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ){
            	continue;
			}
			else{
				return false;
			}
	}
	return true;
}
int main(){
	string s;
	cin>>s;
	cout<<alpha(s)<<endl;
}
