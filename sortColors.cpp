class Solution {
public:
    void sortColors(int A[], int n) {
    int i=0,j=n;
	for(int k=0;k<j;++k)
	{
		if(A[k] == 0)
			swap(A[i++],A[k]);
		else if(A[k] == 2)
			swap(A[--j],A[k--]);
	}
    }
};