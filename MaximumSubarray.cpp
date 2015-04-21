class Solution {
public:
    int maxSubArray(int A[], int n) {
	int ans=0,maxn=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(ans<0) ans=0;
		ans +=A[i];
		maxn=max(maxn,ans);
	}
	return maxn;
    }
};