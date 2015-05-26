/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;

        result.push_back(vector<int> (1,1));

        for(int i = 2;i <= numRows; ++i)
        {
            vector<int> current(i,1);
            const vector<int> &prev = result[i-2];

            for(int j = 1;j < i - 1;++j)
                current[j] = prev[j - 1] + prev[j];
            result.push_back(current);
        }
        return result;
    }
};
