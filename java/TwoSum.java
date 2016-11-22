public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++) {
            m.put(target-nums[i],i);
        }
        for(int i=0;i<nums.length;i++) {
            Integer v = m.get(nums[i]);
            if(v!=null && v!=i) {
                return new int[]{i,v};
            }
        }
        throw new RuntimeException();
    }
}
