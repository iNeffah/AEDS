public class Exercicio3 {
    public static void main(String[] args) {
        int num = 5;
        for (int n = 1; n <= num; n++) {
            for (int i = 1; i <= n; i++) {
                int x = n * i;
                System.out.println(x);
            }
            System.out.println('\n');
        }
    }
}
