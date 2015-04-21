class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int counter = 0;
        for(int i = 0;i < n;++i)
        {
            if(counter == 0 ||A[i] != A[counter - 1])
            {
                A[counter] = A[i];
                ++counter;
            }
        }
     return counter;
    }
};