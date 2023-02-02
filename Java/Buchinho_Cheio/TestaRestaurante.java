/* Trabalho de AEDS (Terceira Trimestral) 
 * João Pedro Neffa e Leandro Rodrigues
 * 203 COLTEC UFMG
*/

import java.util.Scanner;

public class TestaRestaurante {
    public static int Menu() {
        Scanner read = new Scanner(System.in);
        int opcao;

        System.out.println("\n-----------MENU-----------" +
                           "\n(1) - Fazer reserva" +
                           "\n(2) - Cadastrar cliente" +
                           "\n(3) - Fazer pedido" +
                           "\n(4) - Ver mesa" +
                           "\n(5) - Ver comandas" +
                           "\n(6) - Ver informacoes" +
                           "\n(7) - Dividir Conta" +
                           "\n(0) - Sair" +
                           "\n--------------------------");
        opcao = read.nextInt();
        return opcao;
    }

    public static void main(String[] args) {
        BuxinhoCheio BC = new BuxinhoCheio();
        int opcao;
        Scanner read = new Scanner(System.in);
        int mesa, nPessoas, tipo;

        do {
            opcao = Menu();
            switch (opcao) {
                case 1: // Fazer reserva
                    String data;
                    System.out.println("-----Informações da reserva-----");

                    System.out.println("Numero da mesa: ");
                    mesa = read.nextInt();
                    if (BC.getMesa(mesa) == null) {
                        System.out.println("Mesa nao encontrada.");
                        break;
                    }

                    System.out.println("Data: ");
                    data = read.next();

                    System.out.println("Numero de pessoas: ");
                    nPessoas = read.nextInt();

                    if (!BC.reservar_mesa(mesa, data, nPessoas)) {
                        System.out.println("Erro ao tentar realizar a reserva. Tente novamente");
                    }
                    break;

                case 2: // Adiciona um cliente a mesa
                    String nome, email;

                    System.out.println("Numero da mesa: ");
                    mesa = read.nextInt();
                    if (BC.getMesa(mesa) == null) {
                        System.out.println("Mesa nao encontrada.");
                        break;
                    }
                    System.out.println("Nome do cliente: ");
                    nome = read.next();
                    System.out.println("Email do cliente: ");
                    email = read.next();
                    BC.getMesa(mesa).add_cliente(nome, email);
                    break;
                
                case 3: // Fazer pedido
                    System.out.println("Numero da mesa: ");
                    mesa = read.nextInt();
                    if (BC.getMesa(mesa) == null) {
                        System.out.println("Mesa nao encontrada.");
                        break;
                    }

                    System.out.print("Escolha o tipo:\n" +
                                       "(1) Comida\n" +
                                       "(2) Bebida\n");
                    tipo = read.nextInt();

                    if (tipo == 1) {
                        BC.getMesa(mesa).get_pedido(BC.getMesa(mesa).get_ComandaComida());
                    } else {
                        BC.getMesa(mesa).get_pedido(BC.getMesa(mesa).get_ComandaBebida());
                    }
                    break;
                    
                case 4: // Ver informacoes de uma mesa
                    System.out.println("Numero da mesa: ");
                    mesa = read.nextInt();
                    if (BC.getMesa(mesa) == null) {
                        System.out.println("Mesa nao encontrada.");
                        break;
                    }
                    BC.imprime_mesa(mesa);
                
                case 5: // Ver comandas da mesa
                    System.out.println("Numero da mesa: ");
                    mesa = read.nextInt();
                    if (BC.getMesa(mesa) == null) {
                        System.out.println("Mesa nao encontrada.");
                        break;
                    }

                    System.out.println("Escolha qual comanda quer ver:\n" +
                                       "(1) Comanda de Comida\n" +
                                       "(2) Comanda de Bebida\n");
                    tipo = read.nextInt();
                    if (tipo == 1) {
                        BC.getMesa(mesa).get_ComandaComida().listar_consumo();
                    } else {
                        BC.getMesa(mesa).get_ComandaBebida().listar_consumo();
                    }
                    break;
                    
                case 6: // Ver informações
                    BC.imprimeRestaurante();
                    break;
                
                case 7: // Divide o valor total
                    System.out.println("Numero da mesa: ");
                    mesa = read.nextInt();
                    if (BC.getMesa(mesa) == null) {
                        System.out.println("Mesa nao encontrada.\n");
                        break;
                    }

                    System.out.println("Numero de pessoas: ");
                    nPessoas = read.nextInt();

                    System.out.println("Valor dividido: " + (BC.getMesa(mesa).get_ComandaComida().dividirConta(nPessoas) +
                    BC.getMesa(mesa).get_ComandaBebida().dividirConta(nPessoas)) + "\n");

                case 0: // Finalizar programa
                    break;

                default:
                    System.out.println("Opção invalida\n");
            }

        } while (opcao != 0);
    }
}