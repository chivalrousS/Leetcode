class Solution {
public:
    int singleNumber(int A[], int n) {
        int i,sum=0;
		for( i=0;i<=n-1;i++)
		{
			sum=sum^A[i];
		}
		return sum;
        
    }
};