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
		
		printf("Digite o código do produto: ");
		scanf("%d", &vendas[contador].codigo);
		
		printf("Digite o preço do produto: ");
		scanf("%f", &vendas[contador].preco);
		
		printf("Digite o estoque do produto: ");
		scanf("%d", &vendas[contador].estoque);
		
		contador++;
		
		printf("\nDeseja cadastrar mais algum produto?: [1]Sim ou [2]Não.\n");
        scanf("%d", &continuar);
		
	}while (continuar == 1);
	
	printf("=-=-=-= Lista de produtos =-=-=-=\n\n");
	for (i = 0; i < contador; i++){
		printf("Nome do produto: %s.\n", vendas[i].nome);
		printf("Código do produto: %d.\n", vendas[i].codigo);
		printf("Preço do produto: %.2f reais.\n", vendas[i].preco);
		printf("Estoque do produto: %d.\n", vendas[i].estoque);
		printf("\n");
	}
	
	printf("Deseja comprar algum produto?: [1]Sim ou [2]Não.\n")/
	scanf("%d", &continuar2);
	
	switch(continuar2){
		case 1:
			do{ 
			printf("Digite o código do produto que deseja comprar: ");
			scanf("%d", &codigodoproduto);
			

			for (i = 0; i < contador; i++){
				if (codigodoproduto == vendas[i].codigo){
					printf("Produto selecionado: %s.\n", vendas[i].nome);
					printf("Como deseja pagar?: [1]Cédula ou [2]Cartão\n");
					scanf("%d", &pagamento);
					
					if (pagamento == 1){
						printf("Quanto reais irá inserir?: ");
						scanf("%f", &cedula);
					
						if (cedula == vendas[i].preco){
							printf("Pagamento realizado!\n\n");
						}
						if (cedula > vendas[i].preco){
							troco = (cedula - vendas[i].preco);
							printf("Pagamento realizado! Seu troco é de %.2f reais.\n\n", troco);
						}
						else{
							printf("O valor inserido é menor que o preço do produto.\n\n");
						}
					}
					if (pagamento == 2){
						printf("Deseja pagar por [1]Crédito ou [2]Débito?\n");
						scanf("%d", &cartao);
						
						if(cartao == 1){
							printf("Pagamento realizado! A compra será mostrada na sua fatura.\n\n");
							
						}
						if(cartao == 2){
							printf("Pagamento realizado!\n\n");
							
						}
					}
				}	
				else{
					printf("Produto não está cadastrado!\n\n");
					}	
				}
			printf("Deseja comprar outro produto? [1]Sim ou [2]Não: ");
			scanf("%d", &novacompra);
			printf("\n");
			}while (novacompra == 1);
			
		case 2: 
			printf("Saindo...");
			break;
		
	}
	system("pause");
}