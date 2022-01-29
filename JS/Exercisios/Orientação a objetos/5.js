class ContaBancaria{
    constructor(saldo_conta_corrente = 0, saldo_poupanca = 0, juros_poupanca = 0){
        this.saldo_conta_corrente = saldo_conta_corrente;
        this.saldo_poupanca = saldo_poupanca;
        this.juros_poupanca = juros_poupanca / 100;
    }

    deposito(valor){
        this.saldo_conta_corrente += valor;
    }

    saque(valor){
        this.saldo_conta_corrente -= valor;
    }

    tranferirContaCorrentePoupanca(valor){
        if(valor > this.saldo_conta_corrente){
            console.log("Valor acima do saldo!");
        }
        else{
            this.saldo_conta_corrente -= valor;
            this.saldo_poupanca += valor + (valor * this.juros_poupanca);
        }
    }
}

class ContaEspecial extends ContaBancaria{
    constructor(saldo_conta_corrente = 0, saldo_poupanca = 0, juros_poupanca = 0){
        super(saldo_conta_corrente, saldo_poupanca, juros_poupanca * 2);
    }
}

const contaA = new ContaBancaria(100, 0, 50);
contaA.deposito(100);
contaA.tranferirContaCorrentePoupanca(50);
console.log(contaA);
const contaB = new ContaEspecial(100, 0, 25);
contaB.deposito(100);
contaB.tranferirContaCorrentePoupanca(50);
console.log(contaB);