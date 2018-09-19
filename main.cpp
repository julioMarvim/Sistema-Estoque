#include <iostream>
#include <string.h>
#include <stdlib.h>
#include"estoque.h"


using namespace std;
extern double valorTotal;
int main() {
	int opcao = 0;
	int contador = 0;
	Estoque estoque;
	Produto estoqueProdutos[5];
	int qtd;
	double valor;
	String nome;
	Produto produto;

	do{
		cout << "\n\n\n			      * * * * CADASTRO DE PRODUTOS * * * *\n\n\n";
		cout << "\n Para CADASTRAR PRODUTO digite: 1";
		cout << "\n Para CONSULTAR PRODUTO digite: 2";
		cout << "\n Para LISTAR PRODUTOS digite: 3";
		cout << "\n Para VIZUALIZAR BALANCETE DO ESTOQUE digite: 4\n\n\n";
		
		cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque) << "\n\n\n";
		cout << "OPCAO: ";
		cin >> opcao;
		fflush(stdin);
		
		system("cls");
		switch(opcao){
			case 1:
				cout << "			      * * * * CADASTRO DE PRODUTOS * * * *\n\n\n";
				cout << "--------------------------------------CADASTRO DE PRODUTOS-------------------------------------\n\n\n";
				
				
				
				cout << "	NOME: ";
				gets(nome);
				cout <<"	QUANTIDADE: ";
				cin >> qtd;
				cout << "	VALOR UNITARIO: ";
				cin >> valor;
				
				cadastrarProduto(estoqueProdutos, produto, nome, qtd, contador, valor);
				
				cout << "\n\n	Produto cadastrado com sucesso!";
				while(opcao == 1){
					contador++;
					break;
				};
					cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
				
				cout << "\n\n\n-----------------------------------------------------------------------------------------------\n\n\n";
				break;
			case 2:
				cout << "			      * * * * CADASTRO DE PRODUTOS * * * *\n\n\n";
				cout << "--------------------------------------CONSULTA DE PRODUTOS-------------------------------------\n\n\n";
				
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
						char opcaoCadastro;
						
						cout << "\n Para VENDER PRODUTO digite: (v)";
						cout << "\n Para ATUALIZAR PRODUTO digite: (a)\n";
						
						cout << "OPCAO: ";
						cin >> opcaoCadastro;

						if(opcaoCadastro == 'v'){
							cout << "Para VENDER algum dos porodutos encontrado informe o CODIGO: ";
							cin >> codEscolhido;
							cout <<"\n";
							cout << "Informe a quantidade desejada: ";
							cin >> qtdEscolhida;
							cout <<"\n\n";
								
							venderProduto(estoqueProdutos, codEscolhido, qtdEscolhida, estoque);
							
							cout << "\n\n	VENDA realizada com sucesso!";
						
							cout << "ESTOQUE ATUALIZADO:\n\n";
							listarProdutos(estoqueProdutos);
								
							cout <<"\n\n";
							cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
							cout << "\n\n\n-----------------------------------------------------------------------------------------------\n\n\n";
							break;
						}
						
						if(opcaoCadastro == 'a'){
							cout << "Para ATUALIZAR algum dos porodutos encontrado informe o CODIGO: ";
							cin >> codEscolhido;								
							fflush(stdin);
								
							cout << "	NOME: ";
							gets(nome);
							cout <<"	QUANTIDADE: ";
							cin >> qtd;
							cout << "	VALOR UNITARIO: ";
							cin >> valor;
							cout <<"\n\n";
								
							atualizarEstoque(estoqueProdutos, codEscolhido, nome, qtd, valor);
							cout << "\n\n Produto ATUALIZADO com sucesso!";
								
							cout << "\n\nESTOQUE ATUALIZADO:\n\n";
							listarProdutos(estoqueProdutos);
								
							cout <<"\n\n";
							cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
							cout << "\n\n\n-----------------------------------------------------------------------------------------------\n\n\n";
							break;
						}
					continue;
					}
				cout << "\n\n\n-----------------------------------------------------------------------------------------------\n\n\n";
				break;
			case 3:
				cout << "			      * * * * CADASTRO DE PRODUTOS * * * *\n\n\n";
				cout << "----------------------------------------LISTA DE PRODUTOS--------------------------------------\n\n\n";
					
					listarProdutos(estoqueProdutos);
					cout <<"\n\n";
					cout << "						VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
				
				cout << "\n\n\n-----------------------------------------------------------------------------------------------\n\n\n";
				break;
			case 4:
				cout << "			      * * * * CADASTRO DE PRODUTOS * * * *\n\n\n";
				cout << "----------------------------------------BALANCETE DE ATIVIDADES--------------------------------------\n\n\n";
				int sair;
					cout << "VALOR TOTAL VENDIDO: R$:"	<< estoque.ValorTotalVendido;		
					cout <<"\n\n";
					cout << "VALOR TOTAL EM ESTOQUE: R$:" << calculaValorTotal(estoqueProdutos, estoque);
					
					cout << "\n\nPara ENCERRA O SISTEMA digite 0: ";
					cin >> sair;
					
					if(sair == 0){
						cout << "			      * * * * OBRIGADO VOLTE SEMPRE!! * * * *\n\n\n";					
									
						cout << "\n\n\n-----------------------------------------------------------------------------------------------\n\n\n";
						return 0;
				   }
				   break;
			default:
                cout << "Digite uma opcao valida\n";			
		}
		
	}while(opcao);
	return 0;
}


