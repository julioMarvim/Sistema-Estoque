#include <iostream>
#include <string.h>
#include"estoque.h"

using namespace std;
extern double valorTotal;
int main() {
	int opcao = 0;
	int contador = 0;
	Estoque estoque;
	Produto estoqueProdutos[5];

	do{
		cout << "\n Para CADASTRAR PRODUTO digite: 1";
		cout << "\n Para CONSULTAR PRODUTO digite: 2";
		cout << "\n Para LISTAR PRODUTOS digite: 3";
		cout << "\n Para SAIR digite: 4\n\n\n";
		
		cin >> opcao;
		fflush(stdin);
		
		switch(opcao){
			case 1:
				cout << "-----------------------CADASTRO DE PRODUTOS------------------------\n\n\n";
				
				int qtd;
				double valor;
				String nome;
				Produto produto;
				
				cout << "	NOME: ";
				gets(nome);
				cout <<"	QUANTIDADE: ";
				cin >> qtd;
				cout << "	VALOR UNITARIO: ";
				cin >> valor;
				
				cadastrarProduto(estoqueProdutos, produto, nome, qtd, contador, valor);
				
				while(opcao == 1){
					contador++;
					break;
				};
					cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
				
				cout << "\n\n\n---------------------------------------------------------------------\n\n\n";
				break;
			case 2:
				cout << "\n\n\n-------------------------CONSULTAR PRODUTO-------------------------\n\n\n";
				
				String nomeProduto;
				cout << "Digite o nome do Produto: ";
				gets(nomeProduto);
				cout <<"\n";
				fflush(stdin);
				
				bool produtoEncontrado;
				produtoEncontrado = obterProdutoPorNome(estoqueProdutos, nomeProduto);
				cout <<"\n\n";
				if(produtoEncontrado){
					
						int codEscolhido;
						int qtdEscolhida;
						
						cout << "Para vernder algum poroduto encontrado informe o CODIGO: ";
						cin >> codEscolhido;
						cout <<"\n";
						cout << "Informe a quantidade desejada: ";
						cin >> qtdEscolhida;
						cout <<"\n\n";
						venderProduto(estoqueProdutos, codEscolhido, qtdEscolhida);
					}
				cout << "\n\n\n---------------------------------------------------------------------\n\n\n";
				break;
			case 3:
				cout << "-------------------------PRODUTOS CADASTRADOS-------------------------\n\n\n";
					
					listarProdutos(estoqueProdutos);
					cout <<"\n\n";
					cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
				
				cout << "\n\n\n--------------------------------------------------------------------\n\n\n";
				break;
			case 4:
				cout << "-------------------------SAIR-------------------------\n\n\n";
					
					
					
				
				cout << "\n\n\n--------------------------------------------------------------------\n\n\n";
				break;
		}
		
	}while(opcao);
	return 0;
}


