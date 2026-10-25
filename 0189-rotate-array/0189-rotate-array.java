class Solution {
    public void rotate(int[] nums, int k) {
        // Edge case: if the array is empty or k is 0, no rotation needed
        

        // Reduce k to avoid unnecessary full rotations
        k = k % nums.length;

        // Reverse the entire array
        reverse(nums, 0, nums.length - 1);

        // Reverse the first k elements
        reverse(nums, 0, k - 1);

        // Reverse the remaining n-k elements
        reverse(nums, k, nums.length - 1);
    }

    // Helper method to reverse a part of the array
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            // Swap elements at start and end
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}