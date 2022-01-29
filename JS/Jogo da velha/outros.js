function jogar(){
    const id_jogo = document.getElementById("jogo");
    const id_btn_jogar = document.getElementById("btn-jogar"); 
    id_btn_jogar.style.display = "none";
    id_jogo.style.display = "";
}

function alteraTabuleiroHtml(){
    const tabuleiro = jogo.getTabuleiro();
    let posicoes = {
        "0,0": 1,
        "0,1": 2,
        "0,2": 3,
        "1,0": 4,
        "1,1": 5,
        "1,2": 6,
        "2,0": 7,
        "2,1": 8,
        "2,2": 9
    }
    for(let x = 0; x < 3; x++){
        for(let y = 0; y < 3; y++){
            let string_posicao = x + "," + y;
            let posicao = document.getElementById(`posicao-${posicoes[string_posicao]}`)
            if(tabuleiro[x][y] != -1){
                posicao.innerHTML = tabuleiro[x][y] == 0 ? "X" : "O";
            }
            else{
                posicao.innerHTML = "&nbsp;";
            }
        }
    }
    if(jogo.verificarVitorias()){
        for(let x = 1; x < 10; x++){
            let posicao = document.getElementById("posicao-"+ x);
            posicao.innerHTML = "&nbsp;";
        }
        const vitorias_x = document.getElementById("vitorias-x");
        const vitorias_y = document.getElementById("vitorias-o");
        const vitorias_totais = jogo.getVitorias();
        vitorias_x.innerText = `Vitorias de X : ${vitorias_totais[0]}`;
        vitorias_y.innerText = `Vitorias de O: ${vitorias_totais[1]}`;
    }
}

function posicaoClick(posicao){
    if(posicao.target.innerHTML != "&nbsp;"){
        alert("Posição já preenchida!");
    }
    else{
        const posicao_id = posicao.target.id.replace("posicao-", "");
        jogo.inserirPosicaoTabuleiro(posicao_id, jogador.retornaJogador());
        jogador.alterarJogador();
        alteraTabuleiroHtml();
    }
}

const btn_jogar_id = document.getElementById("btn-jogar");
btn_jogar_id.addEventListener("click", jogar);
const jogador = new Jogador();
const jogo = new JogoDaVelha();
for(let x = 1; x < 10; x++){
    let posicao = document.getElementById("posicao-"+ x);
    posicao.addEventListener("click", posicaoClick.bind(posicao));
}