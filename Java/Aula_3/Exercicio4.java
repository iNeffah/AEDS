public class Exercicio4 {
    public static void main(String[] args) {
        int f1, f2;
        f1 = 0; 
        f2 = 1;
        while (f2 <= 100) {
            f2 = f1 + f2;
            f1 = f2 - f1;; 

            System.out.println(f2);
        }
    }
}