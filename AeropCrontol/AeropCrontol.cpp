// AeropCrontol.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
/*Escreva um programa que simule o controle de uma pista de
descolagem num aeroporto.Neste programa, o utilizador deve ser
capaz de realizar as seguintes tarefas :
    1 - Listar o n�mero de avi�es aguardando na fila de descolagem;
    2 - Autorizar a descolagem do primeiro avi�o da fila;
    3 - Adicionar um avi�o � fila de espera;
    4 - Listar todos os avi�es na fila de espera;
    5 - Listar as caracter�sticas do primeiro avi�o da fila.
Nota: Considere que os avi�es possuem um nome e um n�mero
inteiro como identificador.Adicione outras caracter�sticas conforme achar necess�rio.*/

#include <iostream>
#include <Windows.h>
#include <queue>
#include <string>

using namespace std;

struct Aviao {
    string nome;
    int id;
};


void listarNumero(queue<Aviao>& fila);
void autorizarDescolagem(queue<Aviao>& fila);
void adicionarAviao(queue<Aviao>& fila);
void listarAviao(queue<Aviao> fila);
void listarPrimeiro(queue<Aviao>& fila);

int main() {
    queue<Aviao> descolar;
    int op;

    do {
        cout << "\nControle de Pista de Descolagem\n";
        cout << "1 - Listar o n�mero de avi�es para descolar\n";
        cout << "2 - Autorizar descolagem do primeiro avi�o\n";
        cout << "3 - Adicionar avi�o � fila de espera\n";
        cout << "4 - Listar todos os avi�es em fila de espera\n";
        cout << "5 - Listar as caracter�sticas do primeiro avi�o da fila\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma op��o: ";
        cin >> op;

        switch (op) {
        case 1:
            listarNumero(descolar);
            break;
        case 2:
            autorizarDescolagem(descolar);
            break;
        case 3:
            adicionarAviao(descolar);
            break;
        case 4:
            listarAviao(descolar);
            break;
        case 5:
            listarPrimeiro(descolar);
            break;
        case 0:
            cout << "Sair\n";
            break;
        default:
            cout << "Op��o inv�lida. Tente novamente.\n";
        }
    } while (op != 0);

    return 0;
}


void listarNumero(queue<Aviao>& fila) {
    cout << "N�mero de avi�es na fila para descolar: " << fila.size() << "\n";
}

void autorizarDescolagem(queue<Aviao>& fila) {
    if (!fila.empty()) {
        Aviao primeiro = fila.front();
        cout << "Avi�o " << primeiro.nome << " (ID: " << primeiro.id << ") autorizado a descolar.\n";
        fila.pop();
    }
    else {
        cout << "N�o h� avi�es na fila de descolagem.\n";
    }
}

void adicionarAviao(queue<Aviao>& fila) {
    Aviao novo;
    cout << "Inserir nome do avi�o: ";
    cin >> novo.nome;
    cout << "Inserir identificador do avi�o: ";
    cin >> novo.id;
    fila.push(novo);
    cout << "Avi�o " << novo.nome << " (ID: " << novo.id << ") adicionado � fila de espera.\n";
}

void listarAviao(queue<Aviao> fila) {
    if (fila.empty()) {
        cout << "N�o h� avi�es em fila de espera.\n";
    }
    else {
        cout << "Avi�es em fila de espera:\n";
        while (!fila.empty()) {
            Aviao aviao = fila.front();
            cout << "- " << aviao.nome << " (ID: " << aviao.id << ")\n";
            fila.pop();
        }
    }
}

void listarPrimeiro(queue<Aviao>& fila) {
    if (!fila.empty()) {
        Aviao primeiro = fila.front();
        cout << "Primeiro avi�o:\n";
        cout << "Nome: " << primeiro.nome << "\n";
        cout << "ID: " << primeiro.id << "\n";
    }
    else {
        cout << "N�o h� avi�es para descolar.\n";
    }
}

