// FilaNumInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
/*Defina uma fila de número inteiros.
    1 - Preencha fila com 5 número inteiros.
    2 - Escreva um método para inverter a ordem
    dos elementos dessa fila, usando uma pilha como estrutura auxiliar.
    3 - Mostre os elementos da fila inicial.
    4 - Mostre os mesmos elementos por ordem inversa.
*/

#include <iostream>
#include <queue>
#include <Windows.h>
#include <stack>

using namespace std;

void mostrar(queue<int> fila);
void filaInversa(queue<int> fila);

int main()
{
    SetConsoleOutputCP(1252);

    queue<int>fila;

    for (int i = 1; i < 6; i++)
    {
        fila.push(i);
    }
  
    mostrar(fila);

    filaInversa(fila);
}

void mostrar(queue<int> fila)
{
    while (!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }
}

void filaInversa(queue<int> fila)
{
    stack<int> pilha;
    cout << endl;
    for (int i = 5; i > 0; i--) {
        pilha.push(i);
        cout << pilha.top() << " ";
        pilha.pop();
    }
}