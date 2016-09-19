/* 算法步骤：[0...end]
 * 1.从最右边开始找最长的non-descending序列[j...end]
 * 2.如果j!=0，将nums[j-1]作为pivot，在[j..end]中找到pivot的前驱，也就是从右开始第一个大于pivot的nums[i]
 *   如果i==0，那么证明这是最后一个permutation，reverse这个nums即可，结束
 * 3.交换nums[i]和nums[j-1]
 * 4.reverse nums[j...end]
 */

class Solution {
public:
    void exchange(int &a,int &b) {
        int temp=a;
        a=b;
        b=temp;
    }

    void reverse(vector<int> &nums,int low,int high) {
        while(low<high) {
            swap(nums[low],nums[high]);
            low++;high--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;
        //here must be >= not >
        while(j-1>=0 && nums[j-1]>=nums[j]) j--;
        if(j>0) {
            int pivot=nums[j-1];
            int i=nums.size()-1;
            //here must be <= not <
            while(nums[i]<=pivot) i--;
            exchange(nums[j-1],nums[i]);
            reverse(nums,j,nums.size()-1);
        } else {
            reverse(nums,0,nums.size()-1);
        }
        
    }
};
