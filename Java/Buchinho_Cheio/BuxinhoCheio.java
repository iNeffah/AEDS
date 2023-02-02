public class BuxinhoCheio {
    private String nome;
    private String endereco;
    private Mesa[] mesas;

    // Construtor
    public BuxinhoCheio() {
        this.nome = "Restaurante Buxinho Cheio";
        this.endereco = "Coltec UFMG";
        this.mesas = new Mesa[40];
        for (int i=0; i < 40; i++) {
            this.mesas[i].setN_mesa(i+1);
        }
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getEndereco() {
        return endereco;
    }
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    public Mesa getMesa(int n_mesa) {
        for (int i=0; i<40; i++) {
            if (mesas[i].getN_mesa() == n_mesa) {
                return mesas[i];
            }
        } return null;
        
    }
    
    // Métodos
    // Reserva uma mesa definida
    public boolean reservar_mesa(int mesa, String data, int nPessoas) {
        if (this.mesas[mesa].reservar(data, nPessoas)) {
            return true;
        } else {return false;}
    }

    // Imprime informações do restaurante
    public void imprimeRestaurante() {
        System.out.println("Restaurante " + this.nome +
                           "\nEndereço: " + endereco +
                           "\n------- Informações das mesas -------\n");
        for (int i=0; i < this.mesas.length; i++) {
            mesas[i].imprime_mesa();
        }
    }
    public void imprime_mesa(int n_mesa) {
        for (int i=0; i<40; i++) {
            if (mesas[i].getN_mesa() == n_mesa) {
                mesas[i].imprime_mesa();
                break;
            }
        }
    }
}