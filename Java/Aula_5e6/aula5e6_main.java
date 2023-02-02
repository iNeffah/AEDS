public class aula5e6_main {
    public static void main (String[] args) {
        Empresa EA = new Empresa();
        EA.setEmpregados(new Funcionario[10]);
        Funcionario funcionario1 = new Funcionario();
        Funcionario funcionario2 = new Funcionario();
        Funcionario funcionario3 = new Funcionario();

        // Instanciando Funcionario 1
        funcionario1.setNome("Matheus");
        funcionario1.setDepartamento("Marketing");
        funcionario1.setSalario(2000.0);
        funcionario1.setRG("12345678901");
        funcionario1.setDataDeEntrada(10, 6, 2022);
        EA.adiciona(funcionario1);

        // Instanciando Funcionario 2
        funcionario2.setNome("Alice");
        funcionario2.setDepartamento("Adiministrativo");
        funcionario2.setSalario(10000.0);
        funcionario2.setRG("92849062891");
        funcionario2.setDataDeEntrada(10, 6, 2022);
        EA.adiciona(funcionario2);
        
        // Instanciando Funcionario 3
        funcionario3.setNome("Matheus");
        funcionario3.setDepartamento("Marketing");
        funcionario3.setSalario(2000.0);
        funcionario3.setRG("12345678901");
        funcionario3.setDataDeEntrada(10, 6, 2022);
        EA.adiciona(funcionario3);

        EA.mostraEmpregados();
    }
}
