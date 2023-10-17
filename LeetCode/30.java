import java.util.*;
import java.io.*;

// Substring with Concatenation of All Words

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {    
        List<Integer> ans = new ArrayList<>();
        int n = words[0].length();
        int m = words.length;
        for(int i = 0; i <= s.length() - n * m; i++) {
            String sub = s.substring(i, i + n * m);
            
            Set<Integer> set = new HashSet<>();
            
            for(String word : words) {
                int pos = sub.indexOf(word);
                while(pos != -1 && (set.contains(pos) || pos % n != 0)) {
                    pos = sub.indexOf(word, pos + 1);
                }
                if(pos == -1) break;
                set.add(pos);
            }
            if(set.size() == m) {
                ans.add(i);
            }
        }
        return ans;
    }
}




// import java.util.*;
// import java.io.*;

// class Solution {
//     public List<Integer> findSubstring(String s, String[] words) {
//         int slen = s.length();
//         int n = words.length;
//         int wordLen = words[0].length();
        
//         Map<String, Integer> count = new HashMap<>();
//         for(String word : words) {
//             count.put(word, count.getOrDefault(word,0) + 1);
//         }
        
//         List<Integer> ans = new ArrayList<>();
        
//         for(int i = 0; i <= slen - wordLen * n; i++) {
//             String subStr = s.substring(i, i + wordLen * n);
//             if(check(subStr,count,wordLen)) {
//                 ans.add(i);
//             }
//         }
//         return ans;
//     }
            
//     static boolean check(String subStr, Map<String, Integer> count, int wordLen) {
//         Map<String, Integer> seen = new HashMap<>();
//         for(int i = 0; i < subStr.length(); i += wordLen) {
//             String sword = subStr.substring(i, i + wordLen);
//             seen.put(sword, seen.getOrDefault(sword, 0) + 1);
//         }
//         return seen.equals(count);
//     }
// }