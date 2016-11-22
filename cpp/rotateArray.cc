class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<2 || k<=0)
            return;
        int len=nums.size();
        k=k%len;
        while(k>0) {
            int temp=nums.back();nums.pop_back();
            nums.insert(nums.begin(),temp);
            k--;
        }
    }
};
