import java.util.*;
import java.io.*;

// A + B / 4 (EOF check)

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        while(((str = br.readLine()) != null)) {
            String[] strarr = str.split(" ");
            int a = Integer.parseInt(strarr[0]);
            int b = Integer.parseInt(strarr[1]);
            System.out.println(a + b);
        }
    }
}