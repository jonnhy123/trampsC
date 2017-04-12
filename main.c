#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	float valor;
	struct no *proximoNo;
}nos;

typedef nos *controlaNos;

void printPause();//Pausa a execução e limpa a tela
void deposito(controlaNos *topo, int empilha);//Empilha valores
void saque(controlaNos *topo); //Desempilha valores
void imprime(controlaNos topo); //Imprime a pilha
int vazio(controlaNos topo); //Verifica se a pilha esta vazia
int total(controlaNos topo);

int main(int argc, char *argv[]) {
	controlaNos topoPilha = NULL;
    int menu = 0, num = 0;
    float vlrDeposito = 0;
    
    while (menu != 5) {
        printf("Escolha uma opcao:\n"
               "1 - Deposito\n"
               "2 - Saque\n"
               "3 - Extrato\n"
               "4 - Total Saldo\n"
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
			case 4:
				if(vazio(topoPilha)){
					printf("A pilha esta vazia!\n");
				}else {
					total(topoPilha);	
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

//função que pause e limpa a tela
void printPause(){
	system("pause");//comando que pausa tela
	system("cls");//comando que limpa a tela
}

//Esta função vai tirar o último nó da pilha, e retirá-lo de lá
void saque(controlaNos *topo){
	controlaNos popNo = NULL;
	float valorSaque = 0;
	
	printf("Favor, informe o valor desejado(a)\n");
	scanf("%f",&valorSaque);
/*	
	if(){
		printf("Saque no valor %.2f realizado com sucesso.", popNo->valor);
	}else{
		
	}	
*/	
	popNo = *topo;
	*topo = (*topo)->proximoNo;
	
	free(popNo);
}

//função que vai inserir elementos na pilha
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

//função que verefica se a função está vazia
int vazio(controlaNos topo){
	return (topo == NULL);
}

//função que exibe os valores na pilha
void imprime(controlaNos topo){
	while(topo != NULL){
		printf("-->%.2f\n", topo->valor);
		topo=topo->proximoNo;
	}
}

//função que soma os valores da conta do usúario 
int total(controlaNos topo){
	float valorSaldo = 0;
	while(topo != NULL){
		valorSaldo = valorSaldo + topo->valor;
	}
	printf("Seu saldo eh de %.2f", valorSaldo);
}
