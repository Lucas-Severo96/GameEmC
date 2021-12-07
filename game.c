#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();

void mostrarInfo(Calcular calc);

int pontos = 0;

int main() {

	//Deve ser chamado apenas 1 vez;
	srand(time(NULL));

	jogar();

	return 0;
}

void jogar() {

}

void mostrarInfo(Calcular calc) {
	char op[25];

	if(calc.operacao == 0) { //0 == Somar
		sprintf(op, "Somar");
	}else if(calc.operacao == 1) { //1 == Diminuir
		sprintf(op, "Diminuir");
	}else if(calc.operacao == 2) { //2 == Multiplicar
		sprintf(op, "Multiplicar");
	}else {
		sprintf(op, "Operação Desconhecida");
	}
	printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperação: %s",
			calc.valor1, calc.valor2, calc.dificuldade, op );
}

int somar(int resposta, Calcular calc) {
	int resultado = calc.valor1 + calc.valor2;
	calc.resultado = resultado;
	int certo = 0; //0 == Errou, 1 == Acertou

	if(resposta == calc.resultado) {
		printf("Resposta Correta!\n");
		certo = 1;
	}else {
		printf("Resposta Errada!\n");
	}
	printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
	return certo;
}

int diminuir(int resposta, Calcular calc) {
	int resultado = calc.valor1 - calc.valor2;
	calc.resultado = resultado;
	int certo = 0; //0 == Errou, 1 == Acertou

	if(resposta == calc.resultado) {
		printf("Resposta Correta!\n");
		certo = 1;
	}else {
		printf("Resposta Errada!\n");
	}
	printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
	return certo;
}

int multiplicar(int resposta, Calcular calc) {

}
