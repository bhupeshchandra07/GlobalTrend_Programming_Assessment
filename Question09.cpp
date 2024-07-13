#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxDifference(std::vector<int>& nums) {
    int minElement = nums[0];
    int maxDiff = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
        maxDiff = std::max(maxDiff, nums[i] - minElement);
        minElement = std::min(minElement, nums[i]);
    }
    return maxDiff;
}

int main() {
    std::vector<int> nums = {2, 3, 10, 2, 4, 8, 1};
    std::cout << "Maximum difference between any two elements: " << maxDifference(nums) << std::endl;
    return 0;
}
