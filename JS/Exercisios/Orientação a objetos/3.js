class EnderecoCliente{
    constructor(rua = "", bairro = "", cidade = "", estado = ""){
        this.rua = rua;
        this.bairro = bairro;
        this.cidade = cidade;
        this.estado = estado;
    }

    set setRua(nome){
        this.rua = nome;
    }
    
    set setBairro(nome){
        this.bairro = nome;
    }

    set setCidade(nome){
        this.cidade = nome;
    }

    set setEstado(nome){
        this.estado = nome;
    }
}

const Endereco = new EnderecoCliente("Aimores", "Guanabara", "São Paulo", "São Paulo");
console.log(Endereco);
Endereco.setBairro = "Jorge";
console.log(Endereco);