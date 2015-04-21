class Solution {
public:
    int reverse(int x) {
        int rev=0;
	int count=1;
	bool flag=false;
	if(x<0)
	{
		flag=true;
		x=-x;
	}
	queue<int> Q;
	while(x>0)
	{
		int res=x%10;
		Q.push(res);

		x/=10;
		count*=10;
	}
	while(!Q.empty())
	{
		int res=Q.front();
		Q.pop();

		count/=10;
		rev=rev+res*count;
	}
	return flag?-rev:rev;
        
    }
};