class Solution {
public:
    static bool comp(string &s, string &t) {
        return s+t > t+s;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for(int i=0;i<nums.size();i++) {
            vs.push_back(to_string(nums[i]));
        }
        
        sort(vs.begin(),vs.end(),comp);
        
        string result;
        for(int i=0;i<nums.size();i++) {
            result+=vs[i];
        }
        
        return result[0]=='0' ? "0" : result;
    }
};
