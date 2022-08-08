package 그래프;
// DFS 와 BFS

import java.io.*;
import java.util.*;

class Main {

    private static int n, m, start;
    private static boolean[] visited;
    private static BufferedWriter bw;
    private static BufferedReader br;
    private static List<Integer>[] a;

    private static void DFS(int now) throws IOException {
        bw.write(String.valueOf(now) + " ");
        visited[now] = true;
        for(int next : a[now]) {
            if(!visited[next]) {
                DFS(next);
            }
        }
    }

    private static void BFS(int start) throws IOException{
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = true;

        while(!q.isEmpty()) {
            int now = q.poll();
            bw.write(String.valueOf(now) + " ");

            for(int next : a[now]) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.offer(next);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        start = Integer.parseInt(st.nextToken());

        visited = new boolean[n + 1];
        a = new ArrayList[n + 1];

        for(int i = 0; i < n + 1; i++) {
            a[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            a[s].add(e);
            a[e].add(s);
        }

        for(List<Integer> list : a) {
            Collections.sort(list);
        }

        DFS(start);
        bw.newLine();

        Arrays.fill(visited, false);
        BFS(start);
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }

}
