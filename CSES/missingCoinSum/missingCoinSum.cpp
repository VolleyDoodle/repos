//basically this: https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> nums(n);
  
  for (int i = 0; i < n; i++){
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  long long smallestSum = 0;
  for (int x : nums){
    if (smallestSum + 1 < x){
      break;
    }
    smallestSum+=x;
  }
  cout << smallestSum + 1;
  
}