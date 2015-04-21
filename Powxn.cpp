class Solution {
public:
    bool Invalid_input = false;
    bool equal(double x,double y)
    {
	if((x - y <0.0000001)&&(x-y>-0.0000001))
		return true;
	else
		return false;
    }
    double computepow(double x,int y)
    {
	if(y == 0)
		return 1.0;
	if(y == 1)
		return x;
	if(equal(x,1.0))
	    return 1.0;

	double result = computepow(x,y>>1);
	result *= result;
	if(y & (0x1) == 1)
		result *= x;
	return result;
    }
    double pow(double x, int n)
    {
	if(equal(x,0.0)&& n<0)
	{
		Invalid_input = true;
		return 0.0;
	}
	unsigned int index = (unsigned int) n;
	if(n < 0)
	{   if(n == -2147483648)
	{
	    return  1/(x * pow(x,-(n+1)));
	}
		index = (unsigned int )(-n);
	}
	double result = computepow(x,index);
	if(n < 0)
		result = 1.0/result;
	return result;
    }
};