#include <bits/stdc++.h>
using namespace std;

int longe(string s){
   
    if (s.length() == 0)
        return 0;

    if (s.length() == 1)
        return 1;

    int maxLength = 0;
    vector<bool> a(256,false); 

    int left = 0, right = 0;
    while (right < s.length()) {

        if (a[s[right]] == true) {

            while (a[s[right]] == true) {

                a[s[left]] = false;
                left++;
            }
        }

        a[s[right]] = true;

        maxLength = max(maxLength, (right - left + 1));
        right++;
    }
    return maxLength;
}


int main()
{
    string str;
    cin>>str;
    int len = longe(str);
    cout <<len<<endl;
    return 0;
}

