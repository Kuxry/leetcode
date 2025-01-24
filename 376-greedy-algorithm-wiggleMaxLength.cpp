#include <vector>
using namespace std;


// 思路：
// 1. 遍历数组，计算当前差值和前一对差值
// 2. 如果当前差值和前一对差值的符号相反，则计数器加1
// 3. 返回计数器
// 4. 特殊情况：如果数组长度小于等于1，则返回数组长度


// 版本一
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
            }
            preDiff = curDiff;
        }
        return result;
    }
};