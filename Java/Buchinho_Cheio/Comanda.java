abstract public class Comanda {
    protected String[] consumo;
    protected double[] valores;
    protected double valor_total;

    //Construtor
    public Comanda() {
        this.consumo = new String[0];
        this.valores = new double[0];
        this.valor_total = 0;
    }

    // Getter para o valor total
    // Sem setter pois já que alterado toda vez que é realizado um pedido
    public double getValor() {
        return valor_total;
    }
    
    //Métodos
    abstract public void listar_consumo();

    // Adiciona um item e seu preço nos vetores de consumo e valores respectivamente.
    // É utilizada no método get_pedido() da classe Mesa.
    public void add_item(String item, double valor) {
        String[] novo = new String[this.consumo.length + 1];
        double[] novo2 = new double[this.valores.length + 1];

        for (int i = 0; i < this.consumo.length; i++) {
            novo[i] = this.consumo[i];
            novo2[i] = this.valores[i];
        }
        this.consumo = novo;
        this.consumo[this.consumo.length -1] = new String();
        this.consumo[this.consumo.length -1] = item;

        this.valores = novo2;
        this.valores[this.valores.length -1] = valor;
        this.valor_total += valor;
    }

    // Calcula 10% do valor total
    public double calcular10porcento() {
        return (0.1 * valor_total);
    }   

    // Divide a conta entre um numero n de pessoas
    public double dividirConta(int n_pessoas){
        return (valor_total/n_pessoas);
    }
}