/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    void comb(int n, int index, int k, vector<vector<int>> &res, vector<int> &path)
    {
        if(path.size() == k){res.push_back(path);return;}
        for(int i = index+1; i <=n; i++)
        {
            path.push_back(i);
            comb(n,i,k,res,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<k || n<1 || k<1)return res;
        vector<int> path;
        for(int i =1; i <= n; i++)
        {
            path.push_back(i);
            comb(n,i,k,res,path);
            path.pop_back();
        }

    }
};
