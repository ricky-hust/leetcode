//这题基本思路为dfs，可以画二叉树来体会整个过程的流程
//仔细体会下面两种做法的区别
//在leetcode中第二种做法更快
class Solution {
public:
    void dfs(vector<int>& nums,int index,vector<int>& seq,vector<vector<int>>& result) {
        if(index >= nums.size()) {
            result.push_back(seq);
            return;
        }
        seq.push_back(nums[index]);
        dfs(nums,index+1,seq,result);
        seq.pop_back();
        dfs(nums,index+1,seq,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> seq;
        dfs(nums,0,seq,result);
        return result;
    }
};

class Solution {
public:
    void dfs(vector<int>& nums,int index,vector<int> seq,vector<vector<int>>& result) {
        if(index >= nums.size()) {
            result.push_back(seq);
            return;
        }
        dfs(nums,index+1,seq,result);
        seq.push_back(nums[index]);
        dfs(nums,index+1,seq,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> seq;
        dfs(nums,0,seq,result);
        return result;
    }
};

//bitmap的解决方法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len=nums.size();
        long long bit=0,maxbit=(1<<len);
        vector<vector<int>> result;
        while(bit<maxbit) {
            long long curbit=bit;
            vector<int> seq;
            for(int i=0;i<len;i++) {
                if(curbit&1)
                    seq.push_back(nums[i]);
                curbit>>=1;
            }
            result.push_back(seq);
            bit++;
        }
        return result;
    }
};
