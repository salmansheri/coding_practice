#include <iostream>
#include <vector>
using namespace std;

// solution class
class Solution {
public:
  // printing pairs of the array
  void printPairs(vector<int> &nums) {
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
  // pairSum using brute force
  // Time Complexity O(n2)
  vector<int> pairSum(vector<int> &nums, int target) {
    // getting the size of the array
    int n = nums.size();
    // initializing a vector
    vector<int> ans;

    // traversing through the array
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        /*
         * if the sum equal to target push the index to the answer array
         *              0  1   2   3
         *  eg: nums = [2, 7, 11, 15]
         *    target = 9
         *    0   1
         *    2 + 7 = 9
         *    return [0, 1]
         */
        if (nums[i] + nums[j] == target) {
          ans.push_back(i);
          ans.push_back(j);
          return ans;
        }
      }
    }
    return ans;
  }
  // Solving with Two Pointer approach (optimized)
  // Time Complexity = O(n)
  vector<int> twoPointer(vector<int> &nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    /*
     * use while loop range of start < end
     * assign pairSum = nums[start] + nums[end]
     * if pairSum is greater than than target decrement the end
     * else if pairSum is lesser than target
     *       increment start
     * else
     *        push start and end to ans array
     *        return ans array
     *
     */

    while (start < end) {
      int pairSum = nums[start] + nums[end];
      if (pairSum > target) {
        end--;
      } else if (pairSum < target) {
        start++;
      } else {
        ans.push_back(start);
        ans.push_back(end);
        return ans;
      }
    }

    return ans;
  }
};
// main function
int main() {
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  for (int num : solution.twoPointer(nums, target)) {
    cout << num << ", ";
  }
  return 0;
}
