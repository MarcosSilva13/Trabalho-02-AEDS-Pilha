#include <iostream>
#include <windows.h>
#include "Pilha.cpp"
#include <iomanip>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TPilha mochila;
    Pedido pedido[MAX_ENTREGA];

    TPilha_Inicializa(&mochila);

    int op, contador = 0;
    int *pont; // ponteiro para alterar o valor do contador nas funções
    pont = &contador;

    do
    {
        menu();
        cout << "Escolha uma opcão: ";
        cin >> op;

        system("cls");

        switch (op)
        {
        case 1:
            IncluirPedido(pedido, contador, pont);
            break;
        case 2:
            ListarPedidos(pedido, contador);
            break;
        case 3:
            Cardapio();
            system("pause");
            system("cls");
            break;
        case 4:
            ConsultaPedido(pedido, contador);
            break;
        case 5:
            ListaEntrega(&mochila, pedido, contador);
            break;
        case 6:
            LancarEntrega(&mochila, pedido, contador, pont);
            break;
        }   

    } while (op != 7);

    return 0;
}