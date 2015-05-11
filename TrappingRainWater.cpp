/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        vector<int> left(n),right(n);
        for(int i = 0; i < n;++i)
            left[i] = i?max(left[i-1],height[i]):height[i];
        for(int i = n-1;i >= 0;--i)
            right[i] = (i == n-1)?height[i]:max(right[i+1],height[i]);
        for(int i = 0;i < n;++i)
            result += min(left[i],right[i]) - height[i];
        return result;
    }
};
