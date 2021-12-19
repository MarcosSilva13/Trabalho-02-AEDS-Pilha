#include <iostream>
#include <windows.h>
#include "Pilha.hpp"
#include <iomanip>
#include <time.h>

using namespace std;

void menu()
{
    system("color 0E");
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        �                          DELIVERY                            �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 1 - INCLUIR NOVO PEDIDO                                      �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 2 - LISTAR PEDIDOS                                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 3 - VER CARDÁPIO                                             �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 4 - CONSULTAR PEDIDO                                         �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 5 - IMPRIMIR LISTA DE ENTREGA                                �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 6 - LANÇAR ENTREGA                                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 7 - SAIR                                                     �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������\n\n";
}

void TPilha_Inicializa(TPilha *p)
{
    p->Topo = -1; // Indica que a pilha está inicializada e vazia
}

int TPilha_Vazia(TPilha *p)
{
    if (p->Topo == -1)
    {
        return 1; // Retorno verdadeiro, a pilha está vazia
    }
    else
    {
        return 0; // Retorno falso, a pilha não está vazia
    }
}

int TPilha_Cheia(TPilha *p)
{
    if (p->Topo == MAX_ENTREGA - 1)
    {
        return 1; // Retorno verdadeiro, a pilha está cheia: 0 a 9 preenchidos
    }
    else
    {
        return 0; // Retorno falso, a pilha não está cheia
    }
}

void TPilha_Empilha(TPilha *p, Pedido ped)
{
    if (TPilha_Cheia(p) == 1)
    {
        cout << "\nPilha cheia\n";
    }
    else
    {
        p->Topo++;
        p->Pilha[p->Topo] = ped;
        // cout << "Valor empilhado: " << x << endl;
    }
}

void TPilha_Desempilha(TPilha *p, Pedido *ped)
{
    // int aux; // Receber o valor da pilha que será desempilhado
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nImpossível desempilhar. Pilha vazia\n";
    }
    else
    {
        *ped = p->Pilha[p->Topo];
        p->Topo--;
        // return x;
    }
}

void TPilha_Imprime(TPilha *p)
{
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nPilha vazia\n";
        return;
    }
    for (int i = p->Topo; i >= 0; i--)
    {
        if (i == p->Topo)
        {
            cout << "\nTopo -> " << p->Pilha[i].codPedido << "\n";
        }
        else
        {
            cout << "\t " << p->Pilha[i].codPedido << "\n";
        }
    }
}

