function habilitacaoIdade(idade){
	if(idade >= 18){
		console.log(`Voce tem ${idade} e ja pode tirar a habilitacao`);
	}
	else{
		console.log(`Voce tem ${idade} e nao pode tirar a habilitacao`);
	}
}
habilitacaoIdade(18);
habilitacaoIdade(17);
