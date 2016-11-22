public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i=0,j=numbers.length-1;
        while(i<j) {
            int t = numbers[i] + numbers[j];
            if(t>target) {
                j--;
            } else if(t<target) {
                i++;
            } else {
                return new int[]{i+1,j+1};
            }
        }
        throw new RuntimeException();
    }
}
