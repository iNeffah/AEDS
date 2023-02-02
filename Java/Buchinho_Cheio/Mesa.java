import java.util.Scanner;

public class Mesa {
    private int n_mesa;
    private String data;
    private boolean reserva;
    private Cliente[] clientes;
    private ComandaComida ComandaComida;
    private ComandaBebida ComandaBebida;

    //Construtor
    public Mesa() {
        this.reserva = false;
        this.clientes = new Cliente[0];
    }

    // Getters e Setters
    public int getN_mesa() {
        return n_mesa;
    }
    public void setN_mesa(int n_mesa) {
        this.n_mesa = n_mesa;
    }
    
    public String getData() {
        return data;
    }

    public Cliente[] getClientes() {
        return clientes;
    }
    public Comanda get_ComandaComida() {
        return ComandaComida;
    }
    public Comanda get_ComandaBebida() {
        return ComandaBebida;
    }

    public boolean getReserva() {
        return reserva;
    }

    // Métodos
    // Reserva a mesa. retorna false se nao conseguir e true se sim
    public boolean reservar(String data, int n_pessoas) {
        if (this.reserva == true) { // mesa ja reservada
            return false;
        } else {
            this.reserva = true;
            this.data = data;

            Scanner scan = new Scanner(System.in);
            this.clientes = new Cliente[n_pessoas];
            for (int i=0; i < n_pessoas; i++) {
                this.clientes[i] = new Cliente();
                System.out.println("Nome do cliente " + i+1 + ": ");
                clientes[i].setNome(scan.next());
                System.out.println("Email do cliente " + i+1 + ": ");
                clientes[i].setEmail(scan.next());
            }
            return true;
        }
    }
    // Imprime informações da mesa
    public void imprime_mesa() {
        System.out.println("Mesa: " + n_mesa);
        if (reserva == true) {
            System.out.println("\nEstado: reservado" +
                               "\nData: " + data); 
        } else {System.out.println("\nEstado: nao reservado"); }
        System.out.println("\n-----------------------------------\n");
    }

    // Adiciona 1 cliente ao vetor de clientes da mesa
    public void add_cliente(String nome, String email) {
        // Adiciona espaço igual a 1 cliente na array e atribui.
        Cliente[] novo = new Cliente[this.clientes.length + 1];
        Scanner scan = new Scanner(System.in);
        for (int i = 0; i < this.clientes.length; i++) {
            novo[i] = this.clientes[i];
        }
        this.clientes = novo;
        this.clientes[this.clientes.length -1] = new Cliente();
        clientes[this.clientes.length -1].setNome(nome);
        clientes[this.clientes.length -1].setEmail(email);
    }

    // Pega o pedido da mesa com nome do item e valor e coloca na comanda
    public void get_pedido(Comanda comanda) {
        Scanner scan = new Scanner(System.in);
        String item;
        double valor;

        System.out.println("Item: ");
        item = scan.next();
        System.out.println("Valor: ");
        valor = scan.nextDouble();
        comanda.add_item(item, valor);
    }
}

