//线性算法解决以为模式识别问题
//这里引入了maxsofar和maxendinghere这两个状态变量让问题可以线性解决
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar=INT_MIN,maxendinghere=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            maxendinghere=(maxendinghere>0?maxendinghere+nums[i]:nums[i]);
            maxsofar=(maxsofar>maxendinghere?maxsofar:maxendinghere);
        }
        return maxsofar;
    }
};
