/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = -1;

        int i = 0;
        int j = height.size() - 1;
        int m;
        while (i < j) {
             m = min(height[i], height[j]);
             res = max(res, (j-i)*m);
             if (height[i] == m) {
                 i++;
             }
             else {
                 j--;
             }
        }
        return res;
    }
};
