#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


struct Sistema{
	
	int codigo;
	char nome[20];
	int estoque;
	float preco;
	
};

int main(){
	setlocale(LC_ALL,"portuguese");
	
	struct Sistema vendas[50];
	int contador = 0;
	int continuar, i, continuar2;
	int codigodoproduto, pagamento, cartao, novacompra;
	float troco, cedula;
	
	printf("=-=-=-= Sistema de Vendas =-=-=-=\n\n");
	do{
		printf("Digite o nome do produto: ");
		scanf("%s", vendas[contador].nome);
		
		printf("Digite o c�digo do produto: ");
		scanf("%d", &vendas[contador].codigo);
		
		printf("Digite o pre�o do produto: ");
		scanf("%f", &vendas[contador].preco);
		
		printf("Digite o estoque do produto: ");
		scanf("%d", &vendas[contador].estoque);
		
		contador++;
		
		printf("\nDeseja cadastrar mais algum produto?: [1]Sim ou [2]N�o.\n");
        scanf("%d", &continuar);
		
	}while (continuar == 1);
	
	printf("=-=-=-= Lista de produtos =-=-=-=\n\n");
	for (i = 0; i < contador; i++){
		printf("Nome do produto: %s.\n", vendas[i].nome);
		printf("C�digo do produto: %d.\n", vendas[i].codigo);
		printf("Pre�o do produto: %.2f reais.\n", vendas[i].preco);
		printf("Estoque do produto: %d.\n", vendas[i].estoque);
		printf("\n");
	}
	
	printf("Deseja comprar algum produto?: [1]Sim ou [2]N�o.\n")/
	scanf("%d", &continuar2);
	
	switch(continuar2){
		case 1:
			do{ 
			printf("Digite o c�digo do produto que deseja comprar: ");
			scanf("%d", &codigodoproduto);
			

			for (i = 0; i < contador; i++){
				if (codigodoproduto == vendas[i].codigo){
					printf("Produto selecionado: %s.\n", vendas[i].nome);
					printf("Como deseja pagar?: [1]C�dula ou [2]Cart�o\n");
					scanf("%d", &pagamento);
					
					if (pagamento == 1){
						printf("Quanto reais ir� inserir?: ");
						scanf("%f", &cedula);
					
						if (cedula == vendas[i].preco){
							printf("Pagamento realizado!\n\n");
						}
						if (cedula > vendas[i].preco){
							troco = (cedula - vendas[i].preco);
							printf("Pagamento realizado! Seu troco � de %.2f reais.\n\n", troco);
						}
						else{
							printf("O valor inserido � menor que o pre�o do produto.\n\n");
						}
					}
					if (pagamento == 2){
						printf("Deseja pagar por [1]Cr�dito ou [2]D�bito?\n");
						scanf("%d", &cartao);
						
						if(cartao == 1){
							printf("Pagamento realizado! A compra ser� mostrada na sua fatura.\n\n");
							
						}
						if(cartao == 2){
							printf("Pagamento realizado!\n\n");
							
						}
					}
				}	
				else{
					printf("Produto n�o est� cadastrado!\n\n");
					}	
				}
			printf("Deseja comprar outro produto? [1]Sim ou [2]N�o: ");
			scanf("%d", &novacompra);
			printf("\n");
			}while (novacompra == 1);
			
		case 2: 
			printf("Saindo...");
			break;
		
	}
	system("pause");
}