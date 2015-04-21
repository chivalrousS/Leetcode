class Solution {
public:
    int numTrees(int n) {
        if(n < 0)
          return 0;
        long long dividend = 1,divider =1;
        for(int i=2*n;i>=(n+2);--i)
          dividend *= i;
        for(int j=n;j>=2;--j)
          divider *= j;
        return (int)(dividend/divider);
    }
};