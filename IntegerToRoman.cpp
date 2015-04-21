class Solution {
public:
    string intToRoman(int num) {
        const int Integer[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const string Roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string romans;
        for(size_t i=0;num > 0;++i)
        {
            int count = num / Integer[i];
            num %= Integer[i];
            for(;count > 0;--count)
               romans += Roman[i];
        }
        
        return romans;
        
    }
};