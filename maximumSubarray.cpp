#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // printing all sub arrays of the array
  void printSubarray(vector<int> &nums) {
    for (int start = 0; start < nums.size(); start++) {
      for (int end = 0; end < nums.size(); end++) {
        for (int i = start; i <= end; i++) {
          cout << nums[i];
        }
        cout << " ";
      }
      cout << endl;
    }
  }
  // Solving using Brute Form
  int bruteForce(vector<int> &nums) {
    int maxSum = INT_MIN;
    int n = nums.size();
    for (int start = 0; start < n; start++) {
      int currSum = 0;
      for (int end = start; end < n; end++) {
        currSum += nums[end];
        maxSum = max(currSum, maxSum);
      }
    }
    return maxSum;
  }

  // Solving using Kadane's Algorithm
  int kadanesAlgorithm(vector<int> &nums) {
    int currSum = 0, maxSum = INT_MIN;
    for (int num : nums) {
      currSum += num;
      maxSum = max(currSum, maxSum);
      // reset Current sum = 0
      if (currSum < 0) {
        currSum = 0;
      }
    }
    return maxSum;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4, 5};
  // solution.printSubarray(nums);
  cout << " The Max Subarray sum  = " << solution.bruteForce(nums) << endl;
  cout << " The Max Subarray sum  = " << solution.kadanesAlgorithm(nums)
       << endl;

  return 0;
}
