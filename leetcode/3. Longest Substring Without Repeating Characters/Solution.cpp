// Solution slowly
class Solution {
public:
    typedef std::set<char> StringSet;
    
    int lengthOfLongestSubstring(string s) {
        
        int maxLength = 0;
        StringSet strSet;
        std::deque<StringSet::iterator> itQueue;
        
        for (int i=0; i < s.size(); ++i)
        {
            StringSet::iterator it = strSet.find(s[i]);
            if (it != strSet.end())
            {
                while(1)
                {
                    StringSet::iterator iter = itQueue.front();
                    itQueue.pop_front();
                    char val = *iter;
                    strSet.erase(iter);
                    if (val == s[i])
                        break;
                }
            }
            std::pair<StringSet::iterator,bool> tmp = strSet.insert(s[i]);
            itQueue.push_back(tmp.first);
            if (strSet.size() > maxLength)
                maxLength = strSet.size();
        }
        
        return maxLength;
    }
};


// Solution fast
class Solution {
public: 
    int lengthOfLongestSubstring(string s) {
        
        int charLastPositionInS[128];
        
        // memset the val to -1
        std::memset(charLastPositionInS, 0xFF, sizeof charLastPositionInS);
        
        int subStrStartPositionInS = 0;
        int maxLength = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // Is current char in the sub string
            if (charLastPositionInS[s[i]] >= subStrStartPositionInS)
                subStrStartPositionInS = charLastPositionInS[s[i]] + 1;
            
            charLastPositionInS[s[i]] = i;
            
            if (maxLength < i - subStrStartPositionInS + 1)
                maxLength = i - subStrStartPositionInS + 1;
        }
        return maxLength;
    }
};
