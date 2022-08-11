import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException{
        int input = 0;
        while((input = System.in.read()) != -1) {
            System.out.println("입력문자 : " + input + " >> "+ (char)input);
        }
        
    }
}