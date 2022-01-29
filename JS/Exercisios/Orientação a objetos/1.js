class ContaBancaria{
	constructor(){
		this.saldo = 0;
	}
	deposito(quantidade){
		this.saldo += quantidade;
	}
	saque(quantidade){
		this.saldo -= quantidade;
	}	
}

const contaA = new ContaBancaria();
contaA.deposito(1000);
console.log(contaA.saldo);
contaA.saque(500);
console.log(contaA.saldo);

