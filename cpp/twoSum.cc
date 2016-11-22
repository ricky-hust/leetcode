class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++) {
            int t=target-nums[i];
            if(m.find(t) == m.end()) {
                m[nums[i]]=i;
            } else {
                result.push_back(m[t]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};
