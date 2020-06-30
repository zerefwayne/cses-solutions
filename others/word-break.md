# Recursion from 0 TLE

```cpp
class Solution
{
public:
    bool wordBreakHelper(int start, int end, string &s, unordered_set<string> &dict)
    {
        if (end == s.length())
        {
            return false;
        }

        string str = s.substr(start, end - start + 1);

        if (dict.find(str) != dict.end())
        {

            if (end == s.length() - 1)
            {
                return true;
            }

            return wordBreakHelper(start, end + 1, s, dict) || wordBreakHelper(end + 1, end + 1, s, dict);
        }

        

        return wordBreakHelper(start, end + 1, s, dict);
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return wordBreakHelper(0, 0, s, dict);
    }
};
```

# Recursion from n-1 TLE

```cpp
class Solution
{
public:
    bool wordBreakHelper(int start, int end, string &s, unordered_set<string> &dict)
    {

        if (start == -1)
        {
            return false;
        }

        string str = s.substr(start, end - start + 1);

        if (dict.find(str) != dict.end())
        {

            if (start == 0)
            {
                return true;
            }

            return wordBreakHelper(start - 1, end, s, dict) || wordBreakHelper(start - 1, start - 1, s, dict);
        }

        return wordBreakHelper(start - 1, end, s, dict);
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.length();

        return wordBreakHelper(n - 1, n - 1, s, dict);
    }
};
```

# Substring Recursion from start TLE

```cpp
class Solution
{
public:
    bool helper(string &s, unordered_set<string> &dict)
    {
        if (s == "")
        {
            return true;
        }
        
        string str;

        for (int i = 1; i <= s.length(); i++)
        {
            str = s.substr(0, i);
            if (dict.find(str) != dict.end())
            {
                str = s.substr(i, s.length());
                if (helper(str, dict))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }
};
```


# Substring Memoized from start ACCEPTED

```cpp
class Solution
{
public:
    bool helper(string &s, unordered_set<string> &dict, map<string, bool> &cache)
    {

        if (s == "")
        {
            return true;
        }

        if (cache.find(s) != cache.end())
        {
            return cache[s];
        }

        string str;

        for (int i = 1; i <= s.length(); i++)
        {

            str = s.substr(0, i);

            if (dict.find(str) != dict.end())
            {

                string st = s.substr(i, s.length());

                if (helper(st, dict, cache))
                {
                    cache[st] = true;
                    return true;
                }
            }
        }
        cache[s] = false;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        map<string, bool> cache;

        return helper(s, dict, cache);
    }
};
```

# Dynamic Programming

```cpp
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.length();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int len = 1; len <= s.length(); len++)
        {

            for (int i = 0; i < len; i++)
            {

                if (dp[i] == true)
                {

                    string str = s.substr(i, len - i);

                    if (dict.find(str) != dict.end())
                    {

                        dp[len] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
```