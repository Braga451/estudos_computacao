class Carro{
    constructor(marca = "", cor = ""){
        this.marca = marca;
        this.cor = cor;
        this.gasolina_restante = 0; // Limite 500L
    }

    abastecer(quantidade){
        if(this.gasolina_restante + quantidade <= 500){
            this.gasolina_restante += quantidade;
            console.log(`Total gasolina: ${this.gasolina_restante}`);
        }
        else{
            console.log(`Foram colocados apenas ${quantidade - this.gasolina_restante > 0 ? quantidade - this.gasolina_restante : 0} litros`);
            this.gasolina_restante = 500;
        }
    }

    dirigir(){
        if(this.gasolina_restante - 10 > 0){
            this.gasolina_restante -= 10
            console.log(`Gasolina restante: ${this.gasolina_restante}`);
        }
        else{
            console.log("Vá abastecer!");
        }
    }
}

const carro = new Carro();
carro.dirigir();
carro.abastecer(14);
carro.dirigir();
carro.dirigir();
carro.abastecer(500);
carro.abastecer(1);