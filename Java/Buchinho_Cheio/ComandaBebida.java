public class ComandaBebida extends Comanda {
    // imprime a comanda de bebidas com os itens consumidos e o valor total
    @Override
    public void listar_consumo() {
        int i;
        System.out.println("---------- Comanda de Bebida ----------\n");
        for (i=0; i < this.consumo.length; i++) {
            System.out.println(i+1 + ". " + this.consumo[i] + "____________ R$" + this.valores[i] + "\n");
        }
        if (i==0) {
            System.out.println("\tNenhuma bebida foi consumida");
        }
        System.out.println("\t-------------------------\n" +
                           "Subtotal: " + valor_total + 
                           "\nTaxa de Serviço (+10%): " + calcular10porcento() + 
                           "\nTotal: " + (valor_total+calcular10porcento()) +
                           "\n---------------------------------------\n");
    }
}