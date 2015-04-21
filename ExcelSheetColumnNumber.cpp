class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        int temp = 0;
        for(int i = 0; i<s.length();++i)
        {
            temp = s[i] - 'A' + 1;
            number = number * 26 + temp;
        }
        return number;
        
    }
};