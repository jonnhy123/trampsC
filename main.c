#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	float valor;
	struct no *proximoNo;
}nos;

typedef nos *controlaNos;

void printPause();//Pausa a execu��o e limpa a tela
void deposito(controlaNos *topo, int empilha);//Empilha valores
void sque(controlaNos *topo); //Desempilha valores
void imprime(controlaNos topo); //Imprime a pilha
int vazio(controlaNos topo); //Verifica se a pilha esta vazia

int main(int argc, char *argv[]) {
	controlaNos topoPilha = NULL;
    int menu = 0, num = 0;
    float vlrDeposito = 0;
    
    while (menu != 5) {
        printf("Escolha uma opcao:\n"
               "1 - Deposito\n"
               "2 - Saque\n"
               "3 - Extrato\n"
               "4 - Relatorios\n"
			   "5 - Encerrar sessao\n");
        scanf("%d",&menu);
        system("cls");
        switch (menu) {
            case 1:
                printf("Digite o valor do deposito:\n");
                scanf("%f",&vlrDeposito);
                system("cls");
                deposito(&topoPilha, vlrDeposito);
                break;
            case 2:
                if (vazio(topoPilha)) {
                    printf("Nao ha nada para desempilhar!\n");
                    printPause();
                }
                else {
                    saque(&topoPilha);
                }
                break;
            case 3:
				if(vazio(topoPilha)){
					printf("A pilha esta vazia!\n");
				}else {
					imprime(topoPilha);
				}   
				printPause();
				break; 
            default:
                printf("Opcao invalida!\n");
                printPause();
                break;
        }
    }
    
    system("pause");
    return 0;
}

//fun��o que pause e limpa a tela
void printPause(){
	system("pause");//comando que pausa tela
	system("cls");//comando que limpa a tela
}

//Esta fun��o vai tirar o �ltimo n� da pilha, e retir�-lo de l�
void saque(controlaNos *topo){
	controlaNos popNo = NULL;
	
	popNo = *topo;
	*topo = (*topo)->proximoNo;
	free(popNo);
}

//fun��o que vai inserir elementos na pilha
void deposito(controlaNos *topo, int empilha){
	controlaNos novoNo = NULL;
	
	novoNo = (controlaNos) malloc(sizeof(nos));
	
	if(novoNo == NULL){
		printf("O valor nao foi depositado!\n");
		printPause();
	}else {
		novoNo->valor=empilha;
		novoNo->proximoNo = *topo;
		*topo=novoNo; 
	}
}

//fun��o que verefica se a fun��o est� vazia
int vazio(controlaNos topo){
	return (topo == NULL);
}

//fun��o que exibe os valores na pilha
void imprime(controlaNos topo){
	while(topo != NULL){
		printf("-->%.2f\n", topo->valor);
		topo=topo->proximoNo;
	}
} 
