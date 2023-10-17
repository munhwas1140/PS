import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        HashMap map = new HashMap();
        map.put("myId", "1234");
        map.put("asdf", "1111");
        map.put("asdf", "1234");
        Scanner s = new Scanner(System.in);
        while(true) {
            System.out.println("id와 password를 입력해주세요");
            System.out.print("id : ");
            String id = s.nextLine().trim();
            System.out.print("password : ");
            String password = s.nextLine().trim();
            System.out.println();

            if(!map.containsKey(id)) {
                System.out.println("id not Found");
                continue;
            }

            if(!(map.get(id)).equals(password)) {
                System.out.println("password not valid");
            } else {
                System.out.println("id, password valid");
                break;
            }
        }
    }
}