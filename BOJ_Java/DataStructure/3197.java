import java.util.*;
import java.io.*;

// 백조의 호수

class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int r, c;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static boolean[][] visited;
    static char[][] map;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));    
        
        int sx, sy, ex, ey;
        sx = sy = ex = ey = -1;
        
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        
        visited = new boolean[r][c];
        map = new char[r][];
        Queue<Pair> waterQ = new LinkedList<>();
        Queue<Pair> swanQ = new LinkedList<>();

        for(int i = 0; i < r; i++) {
            map[i] = br.readLine().toCharArray();
            for(int j = 0; j < c; j++) {
                if(map[i][j] == 'L') {
                    if(sx == -1) {
                        sx = i; sy = j;
                        swanQ.offer(new Pair(sx,sy));
                        visited[sx][sy] = true;
                    } else {
                        ex = i; ey = j;
                    } 
                }
                if(map[i][j] != 'X') { 
                    waterQ.add(new Pair(i,j));
                }
            } 
        }


        boolean flag = false;
        int ans = 0;

        for(int i = 0;; i++) {
            int x, y;
            Queue<Pair> swanQ2 = new LinkedList<>();
            while(!swanQ.isEmpty()) {
                Pair now = swanQ.poll();
                x = now.first;
                y = now.second;
                if(x == ex && y == ey) {
                    flag = true;
                    ans = i;
                    break;
                }
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    if(map[nx][ny] == 'X') {
                        swanQ2.add(new Pair(nx, ny));  
                        continue;  
                    }
                    swanQ.add(new Pair(nx,ny));
                }
            }
            
            if(flag) {
                break;
            }

            int size = waterQ.size();
            for(int j = 0; j < size; j++) {
                Pair now = waterQ.poll();
                x = now.first;
                y = now.second;
                
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if(map[nx][ny] == 'X') {
                        waterQ.offer(new Pair(nx,ny));
                        map[nx][ny] = '.';
                    }
                }
            }
            
            swanQ = swanQ2;
        }

        System.out.println(ans);
        br.close();
    }
}

class Pair {
    Integer first, second;
    Pair(Integer first, Integer second) {
        this.first = first;
        this.second = second;
    }
    public String toString() {
        return first + " " + second;
    }
}