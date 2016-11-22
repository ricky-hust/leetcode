//使用递归+回溯的思路来解决，时间复杂度为O(n!)
class Solution {
public:
    //index为当前需要决定的第index个数
    void internalPermute(vector<int> &num, int index, vector<int> &perm, vector<vector<int> > &result) {
        int size = num.size();
        
        if (size == index) {
            result.push_back(perm);
        }
        else {
            for (int i = index; i < size; ++i) {
                swap(num[index], num[i]);
                perm.push_back(num[index]);
                internalPermute(num, index + 1, perm, result);
                perm.pop_back(); //将之前的pop出去
                swap(num[index], num[i]); //恢复nums
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> perm;
        
        internalPermute(num, 0, perm, result);
        
        return result;
    }
};
