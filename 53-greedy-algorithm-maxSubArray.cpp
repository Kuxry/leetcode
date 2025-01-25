#include <vector>

using namespace std;


// 思路：
// 1. 遍历数组，计算当前累加和
// 2. 如果当前累加和大于结果，则更新结果
// 3. 如果当前累加和小于等于0，则重置累加和
// 4. 返回结果

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};