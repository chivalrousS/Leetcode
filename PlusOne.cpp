/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int incr = 1;
        for(auto d = digits.rbegin(); d != digits.rend(); ++d)
        {
            *d += incr;
            if (*d >= 10)
            {
                *d -= 10;
                incr = 1;
            }
            else
                incr = 0;
        }
        if (incr)
            digits.insert(begin(digits), 1);

        return digits;
    }
};
