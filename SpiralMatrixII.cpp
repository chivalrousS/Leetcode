/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int begin = 0,end = n - 1,num = 1;
        while(begin < end)
        {
            for(int j = begin; j < end; ++j)
                matrix[begin][j] = num++;
            for(int i = begin; i < end; ++i)
                matrix[i][end] = num++;
            for(int j = end;j > begin; --j)
                matrix[end][j] = num++;
            for(int i = end;i > begin; --i)
                matrix[i][begin] = num++;

            ++begin,--end;
        }

        if(begin == end)
            matrix[end][end] = num;

        return matrix;

    }
};
