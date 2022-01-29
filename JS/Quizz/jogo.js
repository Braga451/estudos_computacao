class Jogo{
    #perguntas;
    #pergunta_numero;
    constructor(){
        this.#perguntas = {
            1 : {
                pergunta : "Qual das opções não é um paradigma de programação?:",
                respostas : [
                    ["Programação orientada a objetos", false],
                    ["Programação funcional", false],
                    ["Programação orientada a eventos", false],
                    ["Programação de listas ligadas", true]
                ]
            },
            2 : {
                pergunta : "Qual das opções não é uma linguagem de programação?:",
                respostas : [
                    ["Java", false],
                    ["Brainfuck", false],
                    ["Assembly", false],
                    ["Pilha", true]
                ]
            },
            3: {
                pergunta: "Qual das opções abaixo não é uma estrutura de dados?:",
                respostas: [
                    ["Lista ligada", false],
                    ["Fila", false],
                    ["Arvore", false],
                    ["Mesa", true]
                ]
            }
        }
        this.#pergunta_numero = 1;
    }

    returnPergunta(){
        if(this.#pergunta_numero == Object.keys(this.#perguntas).length + 1){
            return 1;
        }
        const pergunta = this.#perguntas[this.#pergunta_numero];
        this.#pergunta_numero++;
        return pergunta;
    }

    responder(id_elemento){
        const referencia = {
            A : 0,
            B : 1,
            C : 2,
            D : 3
        }
        const pergunta = this.#perguntas[this.#pergunta_numero - 1]["respostas"];
        if(pergunta[referencia[id_elemento]][1]){
            return true;
        }
        return false;
    }

    resetaJogo(){
        this.#pergunta_numero = 1;
    }
}