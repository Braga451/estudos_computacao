function verificaDado(x){
	if(typeof(x) == "number"){
		console.log("Numero");
	}
	else if(typeof(x) == "boolean"){
		console.log("Boleano");
	}
	else if(typeof(x) == "string"){
		console.log("String");
	}
}
verificaDado(1);
verificaDado(true);
verificaDado("Abc");

