public class Exercicio1 {
    public static void main(String[] args) {
        int f1, f2, f3;
        f1 = 0; 
        f2 = 1;
        f3 = 0;
        while (f3 <= 100) {
            f3 = f1 + f2;
            f1 = f2; 
            f2 = f3;
            System.out.println(f3);
        }
    }
}
