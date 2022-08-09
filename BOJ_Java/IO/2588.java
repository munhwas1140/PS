import java.io.IOException;
import java.util.Scanner;


// 곱셈

class Main {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int sum = 0;
        for(int i = 0; i < 3; i++) {
            int tmp = a * (b % 10);
            System.out.println(tmp);
            sum += (int)Math.pow(10, i) * tmp;
            b /= 10;
        }
        System.out.println(sum);
    }   
}