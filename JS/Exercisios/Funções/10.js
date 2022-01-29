function imprimeParDecrementar(num){
	for(num; num >= 0; num--){
		console.log(num % 2 == 0 ? num : " ");
	}
}
imprimeParDecrementar(10);
