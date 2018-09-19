#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAXTAM 100
typedef char String[MAXTAM];


typedef struct{
	int IDProduto;
	String NMProduto;
	int QTDProduto;
	double ValorUnitario;
}Produto;

typedef struct{
	double ValorTotal;
	double ValorTotalProduto;
	double ValorTotalVendido;
	int QTDTotal;
}Estoque;

void cadastrarProduto(Produto estoqueProdutos[5], Produto &produto, String nomeProduto, int qtdProduto, int &contador, double valorUnitario);
void listarProdutos(Produto estoqueProdutos[5]);
double calculaValorTotal(Produto estoqueProdutos[5], Estoque &estoque);
bool obterProdutoPorNome(Produto estoqueProdutos[5], String nome);
double venderProduto(Produto estoqueProdutos[5], int idProduto, int qtdProduto, Estoque &estoque);
double calculaValorTotalProduto(int qtdProduto, double valorUnitario, Estoque &estoque);
double atualizarEstoque(Produto estoqueProdutos[5], int idProduto, String nomeProduto, int qtdProduto, double vlUnitario);


#endif
