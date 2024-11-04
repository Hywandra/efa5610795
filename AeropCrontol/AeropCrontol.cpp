// AeropCrontol.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
/*Escreva um programa que simule o controle de uma pista de
descolagem num aeroporto.Neste programa, o utilizador deve ser
capaz de realizar as seguintes tarefas :
    1 - Listar o número de aviões aguardando na fila de descolagem;
    2 - Autorizar a descolagem do primeiro avião da fila;
    3 - Adicionar um avião à fila de espera;
    4 - Listar todos os aviões na fila de espera;
    5 - Listar as características do primeiro avião da fila.
Nota: Considere que os aviões possuem um nome e um número
inteiro como identificador.Adicione outras características conforme achar necessário.*/

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
        cout << "1 - Listar o número de aviões para descolar\n";
        cout << "2 - Autorizar descolagem do primeiro avião\n";
        cout << "3 - Adicionar avião à fila de espera\n";
        cout << "4 - Listar todos os aviões em fila de espera\n";
        cout << "5 - Listar as características do primeiro avião da fila\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
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
            cout << "Opção inválida. Tente novamente.\n";
        }
    } while (op != 0);

    return 0;
}


void listarNumero(queue<Aviao>& fila) {
    cout << "Número de aviões na fila para descolar: " << fila.size() << "\n";
}

void autorizarDescolagem(queue<Aviao>& fila) {
    if (!fila.empty()) {
        Aviao primeiro = fila.front();
        cout << "Avião " << primeiro.nome << " (ID: " << primeiro.id << ") autorizado a descolar.\n";
        fila.pop();
    }
    else {
        cout << "Não há aviões na fila de descolagem.\n";
    }
}

void adicionarAviao(queue<Aviao>& fila) {
    Aviao novo;
    cout << "Inserir nome do avião: ";
    cin >> novo.nome;
    cout << "Inserir identificador do avião: ";
    cin >> novo.id;
    fila.push(novo);
    cout << "Avião " << novo.nome << " (ID: " << novo.id << ") adicionado à fila de espera.\n";
}

void listarAviao(queue<Aviao> fila) {
    if (fila.empty()) {
        cout << "Não há aviões em fila de espera.\n";
    }
    else {
        cout << "Aviões em fila de espera:\n";
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
        cout << "Primeiro avião:\n";
        cout << "Nome: " << primeiro.nome << "\n";
        cout << "ID: " << primeiro.id << "\n";
    }
    else {
        cout << "Não há aviões para descolar.\n";
    }
}

