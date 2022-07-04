#include <iostream>
#include <stdlib.h>
#include<locale.h>
using namespace std;

struct NO { 

    int item;
    NO *esq;
    NO *dir;
};

class Tree { // Inicio da árvore
  private: NO *root; 
  public: Tree() { root = NULL; } 

  public: void inserir(int num) {
    NO *novo = new NO(); // cria um novo Nó
    novo->item = num; // atribui o valor recebido ao item de dados do Nó
    novo->dir = NULL;
    novo->esq = NULL;
    if (root == NULL) root = novo;
    else  { // se não for a raiz
      NO *atual = root;
      NO *anterior;
      while(true) {
        anterior = atual;
        if (num <= atual->item) { // Condição  ir para esquerda ou direita
          atual = atual->esq;
          if (atual == NULL) {
            anterior->esq = novo;
            return;
          } 
        }  
        else {
           atual = atual->dir;
           if (atual == NULL) {
             anterior->dir = novo;
             return;
           }
        } 
      } 
    }

  }

  
  public: void mostrar() {
  
    cout << "\n Exibindo em pré-ordem: ";
    preOrder(root);}

  

  
  private: void preOrder(NO *atual) {
    if (atual != NULL) {
      cout << atual->item << " ";
      preOrder(atual->esq);
      preOrder(atual->dir);
    }
  }


};

main() { 
setlocale(LC_ALL,"Portuguese");
    Tree arv;
    int opcao, x,i;
    cout << ("\n Programa Árvore binária");
    do {
        cout << "\n________________________________________";
        cout << "\nEscolha uma opção:";
		cout << "\n ----1: Inserir número";
		cout << "\n ----2: Exibir";
		cout << "\n ----3: Sair do programa";
		cout << "\n________________________________________";
		cout << "\n :) R: ";
		cin >> opcao;
		switch(opcao) {
	 		case 1: {
	 			 cout << "\n Informe o seu R.A: ";
				  	for(i = 0; i< 9; i++){  // Atribuir os 9 digitos 
					       cin >> x;
		       arv.inserir(x);
			}
		      
		       break;
			}

			case 2: {
		      arv.mostrar();
		      break; 
			}
        } 
    } while(opcao != 3);
}
