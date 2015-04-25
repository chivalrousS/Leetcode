/*
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord.size() != endWord.size()) return 0;
        if(beginWord.empty() || endWord.empty()) return 0;

        queue <string> path;
        path.push(beginWord);
        int level = 1;
        int count = 1;
        wordDict.erase(beginWord);
        while(wordDict.size() > 0 && !path.empty())
        {
            string curword = path.front();
            path.pop();
            --count;
            for(int i = 0;i<curword.size();++i)
            {
                string tmp = curword;
                for(char j = 'a';j <= 'z';++j)
                {
                    if(tmp[i] == j)
                        continue;
                    tmp[i] = j;
                    if(tmp == endWord) return level+1;
                    if(wordDict.find(tmp) != wordDict.end())
                        path.push(tmp);
                    wordDict.erase(tmp);
                }
            }
            if(count == 0)
            {
                count = path.size();
                ++level;
            }
        }
        return 0;
    }
};
