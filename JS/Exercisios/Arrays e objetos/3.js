let onibus = {
	rodas : 8,
	limite_passageiros : 40,
	portas : 2,
	exibir_propriedades : () => console.log(`Numero de rodas: ${onibus["rodas"]}\nLimite de passageiros:${onibus["limite_passageiros"]}\nNumero de portas: ${onibus["portas"]}`)
}
onibus.exibir_propriedades();
