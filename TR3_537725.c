#include <stdio.h>
#include <stdlib.h>


int main(){

	unsigned int vetor[200]; //criando um vetor de 200 posicoes
	int num = 0; //variavel que tem o objetivo de guadar os números digitados pelo usuario
	int pos_vet = 0; //variavel que atribui a posição que o número ficará com o bitset
	int i; //variavel que ira iterar pelo vetor de 200 posicoes
	int j; //variavel que ira iterar pelo vetor menor de 32 bits

	for (i = 0; i < 200; i++){ //preechendo as posicoes do vetor com o numero 0
		vetor[i] = 0; 
	}

	while (num != -1){ //condicao de parada da leitura de numeros 

		printf("Digite um número entre 0  e 5000\n");
		scanf("%d", &num );

		if (num >= 0 && num <= 5000){ //apenas numeros entre 0 e 5000 sao salvos
			vetor[num/32] = vetor[num/32] | 2147483648 >> (num % 32); //operacao logica de ou para ativar o bit correspondente 
		}
	}

	for ( i = 0; i <= 199; i ++){ //pecorrendo pelo maior vetor
		for (j = 0; j <= 31; j++){ //pecorrendo a patir do menor vetor
			if (vetor[i] & (2147483648 >> j)){ //verificando se o bit está ligado
				printf("%d ", j + pos_vet );
			}
		}
		pos_vet = pos_vet + 32; //para ir iterando pelas posicoes do vetor
	}
	return 0;  
}

