public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l=0,h=nums.length-1;
        while(l<=h) {
            int m=(l+h)/2;
            if(nums[m]<target) {
                l=m+1;
            } else if(nums[m]>target) {
                h=m-1;
            } else {
                int rl=m,rh=m;
                while(rl-1>=0 && nums[rl-1]==target) rl--;
                while(rh+1<nums.length && nums[rh+1]==target) rh++;
                return new int[]{rl,rh};
            }
        }
        return new int[]{-1,-1};
    }
}
