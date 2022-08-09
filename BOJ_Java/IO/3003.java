import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

// 킹, 퀸, 룩, 비숍, 나이트, 폰

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[6];
        int[] correct = {1,1,2,2,2,8};
        for(int i = 0; i < 6; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i = 0; i < 6; i++) {
            bw.write(String.valueOf(correct[i] - arr[i]) + " ");
        }
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }   
}