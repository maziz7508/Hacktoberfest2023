// kandane's algorithm is used to find the maximum sum of the subarray
#include <iostream>
#include <vector>
using namespace std;

int kadanesAlgorithm(std::vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum =max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = kadanesAlgorithm(nums);
    std::cout << "Maximum subarray sum: " << maxSum << std::endl;

    return 0;
}
