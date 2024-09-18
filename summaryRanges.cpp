#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> res;
    int n = nums.size();
    int i = 0;

    while (i < n) {
      int start = nums[i];
      while (i < n - 1 && nums[i] + 1 == nums[i + 1]) {
        i++;
      }
      if (start != nums[i]) {
        res.push_back(to_string(start) + "->" + to_string(nums[i]));
      } else {
        res.push_back(to_string(nums[i]));
      }
      i++;
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 5, 6};
  for (string num : solution.summaryRanges(nums)) {
    cout << num << " ";
  }
}
