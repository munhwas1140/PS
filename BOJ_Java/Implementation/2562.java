import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//최댓값

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a[] = new int[9];
        for(int i = 0; i < 9; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        int idx = 0, max = a[0];
        for(int i = 1; i < 9; i++) {
            if(a[i] > max) {
                idx = i;
                max = a[i];
            }
        }

        System.out.println(max);
        System.out.println(idx + 1);
    }
}