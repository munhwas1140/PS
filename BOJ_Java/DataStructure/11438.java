import java.util.*;
import java.io.*;


// LCA2

class Main {
    static int n;
    static ArrayList<Integer>[] g;
    static boolean visited[];
    static int dp[][];
    static int depth[];

    static void DFS(int now, int d) {
        visited[now] = true;
        depth[now] = d;
        for(int next : g[now]) {
            if(!visited[next]) {
                dp[next][0] = now;
                DFS(next, d + 1);
            }
        }
    }

    static void init() {
        for(int j = 1; j < 30; j++) {
            for(int i = 1; i <= n; i++) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }

    static int LCA(int u, int v) {
        if(depth[u] < depth[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }


        int diff = depth[u] - depth[v];
        for(int i =0 ; diff != 0; i++) {
            if((diff & 1) == 1) {
                u = dp[u][i];
            }
            diff >>= 1;
        }

        if(u == v) {
            return u;
        }
        for(int i = 29; i>= 0; i--) {
            if(dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return dp[u][0];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());

        g = new ArrayList[n + 1];
        for(int i = 0; i < n + 1; i++) {
            g[i] = new ArrayList<>();
        }
        depth = new int[n + 1];
        dp = new int[n + 1][30];
        visited = new boolean[n + 1];

        for(int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a, b;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            g[a].add(b);
            g[b].add(a);
        }

        DFS(1,0);
        init();


        int q = Integer.parseInt(br.readLine());
        for(int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a, b;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            int ans = LCA(a, b);
            bw.write(String.valueOf(ans) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}