const verificarElementos = (array) =>{
	if(array.length > 5){
		console.log("Muitos elementos!");
	} 
	else{
		console.log("Poucos elementos!");
	}
}
let a = [1,2,3,4,5,6];
let b = [1,2,3];
verificarElementos(a);
verificarElementos(b);
