import java.util.Scanner;

public class TestDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        //write your code here.......
        // 用和减
        /*a = a + b;
        b = a - b;
        a = a - b;
        System.out.println(a+" "+b);*/

        // 异或
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        System.out.println(a+" "+b);
    }

    public static void main2(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double d= scanner.nextDouble();

        int i = (int)d;
        if(d - i > 0.5) {
            i++;
        }
        System.out.println(i);
    }

    public static void main1(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

        if(a < b) {
            int c = a;
            a = b;
            b = c;
        }
        System.out.println(a+b+" "+(a-b)+" "+a*b+" "+a/b+" "+a%b);
    }
}
