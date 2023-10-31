#include <stdio.h>
#include <stdlib.h>

// criar estrutura de pila
typedef struct Pilha {
    struct Celula* topo;
} Pilha;

// criar estrutura de celula
typedef struct Celula {
    int conteudo;
    struct Celula* seg;
} Celula;

Celula* criarPilhaSemCabeca (int numCel, int count){
    Celula* newSeg = malloc(sizeof(Celula));
    newSeg->conteudo = rand() % 10;
    if (count == 1) {newSeg->seg = NULL;}
    if (numCel == 1) {
        return newSeg;}
    else if (numCel > 1) {
        Celula* anterior = criarPilhaSemCabeca(numCel - 1, count + 1);
        anterior->seg = newSeg;
        return anterior;
    }
}

// Celula* criarPilhaSemCabeca (int count) {
//     Celula* newSeg = malloc(sizeof(Celula));
//     newSeg->conteudo = rand() % 10;
//     newSeg->seg = NULL;
//     while (count > 1){
//         Celula* newSeg_anterior = malloc(sizeof(Celula));
//         newSeg_anterior->conteudo = rand() % 10;
//         newSeg_anterior->seg = NULL;
//     }
// }

Pilha* criarPilhaComCabeca () {
    Pilha* pPilha = (Pilha*)malloc(sizeof(Pilha));
    pPilha->topo = NULL;
    return pPilha;
}

void inserirCelulaPilha (Pilha* pPilha) {
    Celula* newSeg = malloc(sizeof(Celula));
    newSeg->conteudo = rand() % 10;
    newSeg->seg = pPilha-> topo;
    pPilha->topo = newSeg;
}


//***Funções para criação e impressão da lista encadeada***

// Celula* criarListaEncadeada (int count) {
//     if(count == 0) {return NULL;}
//     Celula* newSeg = malloc(sizeof(Celula));
//     newSeg->conteudo = rand() % 10;
//     if (count == 1) {newSeg->seg = NULL;}
//     if (count > 1) {
//         newSeg->seg = criarListaEncadeada(count - 1);}
//     return newSeg;
// }

void imprimirConteudoLista (Celula* lst) {
    if(lst->seg != NULL) {
        printf("teste");
        printf("%d, ", lst->conteudo);
        imprimirConteudoLista(lst->seg);
    } else if(lst->seg == NULL) {
        printf("%d", lst->conteudo);
    }
}

void imprimirEnderecosLista (Celula* lst, int count) {
    printf("endereco da %d celula: %p\n", count, lst);
    if(lst->seg != NULL) {
        imprimirEnderecosLista(lst->seg, count+1);
    }
}
//**********************************************************

void deletarInicioPilhaSemCabeca (Celula** pP) {
    Celula* pReserva = *pP;
    *pP=(pReserva->seg);
    free(pReserva);
}

void insertInicioPilhaSemCabeca (Celula** pP) {
    Celula* p = malloc(sizeof(Celula));
    p->conteudo = rand()%10;
    p->seg = NULL;
    p->seg=*pP;
    *pP = p;
}

int main() {
    printf("Criacao de Pilha composta por lista encadeada com 7 celulas: \n");
    Celula* p = criarPilhaSemCabeca(9, 1);
    printf("Endereco do inicio da Pilha: %p\n", p);

    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoLista(p);
    printf("\n");
    imprimirEnderecosLista(p, 1);
    printf("\n");

    printf("Deletando celula no inicio da Pilha: \n");
    deletarInicioPilhaSemCabeca(&p);
    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoLista(p);
    printf("\n");
    imprimirEnderecosLista(p, 1);
    printf("\n");

    printf("Inserindo celula no inicio da Pilha: \n");
    insertInicioPilhaSemCabeca(&p);
    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoLista(p);
    printf("\n");
    imprimirEnderecosLista(p, 1);
    printf("\n");

}
