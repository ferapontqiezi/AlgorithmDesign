import java.util.*;

public class Main{
    public static void main(String[] args) {
        Random aRandom = new Random();
        int a = aRandom.nextInt(2);
        if(a == 1){
            System.out.println("error1");
        } else {
            System.out.println("error3");
        }
    }
}