//和permutation类似，使用hash去重即可
class Solution {
public:
    void permuteUnique(vector<int>& nums, int index, vector<int> &vi, vector<vector<int>>& result) {
        if(index==nums.size()) {
            result.push_back(vi);
            return;
        }
        
        unordered_set<int> s; //去重
        for(int i=index;i<nums.size();i++) {
            if(s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
                swap(nums[index],nums[i]);
                vi.push_back(nums[index]);
                permuteUnique(nums,index+1,vi,result);
                vi.pop_back();
                swap(nums[index],nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> vi;
        if(nums.size() == 0)
            return result;
        permuteUnique(nums,0,vi,result);
        return result;
    }
};
