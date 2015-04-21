class Solution {
public:
    int search(int A[], int n, int target) {
        int first = 0;
        int end = n;
        while(first != end)
        {
            int mid = first +(end - first)/2;
            if(A[mid] == target)
              return mid;
            if(A[first] <= A[mid])
            {
                if(A[first]<= target && target<A[mid])
                   end = mid;
                else
                   first = mid +1;
            }
            else
            {
                if(A[mid]<target &&target<=A[end-1])
                   first = mid +1;
                else
                   end = mid;
            }
        }
        return -1;
        
    }
};