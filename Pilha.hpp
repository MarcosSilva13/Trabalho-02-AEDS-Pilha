#ifndef PILHA_H
#define PILHA_H

#define MAXTAM 10
#define MAX_ENTREGA 7

typedef struct
{
   int codProduto;
   char nome[20];
   float preco;
} Produto;

typedef struct
{
   int codPedido;
   Produto produtos[MAXTAM];
   float valor_pedido = 0;
   float distancia = 0;
} Pedido;

typedef struct
{
   Pedido Pilha[MAX_ENTREGA];
   int Topo;
} TPilha;

void menu(); // menu do programa

// TADS PILHA
void TPilha_Inicializa(TPilha *p);
int TPilha_Vazia(TPilha *p);
int TPilha_Cheia(TPilha *p);
void TPilha_Empilha(TPilha *p, Pedido ped);
void TPilha_Desempilha(TPilha *p, Pedido *ped);
void TPilha_Imprime(TPilha *p);
int TPilha_Tamanho(TPilha *p);

// Funções extras
void IncluirPedido(Pedido pedido[], int contador, int *pont);                  // faz o cadastro do pedido
void ListarPedidos(Pedido pedido[], int contador);                             // lista todos os pedidos
void Cardapio();                                                               // exibe o cardápio
void ConsultaPedido(Pedido pedido[]);                                          // consulta um pedido
int PesquisaPedido(Pedido pedido[], int cod, int contador);                    // pesquisa o pedido
void ListaEntrega(TPilha *mochila, Pedido pedido[], int contador);             // prepara a mochila com os pedidos
void ImprimeEntrega(TPilha *mochila);                                          // exibe os pedidos na mochila
void LancarEntrega(TPilha *mochila, Pedido pedido[], int contador, int *pont); // lança um pedido para entrega, removendo ele da mochila

#endif