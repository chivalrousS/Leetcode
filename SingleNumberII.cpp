class Solution {
public:
    int singleNumber(int A[], int n) 
    {
	int one=0,two=0;
	for(int i=0;i<n;i++)
	{
		two |=A[i]&one; //two ����ֵ
		one ^=A[i]; //one ������
		int t=one & two; //�����ε�ʱ��one ��two �������˸�λ��ֵ
		one &=~t;//��0����3�εĸ�λ��ֵ
		two &=~t;
	}
	return one;
}
};