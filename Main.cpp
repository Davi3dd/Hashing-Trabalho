#include <iostream>
#include <cstdlib>
#include <cstring>
#define TABLESPACE 2000
using namespace std;

struct agenda {
    bool livre;
    char nome[50];
    char endereco[50];
    char tel[15];
};

void iniciaAgenda(agenda a[]) {
    for (int i = 0; i < TABLESPACE; i++) {
        a[i].livre = true;
    }
}

int minhaHash(char *chave) {
    int hash = 0;
    while (*chave) {
        hash = (hash * 31 + *chave) % TABLESPACE;
        chave++;
    }
    return hash;
}

int main() {
    agenda a[TABLESPACE];
    char nome[50];
    iniciaAgenda(a);
    int op = 1, pos;
    while (op != 0) {
        cout << "Digite um nome: ";
        cin >> nome;
        pos = minhaHash(nome);
        if (pos >= TABLESPACE) pos = pos % TABLESPACE;
        if (a[pos].livre) {
            cout << "Esse nome foi armazenado na posicao " << pos << ".\n";
            strcpy(a[pos].nome, nome);
            a[pos].livre = false;
            cout << "Continuar? [0 - Nao / 1 - Sim] ";
            cin >> op;
        } else {
            cout << "Houve colisao na posicao " << pos << ".\n";
            cout << "Nome alocado: " << a[pos].nome << endl;
            op = 0;
        }
    }
    return 0;
}
