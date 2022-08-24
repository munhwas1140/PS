/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */
import java.util.*;
import java.io.*;

// First Bad Version

public class Solution extends VersionControl {
public int firstBadVersion(int n) {
    int r = n;
    int l = 1;
    int ans = -1;
    while(l <= r) {
        int mid = r - (r - l) / 2;
        if(isBadVersion(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
}