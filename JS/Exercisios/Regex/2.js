const regex = /\w+ID\b/;
let teste = "AbCdID";
console.log(regex.test(teste));
teste = "ABC";
console.log(regex.test(teste));