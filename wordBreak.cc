//dp的题目一般是需要扫描一遍，当前的状态和前面的状态有关
//状态的设计最重要，这个需要经验
//dp也类似一个状态机，只是这个状态机比较复杂，一般可以形成一个一维或者多维DAG
//对于本题，v[i]表示s[0...i-1]是否可以word break
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> v(s.size()+1,false);
        v[0]=true;
        for(int i=1;i<v.size();i++) {
            for(int j=0;j<i;j++) {
                if(v[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    v[i]=true;
                    break;
                }
            }
        }
        return v[s.size()];
    }
};
