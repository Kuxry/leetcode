#include <vector>
#include <algorithm>

using namespace std;


// 455. 分发饼干
// 贪心算法

// 思路：
// 1. 对胃口和饼干进行排序
// 2. 遍历饼干，如果饼干满足胃口，则计数器加1
// 3. 返回计数器

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index = 0;
        for(int i = 0; i < s.size(); i++) { // 饼干
            if(index < g.size() && g[index] <= s[i]){ // 胃口
                index++;
            }
        }
        return index;
    }
};