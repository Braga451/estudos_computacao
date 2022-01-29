class Jogador{
    #jogador;
    constructor(){
        this.#jogador = 0;
    }
    
    alterarJogador(){
        if(this.#jogador == 0){
            this.#jogador = 1;
        }
        else{
            this.#jogador = 0;
        }
    }

    retornaJogador(){
        return this.#jogador;
    }
}

class JogoDaVelha{
    #vitorias_0;
    #vitorias_1;
    #tabuleiro;
    constructor(){
        // 0 = X | 1 = O
        this.#vitorias_0 = 0;
        this.#vitorias_1 = 0;
        this.#tabuleiro = [[-1,-1,-1], [-1,-1,-1], [-1,-1,-1]];
    }

    #resetarTabuleiro(){
        for(let x = 0; x < 3; x++){
            for(let y = 0; y < 3; y++){
                this.#tabuleiro[x][y] = -1;
            }
        }
    }

    mostrarTabuleiroConsole(){
        let tabuleiro = "";
        for(let x = 0; x < 3; x++){
            for(let y = 0; y < 3; y++){
                tabuleiro += this.#tabuleiro[x][y] + "  ";
            }
            tabuleiro += "\n";
        }
        console.log(tabuleiro);
    }

    getTabuleiro(){
        return this.#tabuleiro;
    }

    inserirPosicaoTabuleiro(posicao, jogador){
        let posicoes = {
            1 : [0,0],
            2 : [0,1],
            3 : [0,2],
            4 : [1,0],
            5 : [1,1],
            6 : [1,2],
            7 : [2,0],
            8 : [2,1],
            9 : [2,2]
        }
        this.#tabuleiro[posicoes[posicao][0]][posicoes[posicao][1]] = jogador;
    }

    verificarVitorias(){
        let linhas_colunas = [-1,-1,1];
        let deu_velha = true;
        // Testa linhas:
        for(let x = 0; x < 3; x++){
            for(let y = 0; y < 3; y++){
                linhas_colunas[y] = this.#tabuleiro[x][y];
            }
            if(linhas_colunas[0] != -1 && linhas_colunas[0] == linhas_colunas[1] && linhas_colunas[1] == linhas_colunas[2]){
                switch(linhas_colunas[0]){
                    case 0:
                        alert("X venceu por linha!");
                        this.#vitorias_0++;
                        break;
                    case 1:
                        alert("O venceu por linha!");
                        this.#vitorias_1++;
                        break;
                }
                this.#resetarTabuleiro();
                return true;
            }
        }
        linhas_colunas = [-1,-1,1];
        // Testa colunas:
        for(let y = 0; y < 3; y++){
            for(let x = 0; x < 3; x++){
                linhas_colunas[x] = this.#tabuleiro[x][y];
            }
            if(linhas_colunas[0] != -1 && linhas_colunas[0] == linhas_colunas[1] && linhas_colunas[1] == linhas_colunas[2]){
                switch(linhas_colunas[0]){
                    case 0:
                        alert("X venceu por coluna!");
                        this.#vitorias_0++;
                        break;
                    case 1:
                        alert("O venceu por coluna!");
                        this.#vitorias_1++;
                        break;
                }
                this.#resetarTabuleiro();
                return true;
            }
        }
        // Testa diagonais:
        if(this.#tabuleiro[1][1] != -1 && ((this.#tabuleiro[0][0] == this.#tabuleiro[1][1] && this.#tabuleiro[1][1] == this.#tabuleiro[2][2])   || (this.#tabuleiro[2][0] == this.#tabuleiro[1][1] && this.#tabuleiro[1][1] == this.#tabuleiro[0][2]))){
            switch(this.#tabuleiro[1][1]){
                case 0:
                    alert("X venceu por diagonal!");
                    this.#vitorias_0++;
                    break;
                case 1:
                    alert("O venceu por diagonal!");
                    this.#vitorias_1++;
                    break;
            }
            this.#resetarTabuleiro();
            return true;
        }
        // Testa se deu velha:
        for(let x = 0; x < 3; x++){
            for(let y = 0; y < 3; y++){
                if(this.#tabuleiro[x][y] == -1){
                    deu_velha = false;
                    break;
                }
            }
            if(!deu_velha){
                break;
            }
        }
        if(deu_velha){
            this.#resetarTabuleiro();
            alert("Deu velha!");
            return true;
        }
        return false;
    }

    getVitorias(){
        return [this.#vitorias_0, this.#vitorias_1];
    }
}
