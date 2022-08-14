import java.util.*;
import java.io.*;

// Binary Search

class Solution {
    public int search(int[] nums, int target) {
        int r = nums.length - 1;
        int l = 0;
        while(l <= r) {
            int mid = r + l;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
}