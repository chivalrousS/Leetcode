class Solution {
public:
    int climbStairs(int n) {
	int a[10001]={0};
	int i;
	a[0]=0;
	a[1]=1;
	a[2]=2;
	if(n>10000)
		return 0;
	for(i=3;i<=n;++i)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
    }
};