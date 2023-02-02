class InstaPet{
    private Usuario[] usuarios;

    public InstaPet() {
        this.usuarios = new Usuario[0];
    }

    public void cadastra_usuario(String nome, String email) {
        // Adiciona 1 espaço na array para a novo usuario e atribui.
        Usuario[] novo_usuario = new Usuario[this.usuarios.length + 1];
        for (int i = 0; i < this.usuarios.length; i++) {
            novo_usuario[i] = this.usuarios[i];
        }
        this.usuarios = novo_usuario;
        this.usuarios[this.usuarios.length -1].setNome(nome);
        this.usuarios[this.usuarios.length -1].setEmail(email);
    }

    public void cadastra_foto(String email, String link, String descricao) {
        int i;
        for ( i=0; i < this.usuarios.length; i++) {
            if (this.usuarios[i].getEmail().equals(email)) {
                this.usuarios[i].cadastra_foto(link, descricao);
                break;
            }
        }
        if (i == this.usuarios.length) {
            System.out.println("Email invalido. Tente novamente.");  
        }
    }

    public void cadastra_pet(String email, String nome) {
        int i;
        for ( i=0; i < this.usuarios.length; i++) {
            if (this.usuarios[i].getEmail().equals(email)) {
                this.usuarios[i].cadastra_pet(nome);
                break;
            }
        }
        if (i == this.usuarios.length) {
            System.out.println("Email invalido. Tente novamente.");  
        }
    }

    public int qnt_pets(String email){
        for (int i=0; i < this.usuarios.length; i++) {
            if (this.usuarios[i].getEmail().equals(email)) {
                return this.usuarios[i].qnt_pets();
            }
        }
        return -1;
    }

    public int qnt_usuarios(){
        return this.usuarios.length;
    }

    public void altera_descricao(String email, int n, String descricao) {
        int i;
        for ( i=0; i < this.usuarios.length; i++) {
            if (this.usuarios[i].getEmail().equals(email)) {
                this.usuarios[i].altera_descricao(n, descricao);;
                break;
            }
        }
        if (i == this.usuarios.length) {
            System.out.println("Email invalido. Tente novamente.");  
        }
    }

    public void listar_pets(String email) {
        for (int i=0; i < this.usuarios.length; i++) {
            if (this.usuarios[i].getEmail().equals(email)) {
                Foto[] fotos = this.usuarios[i].getFotos();
                for (int j=0; j < fotos.length; j++) {
                    System.out.println("url: " + fotos[j].getUrl() + "\ndescricao: " + fotos[j].getDescricao());
                    System.out.println("------------------------------------------");
                }
            }
        }
    }

    public void listar_usuarios(){
        for (int i=0; i < this.usuarios.length; i++) {
            System.out.println("nome: " + this.usuarios[i].getNome() + "\nemail: " + this.usuarios[i].getEmail());
            System.out.println("------------------------------------------");
        }
    }
}