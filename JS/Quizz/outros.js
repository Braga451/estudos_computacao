const jogo = new Jogo();

const sleep = (delay) => new Promise((resolve) => setTimeout(resolve, delay));

async function enviarResposta(tag){
    const id = tag.target.id;
    const resposta = jogo.responder(id);
    const tags = {
        A : document.getElementById("A"),
        B : document.getElementById("B"),
        C : document.getElementById("C"),
        D : document.getElementById("D")
    }
    if(resposta){
        const acerto_tag = document.getElementById("acertos");
        const acerto_numero = acerto_tag.innerText.replace("Acertos: ", "");
        acerto_tag.innerText = "Acertos: " + (Number(acerto_numero) + 1);
        for(let element in tags){
            tags[element].style.color = "lime";
        }
        await sleep(800);
    }
    else{
        const erro_tag = document.getElementById("erros");
        const erro_numero = erro_tag.innerText.replace("Erros: ", "");
        erro_tag.innerText = "Erros: " + (Number(erro_numero) + 1);
        for(let element in tags){
            tags[element].style.color = "red";
        }
        await sleep(800);
    }
    for(let element in tags){
        tags[element].style.color = "black";
    }
    pegarPergunta();
}

function resetaJogo(){
    const acerto_tag = document.getElementById("acertos");
    const acerto_numero = acerto_tag.innerText.replace("Acertos: ", "");
    const erro_tag = document.getElementById("erros");
    const erro_numero = erro_tag.innerText.replace("Erros: ", "");
    if(Number(acerto_numero) > Number(erro_numero)){
        alert("Você venceu!");
    }
    else{
        alert("Você perdeu!");
    }
    acerto_tag.innerText = "Acertos: 0";
    erro_tag.innerText = "Erros: 0";
    jogo.resetaJogo();
    pegarPergunta();
}

function pegarPergunta(){
    const pergunta = jogo.returnPergunta()
    if(pergunta.pergunta == undefined){
        resetaJogo();
        return;
    }
    document.getElementById("pergunta").innerText = pergunta.pergunta;
    for(let x = 0; x < 4; x++){
        const base = 65;
        const char = String.fromCharCode(base + x);
        const tag = document.getElementById(char);
        tag.innerText = pergunta.respostas[x][0];
        tag.addEventListener("click", enviarResposta);
    }
}

pegarPergunta();