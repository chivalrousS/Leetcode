/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    const vector<string> key{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits == "")
           return results;
        string cur_re("");
        dfs(results, 0, cur_re, digits);
        return results;
    }

    void dfs(vector<string>& re, int cur_dep,string& cur_re, string digits)
    {
        static string tel_board[] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(cur_dep == digits.length()){
            re.push_back(cur_re);
            return;
        }
        string cur_str = tel_board[digits[cur_dep] - '0'];
        for (int i = 0; i < cur_str.length(); ++i)
        {
            cur_re.push_back(cur_str[i]);
            dfs(re, cur_dep + 1, cur_re, digits);
            cur_re.pop_back();
        }

    }
};
