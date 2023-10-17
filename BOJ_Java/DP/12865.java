import java.util.*;
import java.io.*;

// 평범한 배낭

class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;
    static int n, k;
    static int[][] d = new int[101][100001];
    static int[] w = new int[101];
    static int[] v = new int[101];

    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            w[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
        }
 
        int ans = -1;
        for(int i = 1; i <= n; i++) {
           for(int j = k; j >= 0; j--) {
               d[i][j] = d[i-1][j];
                if(j - w[i] >= 0) {
                    d[i][j] = Math.max(d[i][j], d[i-1][j-w[i]] + v[i]);
                }
                ans = Math.max(ans, d[i][j]);
           }
        }
        
        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();

    }
}