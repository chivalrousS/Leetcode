/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
public:
    int totalNQueens(int n) {
        this->count = 0;
        this->columns = vector<int>(n,0);
        this->main_diag = vector<int>(2*n,0);
        this->anti_diag = vector<int>(2*n,0);

        vector<int> C(n,0);
        dfs(C,0);
        return this->count;
    }
private:
    private:
    int count;
    vector<int> columns;
    vector<int> main_diag;
    vector<int> anti_diag;

    void dfs(vector<int> &C,int row)
    {
        const int N = C.size();
        if(row == N)
        {
            ++this->count;
            return;
        }

        for(int j = 0;j<N;++j)
        {
            const bool flag = columns[j] == 0&&main_diag[row+j] == 0&&anti_diag[row-j+N] == 0;
            if(!flag)
                continue;
            C[row] = j;
            columns[j] = main_diag[row+j]=anti_diag[row-j+N] = 1;
            dfs(C,row+1);
            columns[j] = main_diag[row+j] = anti_diag[row-j+N] = 0;
        }
    }

};
