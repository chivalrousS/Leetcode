class Solution {
public:
    bool search(int A[], int n, int target) {
    int first = 0,last = n-1;
    while(first <= last)
    {   
      int mid = first + (last - first)/2;
      if(A[mid] == target)
        return true;
      if(A[first] < A[mid])
      {   
        if(A[first] <= target && target<A[mid])
          last = mid -1;
        else
          first = mid+1;
      }   
      else if(A[first] > A[mid])
      {   
        if(A[mid] < target && target <= A[last])
          first = mid+1;
        else
          last = mid-1;
      }   
      else
         first++;
    }   
    return false;
    }
};