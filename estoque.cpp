#include<iostream>
#include<string.h>
#include "estoque.h"

#define MAXTAM 100
typedef char String[MAXTAM];
using namespace std;

double valorTotal;

void cadastrarProduto(Produto estoqueProdutos[5], Produto &produto, String nomeProduto, int qtdProduto, int &contador, double valorUnitario){
		int codigoUnico = contador + 1;
		
		produto.IDProduto = codigoUnico;
		strcpy(produto.NMProduto, nomeProduto);
		produto.QTDProduto = qtdProduto;
		produto.ValorUnitario = valorUnitario;	

		estoqueProdutos[contador] = produto;	
}

void listarProdutos(Produto estoqueProdutos[5]){
	Estoque estoque;
	for(int i=0;i<5;i++){
		if(estoqueProdutos[i].IDProduto == i+1){
			cout << "Codigo: " << estoqueProdutos[i].IDProduto << " 	";
			cout << "Nome: " << estoqueProdutos[i].NMProduto << "  ";
			cout << "Quantidade: " << estoqueProdutos[i].QTDProduto << "  ";
			cout << "Valor unitario: R$:" << estoqueProdutos[i].ValorUnitario <<"\n";
		}else{
			continue;
		}		

		calculaValorTotalProduto(estoqueProdutos[i].QTDProduto, estoqueProdutos[i].ValorUnitario, estoque);

	}	
}

double calculaValorTotal(Produto estoqueProdutos[5], Estoque &estoque){
	
	valorTotal = 0;
	for(int i=0;i<5;i++){
		if(estoqueProdutos[i].IDProduto == i+1){
			valorTotal = valorTotal + (estoqueProdutos[i].ValorUnitario * estoqueProdutos[i].QTDProduto);

		}else{
			continue;
		}	
	}
	estoque.ValorTotal = valorTotal;
	return valorTotal;
}

double calculaValorTotalProduto(int qtdProduto, double valorUnitario, Estoque &estoque){
	
	double valor;
	valor = qtdProduto * valorUnitario;
	
	estoque.ValorTotalProduto = valor;	
	return estoque.ValorTotalProduto;
}

bool obterProdutoPorNome(Produto estoqueProdutos[5], String nome){
	int FLAG = 0;
	
	for(int i=0;i<5;i++){
		
		if(strcmp(nome, estoqueProdutos[i].NMProduto) == 0){
			
			cout << "Codigo: " << estoqueProdutos[i].IDProduto << " 	";
			cout << "Nome: " << estoqueProdutos[i].NMProduto << "  ";
			cout << "Quantidade: " << estoqueProdutos[i].QTDProduto << "  ";
			cout << "Valor unitario: R$:" << estoqueProdutos[i].ValorUnitario <<"\n";

			FLAG = 1;
		}
	}
	
		if(FLAG == 0){
			cout << "Nenhum produto encontrado!";
		}
}

double venderProduto(Produto estoqueProdutos[5], int idProduto, int qtdProduto){
	
	double valorAtualizado;

	for(int i=0;i<5;i++){
		
		if(estoqueProdutos[i].IDProduto == idProduto && estoqueProdutos[i].QTDProduto > 0 ){
			estoqueProdutos[i].QTDProduto = estoqueProdutos[i].QTDProduto - qtdProduto;
			valorAtualizado = valorTotal - (estoqueProdutos[i].ValorUnitario * qtdProduto);
		}
	}
}



