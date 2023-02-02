class Empresa {
    private String nome;
    private String cnpj;
    private Funcionario[] empregados;
    
    public String getNome() {return this.nome;}
    public void setNome(String nome) {this.nome = nome;}

    public String getCNPJ() {return this.cnpj;}
    public void setCNPJ(String cnpj) {this.cnpj = cnpj;}

    public void setEmpregados(Funcionario[] empregados) {this.empregados = empregados;}
    public Funcionario[] getEmpregados() {return this.empregados;}

    public Funcionario getFuncionario(int index) {return this.empregados[index];}
    int total_f = 0;
    public void adiciona(Funcionario f) { 
        if (this.total_f == this.empregados.length) {
            Funcionario[] novo = new Funcionario[this.empregados.length +1];
            for (int i = 0; i < this.empregados.length; i++) {
                       novo[i] = this.empregados[i];
            }
            this.empregados = novo;
        }
        this.empregados[this.total_f] = f;
        this.total_f++;
    }

    void mostraEmpregados() {
        for (int i = 0; i < total_f; i++) {
            System.out.println ("Funcionario na posicao: " + i);
            this.empregados[i].mostra();
            System.out.println("\n-----------------------------------------");
        }
    }
}