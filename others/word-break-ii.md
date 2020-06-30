```cpp
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {

        map<string, vector<string>> cache;
        return helper(s, wordDict, cache);
    }

    vector<string> helper(string s, vector<string> &dict, map<string, vector<string>> &cache)
    {
        if (cache.count(s))
        {
            return cache[s];
        }

        vector<string> res;

        if (s.length() == 0)
        {
            res.emplace_back("");
            return res;
        }

        for (auto word : dict)
        {
            if (s.rfind(word, 0) == 0)
            {
                string str = s.substr(word.length(), s.length());
                vector<string> subStrings = helper(str, dict, cache);
                for (auto subStr : subStrings)
                {
                    string space = subStr.length() == 0 ? "" : " ";
                    res.emplace_back(word + space + subStr);
                }
            }
        }

        cache[s] = res;
        return res;
    }
};
```