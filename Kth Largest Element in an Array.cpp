// Kth Largest Element in an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0, R = nums.size() - 1;
          while (L < R) {
              int left = L, right = R;
              int key = nums[left];
              while (left < right) {
                  while (left < right && nums[right] < key) --right;
                 nums[left] = nums[right];
                 while (left < right && nums[left] >= key) ++left;
                 nums[right] = nums[left];
             }
             nums[left] = key;
             if (left == k - 1) return nums[k - 1];
             else if (left > k - 1) R = left - 1;
             else L = left + 1;
         }
        return nums[k - 1];
    }
};