#include <vector>
#include <algorithm>

using namespace std;









class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);

        int result = 1; // points 不为空至少需要一支箭
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {  // 气球i和气球i-1不挨着，注意这里不是>=
                result++; // 需要一支箭
            }
            else {  // 气球i和气球i-1挨着
                points[i][1] = min(points[i - 1][1], points[i][1]); // 更新重叠气球最小右边界
            }
        }
        return result;
    }
};

// Description: 452. 用最少数量的箭引爆气球
// 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
// 由于气球是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就可以确定一个气球了。
// 现在在二维空间中射箭，射中一个气球，气球会爆炸，如果射中多个气球，则用一支箭射中所有被射中的气球。
// 问最少需要射几支箭。 
