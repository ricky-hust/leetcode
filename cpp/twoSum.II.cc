//这个程序的证明大概如下:
//假设答案是[index1,index2]，可能有多组答案，index1,index2是最两边最外围的
//第一种情况:先到达index1，第二种清苦:先到达index2，很简单可以证明这两种情况都可以得到正确答案
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int low=0,high=numbers.size()-1;
        while(low<high) {
            if(numbers[low]+numbers[high] == target) {
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }
            numbers[low]+numbers[high] > target ? high-- : low++;
        }
        return result;
    }
};
