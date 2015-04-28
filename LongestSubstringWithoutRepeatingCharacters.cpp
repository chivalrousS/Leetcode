/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int locs[256];
        memset(locs, -1, sizeof(locs));

        int idx = -1, max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (locs[s[i]] > idx)
            {
                idx = locs[s[i]];
            }

            if (i - idx > max)
            {
                max = i - idx;
            }

            locs[s[i]] = i;
        }
        return max;

    }
};
