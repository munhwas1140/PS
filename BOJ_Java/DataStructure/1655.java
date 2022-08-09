import java.util.*;
import java.io.*;

//가운데를 말해요

class Main {
    static BufferedReader br;
    static BufferedWriter bw;
    
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> left = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> right = new PriorityQueue<>();
        int tmp;
        for(int i = 0; i < n; i++) {
            tmp = Integer.parseInt(br.readLine());
            if(left.isEmpty() || tmp < left.peek()) {
                left.offer(tmp);
            } else {
                right.offer(tmp);
            }
            
            if(left.size() == right.size() + 2) {
                right.offer(left.poll());
            } else if(right.size() == left.size() + 1) {
                left.offer(right.poll());
            }
            bw.write(String.valueOf(left.peek()) + "\n");
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}