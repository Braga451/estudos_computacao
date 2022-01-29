class CarrinhoDeCompras{
	constructor(){
		this.itens = []; // Lista de objetos com atributos nome, valor_fixo, valor_total, quantidade_total
		this.quantidade_total = 0;
		this.valor_total = 0;
	}

	adicionarItem(nome, quantidade, valor){
		let item = {};
		for(let x = 0; x < this.itens.length; x++){
			if(this.itens[x].nome == nome){
				const item_props = this.itens[x]
				item_props.quantidade_total += quantidade;
				item_props.valor_total = item_props.quantidade_total * item_props.valor_fixo;
				return;
			}
		}
		item = {
			nome : nome,
			valor_fixo : valor,
			valor_total : valor,
			quantidade_total : quantidade
		}
		this.itens.push(item);
	}

	removerItem(nome, quantidade){ // Remove x vezes de um objeto
		for(let x = 0; x < this.itens.length; x++){
			if(this.itens[x].nome == nome){
				const item_props = this.itens[x]
				item_props.quantidade_total -= quantidade;
				if(item_props.quantidade_total < 0){
					item_props.quantidade_total = 0;
				}
				item_props.valor_total = item_props.quantidade_total * item_props.valor_fixo;
				return;
			}
		}
	}

	deletarItem(nome){ // Deleta completamente o elemento
		for(let x = 0; x < this.itens.length; x++){
			if(this.itens[x].nome == nome){
				this.itens.splice(x, 1);
			}
		}
	}
}

const carrinho = new CarrinhoDeCompras();
carrinho.adicionarItem("Teste", 1, 150);
carrinho.adicionarItem("Teste", 1, 150);
carrinho.adicionarItem("Teste", 1, 150);
carrinho.adicionarItem("Teste", 1, 150);
carrinho.adicionarItem("Teste", 1, 150);
carrinho.removerItem("Teste", 6);
console.log(carrinho.itens);
carrinho.deletarItem("Teste");
console.log(carrinho.itens);