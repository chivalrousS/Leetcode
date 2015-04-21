class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return binaryInsert(A,0,n-1,target);
    }
    
    int binaryInsert(int A[],int low,int high,int target)
    {
        if(low == high)
        {
            if (A[low] >= target) return low;
            else return low+1;
        }
        
        int mid = (low + high) / 2;
        
        if (A[mid] == target)
           return mid;
        else if (A[mid] > target)
           return binaryInsert(A,low,mid,target);
        else return binaryInsert(A,mid+1,high,target);
    }
};