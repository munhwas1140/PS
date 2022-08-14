import java.uitl.*;
import java.io.*;

// Search Insert Position

class Solution {
    public int searchInsert(int[] nums, int target) {
        int r = nums.length - 1;
        int l = 0;
        int ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return (ans == -1 ? nums.length : ans);
    }
}