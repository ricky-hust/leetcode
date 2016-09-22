//遍历+简单的状态机
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        int pos=1;
        int flag=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == nums[i-1]) {
                if(flag==1) {
                    continue;
                } else {
                    nums[pos++]=nums[i];
                    flag=1;
                }
            } else {
                flag=0;
                nums[pos++]=nums[i];
            }
        }
        return pos;
    }
};
