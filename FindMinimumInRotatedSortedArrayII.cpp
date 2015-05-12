/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high)
        {
            if(nums[low] < nums[high])
                return nums[low];

            int mid = low + (high-low)/2;
            if(nums[low] == nums[mid])
            {
                if(low+1 == high)
                {
                    if(nums[low]>nums[high])
                        low = high;
                    break;
                }
                else
                    low ++;
            }
            else if(nums[low] < nums[mid])
                low = mid;
            else
                high = mid;
        }
        return nums[low];

    }
};

