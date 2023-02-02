class Usuario {
    
    private String nome;
    private String email;
    private Foto[] fotos;
    private String[] pets;

    
    // Getters e Setters
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public Foto[] getFotos() {
        return fotos;
    }
    public String[] getPets() {
        return pets;
    }
    
    public void cadastra_foto(String link, String descricao) {
        // Adiciona 1 espaço na array para a nova foto e atribui.
        Foto[] nova_ft = new Foto[this.fotos.length + 1];
        for (int i = 0; i < this.fotos.length; i++) {
            nova_ft[i] = this.fotos[i];
        }
        this.fotos = nova_ft;
        this.fotos[this.fotos.length].setUrl(link);
        this.fotos[this.fotos.length].setDescricao(descricao);

    }

    public void altera_descricao(int n, String descricao) {
        this.fotos[n-1].setDescricao(descricao); 
        /* n-1 pois não se deve contar a posição 0. 
        // Logo quando o usuario chamar pela 3 foto, por exemplo, 
        ira mudara descricao da foto na 2a posição da array*/
    }

    public void cadastra_pet(String nome) {
        // Adiciona 1 espaço na array para o novo pet e atribui.
        String[] novo_pet = new String[this.pets.length + 1];
        for (int i = 0; i < this.pets.length; i++) {
            novo_pet[i] = this.pets[i];
        }
        this.pets = novo_pet;
        this.pets[this.pets.length] = nome;
    }

    public int qnt_pets() {
        return this.pets.length;
    }
}