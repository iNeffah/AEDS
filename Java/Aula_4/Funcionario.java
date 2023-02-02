class Data {
    int dia;
    int mes;
    int ano;

    public void mostra_data(){
        System.out.print("Data: " + dia + "/" + mes + "/" + ano);
    }
}

class Funcionario {
    String nome;
    String departamento;
    double salario;
    String RG;
    Data data_de_entrada;

    public Funcionario() {
        data_de_entrada = new Data();
    }

    public void mostra(){
        System.out.println("Nome: "+ nome);
        System.out.println("Nome: "+ departamento);
        System.out.println("Salario: "+salario);
        System.out.println("RG: "+RG);
        data_de_entrada.mostra_data();
    }
}

class exercicio {
    public static void main (String[] args) {
        Funcionario funcionario1 = new Funcionario();
        Funcionario funcionario2 = new Funcionario();
        Funcionario funcionario3 = new Funcionario();

        // Instanciando Funcionario 1
        funcionario1.nome = "Matheus";
        funcionario1.departamento = "Marketing";
        funcionario1.salario = 2000.0;
        funcionario1.RG = "12345678901";
        funcionario1.data_de_entrada.dia = 10;
        funcionario1.data_de_entrada.mes = 6;
        funcionario1.data_de_entrada.ano = 2022;

        // Instanciando Funcionario 2
        funcionario1.nome = "Alice";
        funcionario1.departamento = "Administrativo";
        funcionario1.salario = 10000.0;
        funcionario1.RG = "12345678901";
        funcionario1.data_de_entrada.dia = 10;
        funcionario1.data_de_entrada.mes = 6;
        funcionario1.data_de_entrada.ano = 2022;
        
        // Instanciando Funcionario 3
        funcionario3.nome = "Matheus";
        funcionario3.departamento = "Marketing";
        funcionario3.salario = 2000.0;
        funcionario3.RG = "12345678901";
        funcionario3.data_de_entrada.dia = 10;
        funcionario3.data_de_entrada.mes = 6;
        funcionario3.data_de_entrada.ano = 2022;

        if(funcionario1 == funcionario2){
            System.out.println("Funcionarios 1 e 2 são iguais");
        }else{
            System.out.println("Funcionarios 1 e 2 não são iguais");
        }

        if(funcionario1 == funcionario3){
            System.out.println("Funcionarios 1 e 3 são iguais");
        }else{
            System.out.println("Funcionarios 1 e 3 não são iguais");
        }
    }
}