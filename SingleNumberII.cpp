class Solution {
public:
    int singleNumber(int A[], int n) 
    {
	int one=0,two=0;
	for(int i=0;i<n;i++)
	{
		two |=A[i]&one; //two 积累值
		one ^=A[i]; //one 不断求反
		int t=one & two; //第三次的时候one 和two 都保留了该位的值
		one &=~t;//清0出现3次的该位的值
		two &=~t;
	}
	return one;
}
};