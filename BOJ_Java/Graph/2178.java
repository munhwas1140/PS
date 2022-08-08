package 그래프;
// 미로 탐색
// #2178

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;
    static int[][] dist;
    static String[] a;
    static int n, m;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        a = new String[n];
        dist = new int[n][m];
        for(int i = 0; i < n; i++) {
            Arrays.fill(dist[i], -1);
        }
        for(int i = 0; i < n; i++) {
            a[i] = br.readLine();
        }

        dist[0][0] = 1;

        Queue<Pair> q = new LinkedList<>();

        q.offer(new Pair(0,0));
        while(!q.isEmpty()) {
            Pair now = q.poll();

            for(int i = 0; i < 4; i++) {
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx].charAt(ny) == '1' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[now.first][now.second] + 1;
                    q.offer(new Pair(nx, ny));
                }
            }
        }

        bw.write(String.valueOf(dist[n-1][m-1]) + "\n");
        bw.flush();
        bw.close();

        br.close();
    }
}

class Pair {
    public Integer first, second;
    Pair(Integer key, Integer value) {
        this.first = key;
        this.second = value;
    }
}