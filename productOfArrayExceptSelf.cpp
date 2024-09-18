#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n);
    int leftProduct = 1;
    int rightProduct = 1;

    // Calculate left Poduct
    for (int i = 0; i < n; i++) {
      result[i] = leftProduct;
      leftProduct *= nums[i];
    }

    // Calculate right products and final result
    for (int i = n - 1; i >= 0; i--) {
      result[i] *= rightProduct;
      rightProduct *= nums[i];
    }
    return result;
  }
};
int main(void) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  for (int num : solution.productExceptSelf(nums)) {
    cout << num << " ";
  }
  return 0;
}
