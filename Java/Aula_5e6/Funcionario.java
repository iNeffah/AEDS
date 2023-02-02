class Funcionario {
    private String nome;
    private String departamento;
    private double salario;
    private String RG;
    private Data data_de_entrada;
    private static int totalDeFuncionarios;
    private int identificador;

    public Funcionario() {
        data_de_entrada = new Data();
        Funcionario.totalDeFuncionarios++;
        this.identificador = Funcionario.totalDeFuncionarios;
    }
    public Funcionario(String nome) {
        data_de_entrada = new Data();
        this.nome = nome;
        Funcionario.totalDeFuncionarios++;
        this.identificador = Funcionario.totalDeFuncionarios;
    }

    public String getNome() {return this.nome;}
    public void setNome(String nome) {this.nome = nome;}

    public String getDepartamento() {return this.departamento;}
    public void setDepartamento(String departamento) {this.departamento = departamento;}

    public double getSalario() {return this.salario;}
    public void setSalario(double salario) {this.salario = salario;}

    public String getRG() {return this.RG;}
    public void setRG(String RG) {this.RG = RG;}

    public Data getDataDeEntrada() {return this.data_de_entrada;}
    public void setDataDeEntrada(int dia, int mes, int ano) {
        if ((this.data_de_entrada.getDia() < 32 && this.data_de_entrada.getDia() > 0) 
        && (this.data_de_entrada.getMes() < 13 && this.data_de_entrada.getMes() > 0)
        && (this.data_de_entrada.getAno() > 0)) {
            this.data_de_entrada.setDia(dia);
            this.data_de_entrada.setMes(mes);
            this.data_de_entrada.setAno(ano);
        } else {System.out.println("Data inserida eh invalida");}
    }

    public static int getTotalDeFuncionarios() {return Funcionario.totalDeFuncionarios;}
    public int getIdentificador() {return this.identificador;}

    public void mostra(){
        System.out.println("Nome: "+ getNome());
        System.out.println("Nome: "+ getDepartamento());
        System.out.println("Salario: "+ getSalario());
        System.out.println("RG: "+ getRG());
        data_de_entrada.mostra_data();
    }

}
