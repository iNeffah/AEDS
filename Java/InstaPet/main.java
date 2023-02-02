public class main {
    public static void main (String[] args) {
        InstaPet IP = new InstaPet();

        IP.cadastra_usuario("Joao Neffa", "jpsousa837@gmail.com");
        IP.cadastra_foto("jpsousa837@gmail.com", "https://akwvd", "Muito fofo :D");
        IP.listar_pets("jpsousa837@gmail.com");
        IP.listar_usuarios();
        System.out.println(IP.qnt_usuarios());
        IP.altera_descricao("jpsousa837@gmail.com", 1, "Muito fofo XD");
        IP.listar_pets("jpsousa837@gmail.com");
        IP.cadastra_pet("jpsousa837@gmail.com", "Godofredo");
        System.out.println(IP.qnt_pets("jpsous837@gmail.com"));
    }
}
