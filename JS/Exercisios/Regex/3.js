const regex = /Marca: ?[(Nike|Adidas|Pumas|Asics)]/;
let teste = "Marca: Nike";
console.log(regex.test(teste));
teste = "Marca:Nike"
console.log(regex.test(teste));
teste = "Marca: Teste"
console.log(regex.test(teste));