#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
vector<int> rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) {
        return nums; 
    }
    int cycles = gcd(n, k);
    for (int i = 0; i < cycles; ++i) {
        int start = i; 
        int current = start; 
        int prev = nums[start]; 
        while (true) {
          
            int next_idx = (current + k) % n;
            int temp = nums[next_idx];
            nums[next_idx] = prev;
            prev = temp;
            current = next_idx;
            if (current == start) {
                break;
            }
        }
    }

    return nums;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
    	cin>>nums[i];
	}
    vector<int> rotated_nums = rotate(nums, k);
    for (int i=0;i<n;i++) {
        cout << rotated_nums[i] << " ";
    }
    return 0;
}

