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
					printf("Nao ha valores a ser exibido!\n\n");
				}else {
					imprime(topoPilha);
				}   
				printPause();
				break;
			case 4:
				if(vazio(topoPilha)){
					printf("Voce nao possue saldo!\n\n");
				}else {
					total(topoPilha);	
				}
				printPause();
				break;	 
            default:
                printf("Opcao invalida!\n\n");
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
void deposito(controlaNos *topo, int vlrDeposito){
	controlaNos novoNo = NULL;
	int senha = 4221;
	int userSenha = 0;
	novoNo = (controlaNos) malloc(sizeof(nos));
	if(novoNo == NULL)
	{
		printf("O valor nao foi depositado!\n\n");
		printPause();
	}else if((vlrDeposito != 0)&&(vlrDeposito >0))
		{
			if(vlrDeposito >= 1000)
			{
				printf("PARA DEPOSITOS ACIMA DE 1.000,00 SERA NECESSARIO SENHA DO FAVORECIDO!!!\n\n");
				printf("Favor, informe sua senha para concluir o deposito!\n");
				scanf("%d",&userSenha);	
				if(senha == userSenha)
				{
					printf("Deposito realizado com sucesso!\n\n");
					novoNo->valor=vlrDeposito;
					novoNo->proximoNo = *topo;
					*topo=novoNo;
					printPause();
				}else
				{
					printf("Senha incorreta!\n\n");
				}
				printPause();
			}
        	printf("Deposito realizado com sucesso!\n\n");
		}else
		{
			printf("ERRO - Digite valores numericos acima de 0\n\n");
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
	controlaNos saldo = NULL;
	while(topo != NULL){
		valorSaldo = valorSaldo + topo->valor;
		topo=topo->proximoNo;
	}
	printf("Seu saldo eh de RS%.2f\n\n", valorSaldo);
}
