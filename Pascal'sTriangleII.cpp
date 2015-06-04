/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex<0)  return res;
        res.resize(rowIndex+1,0);
        res[0]=1;
        for(int k=1;k<rowIndex+1;k++){
            for(int j=k;j>0;j--){
                if(j==k)
                    res[j]=1;
                else{
                    res[j]=res[j]+res[j-1];
                }
            }
        }
        return res;
    }
};