void IncluirPedido(Pedido pedido[], int contador, int *pont)
{
    Pedido ped;
    Produto prod;
    // nomes dos produtos
    char produto[11][15] = {
        {'M', 'i', 's', 't', 'o', ' ', 'Q', 'u', 'e', 'n', 't', 'e', NULL, NULL, NULL},
        {'H', 'a', 'm', 'b', 'u', 'r', 'g', 'u', 'e', 'r', NULL, NULL, NULL, NULL, NULL},
        {'B', 'a', 'u', 'r', 'u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'B', 'u', 'r', 'g', 'u', 'e', 'r', NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'S', 'a', 'l', 'a', 'd', 'a', NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'E', 'g', 'g', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'B', 'a', 'c', 'o', 'n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'E', 'g', 'g', ' ', 'B', 'a', 'c', 'o', 'n', NULL, NULL, NULL, NULL},
        {'X', '-', 'C', 'a', 'l', 'a', 'b', 'r', 'e', 's', 'a', NULL, NULL, NULL, NULL},
        {'X', '-', 'P', 'i', 'c', 'a', 'n', 'h', 'a', NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'T', 'u', 'd', 'o', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    };

    // vetor de codigo dos produtos
    int codigo[11] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    // vetor de preços
    float preco[11] = {7.50, 8.10, 9.50, 10.50, 11.20, 12.15, 13.30, 14.30, 13.10, 13.50, 14.50};

    int cod, posicao, cont = 0, op = 0;

    cout << "*******************************************\n";
    cout << "*              FAZER PEDIDO               *\n";
    cout << "*******************************************\n\n";

    // verificando o vetor de pedidos se está cheio
    if (contador >= MAX_ENTREGA)
    {
        cout << "Limite de pedidos atingido! Você não pode fazer mais pedidos!\n\n";
        system("pause");
        system("cls");
    }
    else
    {

        srand(time(NULL));

        ped.codPedido = rand() % 10000; // gera codigo do pedido aleatorio

        cout << "O Codigo do seu pedido é: " << ped.codPedido << "\n\n";

        do
        {
            Cardapio();

            cout << "Informe o codigo do produto: ";
            cin >> cod;
            while (cod < 100 || cod > 110)
            {
                cout << "Codigo não existe, Informe outro: ";
                cin >> cod;
            }

            // for para pegar o codigo do produto e sua posição
            for (int i = 0; i < 11; i++)
            {
                if (cod == codigo[i])
                {
                    posicao = i;
                    break;
                }
            }

            // for para salvar o nome do produto na struct do produto
            for (int j = 0; j < 15; j++)
            {
                prod.nome[j] = produto[posicao][j];
            }

            prod.codProduto = codigo[posicao]; // salva o codigo do produto na struct
            prod.preco = preco[posicao];       // salva o preco do produto na struct

            ped.valor_pedido += preco[posicao]; // calcula o valor total do pedido

            ped.produtos[cont] = prod; // salva o produto na struct do pedido
            cont++;                    // controla os indices do vetor de produtos para ir salvando os pedidos um a um na posição

            cout << "\nProduto: " << prod.nome << " cadastrado com sucesso!\n\n";

            Sleep(1500);
            system("cls");

            cout << "Deseja pedir mais produtos? (1) - SIM (2) - NÃO\n";
            cin >> op;

            // para não dar bug caso digite 0 e mesmo assim ir para add novo produto
            while (op < 1 || op > 2)
            { 
                cout << "Opção não existe! Digite 1 ou 2\n";
                cin >> op;
            }

            if (cont == MAXTAM)
            {
                cout << "Limite de produtos atingido! Você não pode adicionar mais produtos!\n";
            }

        } while (op != 2 && cont < MAXTAM);

        cout << "\nAgora informe a sua distancia em KM: ";
        cin >> ped.distancia;

        // caso fosse digitado um valor negativo ex: -1
        while (ped.distancia < 0)
        { 
            cout << "\nDistancia invalida!! Informe um valor positivo: ";
            cin >> ped.distancia;
        }

        pedido[contador] = ped; // salva o pedido no vetor de pedidos

        cout << "\nPedido cadastrado com sucesso!\n\n";

        (*pont)++; // incrementa o valor do ponteiro mudando também o valor do contador

        Sleep(1500);
        system("cls");
    }
}

void Cardapio()
{
    // nomes dos produtos
    char produto[11][20] = {
        {'M', 'i', 's', 't', 'o', ' ', 'Q', 'u', 'e', 'n', 't', 'e', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'H', 'a', 'm', 'b', 'u', 'r', 'g', 'u', 'e', 'r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'B', 'a', 'u', 'r', 'u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'B', 'u', 'r', 'g', 'u', 'e', 'r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'S', 'a', 'l', 'a', 'd', 'a', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'E', 'g', 'g', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'B', 'a', 'c', 'o', 'n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'E', 'g', 'g', ' ', 'B', 'a', 'c', 'o', 'n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'C', 'a', 'l', 'a', 'b', 'r', 'e', 's', 'a', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'P', 'i', 'c', 'a', 'n', 'h', 'a', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
        {'X', '-', 'T', 'u', 'd', 'o', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    };

    // vetor de codigo dos produtos
    int codigo[11] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    // vetor de preços
    float preco[11] = {7.50, 8.10, 9.50, 10.50, 11.20, 12.15, 13.30, 14.30, 13.10, 13.50, 14.50};

    cout << "*******************************************\n";
    cout << "*              CARDÁPIO                   *\n";
    cout << "*******************************************\n\n";

    for (int i = 0; i < 11; i++)
    {
        cout << "Codigo: " << codigo[i] << "\t | " << produto[i] << "\t | R$:" << preco[i] << "\n";
    }

    cout << endl << endl;
}

void ListarPedidos(Pedido pedido[], int contador)
{
    system("cls");
    cout << "*******************************************\n";
    cout << "*            LISTA PEDIDOS                *\n";
    cout << "*******************************************\n\n";

    // verificando o vetor de pedidos se está vazio
    if (contador == 0)
    {
        cout << "Lista de pedidos vazia!\n\n";
    }

    for (int i = 0; i < contador; i++)
    {
        cout << "-------------------------\n";
        cout << "Codigo do Pedido: " << pedido[i].codPedido << "\n\n";
        for (int z = 0; z < MAXTAM; z++)
        {
            // para não mostrar lixo caso o vetor nao esteja completo e bugar o programa
            if (pedido[i].produtos[z].codProduto >= 100 && pedido[i].produtos[z].codProduto <= 110)
            {
                cout << "Codigo do Produto: " << pedido[i].produtos[z].codProduto << "\n";
                cout << "Nome do Produto: " << pedido[i].produtos[z].nome << "\n";
                cout << "Preço: R$" << pedido[i].produtos[z].preco << "\n\n";
            }
        }
        cout << "Distancia: " << pedido[i].distancia << "Km" << "\n";
        cout << "Valor do pedido: R$" << pedido[i].valor_pedido << "\n";
        cout << "-------------------------\n";
    }
    system("pause");
    system("cls");
}

void ConsultaPedido(Pedido pedido[], int contador)
{
    int cod, pos;

    cout << "*******************************************\n";
    cout << "*            CONSULTA PEDIDO              *\n";
    cout << "*******************************************\n\n";

    if (contador == 0)
    {
        cout << "Ainda não tem pedidos para consulta!\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "Informe o codigo do pedido: ";
    cin >> cod;

    // pesquisa o pedido e retorna a posicão que ele foi encontrado
    pos = PesquisaPedido(pedido, cod, contador);

    if (pos == -1)
    {
        cout << "\nPedido não encontrado!\n\n";
    }
    else
    {
        cout << "\n-------------------------\n";
        cout << "Codigo do Pedido: " << pedido[pos].codPedido << "\n\n";
        for (int z = 0; z < MAXTAM; z++)
        {
            // para não mostrar lixo caso o vetor nao esteja completo e bugar o programa
            if (pedido[pos].produtos[z].codProduto >= 100 && pedido[pos].produtos[z].codProduto <= 110)
            {
                cout << "Codigo do Produto: " << pedido[pos].produtos[z].codProduto << "\n";
                cout << "Nome do Produto: " << pedido[pos].produtos[z].nome << "\n";
                cout << "Preço: R$" << pedido[pos].produtos[z].preco << "\n\n";
            }
        }
        cout << "Distancia: " << pedido[pos].distancia << "Km" << "\n";
        cout << "Valor do pedido: R$" << pedido[pos].valor_pedido << "\n";
        cout << "-------------------------\n\n";
    }
    system("pause");
    system("cls");
}

int PesquisaPedido(Pedido pedido[], int cod, int contador)
{
    for (int x = 0; x < contador; x++)
    {
        if (pedido[x].codPedido == cod)
        {
            return x;
        }
    }
    return -1;
}

void ListaEntrega(TPilha *mochila, Pedido pedido[], int contador)
{
    Pedido pedido_temp;

    TPilha_Inicializa(mochila); // reinicia a mochila para sempre mater atualizada a ordem caso entre novos pedidos

    // ordena em ordem decrescente a struct de acordo com a distancia do pedido
    for (int j = 0; j < contador; j++)
    {
        for (int k = j; k < contador; k++)
        {
            if (pedido[j].distancia < pedido[k].distancia)
            {
                pedido_temp = pedido[j];
                pedido[j] = pedido[k];
                pedido[k] = pedido_temp;
            }
        }
    }

    // empilha na mochila os pedidos ordenados por distancia em ordem decrescente
    for (int y = 0; y < contador; y++)
    {
        if (TPilha_Cheia(mochila) == 1)
        {
            cout << "Mochila cheia! Não tem espaço para mais pedidos!\n\n";
        }
        else
        {
            TPilha_Empilha(mochila, pedido[y]);
        }
    }

    ImprimeEntrega(mochila);
}

void ImprimeEntrega(TPilha *mochila)
{
    system("cls");
    cout << "*******************************************\n";
    cout << "*             LISTA ENTREGA               *\n";
    cout << "*******************************************\n\n";

    // verificando se a mochila está vazia
    if (TPilha_Vazia(mochila) == 1)
    {
        cout << "Lista de entrega vazia!\n\n";
    }

    for (int i = mochila->Topo; i >= 0; i--)
    {
        cout << "-------------------------\n";
        cout << "Codigo do Pedido: " << mochila->Pilha[i].codPedido << "\n\n";
        for (int z = 0; z < MAXTAM; z++)
        {
            // para não mostrar lixo caso o vetor nao esteja completo e bugar o programa
            if (mochila->Pilha[i].produtos[z].codProduto >= 100 && mochila->Pilha[i].produtos[z].codProduto <= 110)
            {
                cout << "Codigo do Produto: " << mochila->Pilha[i].produtos[z].codProduto << "\n";
                cout << "Nome do Produto: " << mochila->Pilha[i].produtos[z].nome << "\n";
                cout << "Preço: R$" << mochila->Pilha[i].produtos[z].preco << "\n\n";
            }
        }
        cout << "Distancia: " << mochila->Pilha[i].distancia << "Km" << "\n";
        cout << "Valor do pedido: R$" << mochila->Pilha[i].valor_pedido << "\n";
        cout << "-------------------------\n";
    }
    system("pause");
    system("cls");
}

void LancarEntrega(TPilha *mochila, Pedido pedido[], int contador, int *pont)
{
    system("cls");
    cout << "*******************************************\n";
    cout << "*            ENTREGA DE PEDIDO            *\n";
    cout << "*******************************************\n\n";

    if (TPilha_Vazia(mochila) == 1)
    {
        cout << "Ainda não tem pedidos para serem entregues!\n\n";
    }
    else
    {
        TPilha_Desempilha(mochila, &pedido[contador]);

        cout << "Pedido de codigo: " << pedido[contador].codPedido << " foi entregue!\n\n";

        (*pont)--; // decrementa o valor do ponteiro mudando também o valor do contador
    }

    system("pause");
    system("cls");
}