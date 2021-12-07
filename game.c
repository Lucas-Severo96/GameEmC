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
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main() {

	//Deve ser chamado apenas 1 vez;
	srand(time(NULL));

	jogar();

	return 0;
}

void jogar() {
	Calcular calc;
	int dificuldade;

	printf("Informe o nível de dificuldade desejado [1, 2, 3 ou 4]: ");
	fflush(stdout);
	scanf("%d", &dificuldade);
	calc.dificuldade = dificuldade;

	//Gera um valor (int) randômico entre o e 2
	//0 == somar, 1 == diminuir, 2 == multiplicar
	calc.operacao = rand() % 3;

	if(calc.dificuldade == 1) {
		//fácil - Valores de 0 a 10
		calc.valor1 = rand() % 11;
		calc.valor2 = rand() % 11;
	}else if(calc.dificuldade == 2) {
		//média - Valores de 0 a 100
		calc.valor1 = rand() % 101;
		calc.valor2 = rand() % 101;
	}else if(calc.dificuldade == 3) {
		//difícil - Valores de 0 a 1000
		calc.valor1 = rand() % 1001;
		calc.valor2 = rand() % 1001;
	}else if(calc.dificuldade == 4) {
		//insano - Valores de 0 a 10000
		calc.valor1 = rand() % 10001;
		calc.valor2 = rand() % 10001;
	}else {
		//ultra - Valores de 0 a 100000
		calc.valor1 = rand() % 100001;
		calc.valor2 = rand() % 100001;

	}
	int resposta;
	printf("Informe o resultado para a seguinte operação: ");

	//Somar
	if(calc.operacao == 0) {
		printf("%d + %d\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%d", &resposta);

		if (somar(resposta,calc)) {
			pontos += 1;
			printf("Você tem %d ponto(s).\n", pontos);
		}
	//Diminuir
	}else if(calc.operacao == 1) {
		printf("%d - %d\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%d", &resposta);

		if (diminuir(resposta,calc)) {
			pontos += 1;
			printf("Você tem %d ponto(s).\n", pontos);
		}
	//Multiplicar
	}else if(calc.operacao == 2) {
		printf("%d * %d\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%d", &resposta);

		if(multiplicar(resposta, calc)) {
			pontos += 1;
			printf("Você tem %d ponto(s).\n", pontos);
		}
	//Desconhecida
	}else {
		printf("A operação %d não é reconhecida.\n", calc.operacao);
	}

	//mostrarInfo
	mostrarInfo(calc);

	//Recomeçar o jogo?
	printf("Deseja continuar jogando? [1 - SIM, 0 - NÃO]\n");
	int continuar;
	fflush(stdout);
	scanf("%d", &continuar);

	if(continuar) {
		jogar();
	}else {
		printf("Você finalizou com %d ponto(s).\n", pontos);
		printf("Até a próxima.");
		exit(0);
	}
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
	printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperação: %s\n\n",
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
	int resultado = calc.valor1 * calc.valor2;
	calc.resultado = resultado;
	int certo = 0; //0 == Errou, 1 == Acertou

	if(resposta == calc.resultado) {
		printf("Resposta Correta!\n");
		certo = 1;
	}else {
		printf("Resposta Errada!\n");
	}
		printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
		return certo;
}
