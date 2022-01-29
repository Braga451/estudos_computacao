let numero = 12;
let naoEPrimo = false;
for(let x = 2; x < numero; x++){
	if(numero % x == 0){
		naoEPrimo = true;
	}
}
if(naoEPrimo == true){
	console.log("Nao e primo");
}
else{
	console.log("E primo");
}
