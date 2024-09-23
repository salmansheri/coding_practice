// MajorityElement.cpp
#include <algorithm>
#include <iostream> // standard input output library
#include <vector>   // importing vector
using namespace std;

// Solution
class Solution {
public:
  // Solving using brute force
  // Time Complexity O(n2)
  int bruteForce(vector<int> &nums) {
    int n = nums.size();
    /*
     * Traverse the array using foreach loop
     * assign freq = 0
     * again traverse the array using foreach loop
     * check if j is equal to i
     * true means increment the freq
     * check if freq is greater than n / 2
     *  true means return i
     *
     * */
    for (int i : nums) {
      int freq = 0;
      for (int j : nums) {
        if (j == i) {
          freq++;
        }
      }
      if (freq > n / 2) {
        return i;
      }
    }
    return -1;
  }
  // optimized version using sorting
  int withSorting(vector<int> &nums) {
    int n = nums.size();
    // sorting
    sort(nums.begin(), nums.end());

    // Frequence count
    int freq = 1, ans = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1]) {
        freq++;
      } else {
        freq = 1;
        ans = nums[i];
      }
    }
  }
};
// main function
int main() {
  Solution solution;
  vector<int> nums = {3, 2, 3};
  cout << solution.bruteForce(nums);
}
