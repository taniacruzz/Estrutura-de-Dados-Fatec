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

//**********************************************************
void imprimirConteudoLista (Celula* lst) {
    if(lst->seg != NULL) {
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
//*****************Pilha com Cabeca*****************
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

//*****************Pilha sem Cabeca*****************
Celula* criarPilhaSemCabeca(Celula** pTopo, int numCelulas, int cont) {
    Celula* newSeg = malloc(sizeof(Celula));
    newSeg->conteudo = rand() % 10;
    *pTopo = newSeg;
    if (cont == 1){ 
        newSeg->seg = NULL;
    }
    if (numCelulas == 1) {
        return *pTopo;
    };
    
    if (numCelulas > 1) {
        criarPilhaSemCabeca(pTopo, numCelulas - 1, cont + 1)->seg = newSeg;
    }
    if (cont == 1) {return *pTopo;}
    return newSeg;
}

void insertInicioPilhaSemCabeca (Celula** pP) {
    Celula* p = malloc(sizeof(Celula));
    p->conteudo = rand()%10;
    p->seg=*pP;
    *pP = p;
}
void deletarInicioPilhaSemCabeca (Celula** pP) {
    Celula* pReserva = *pP;
    *pP=(pReserva->seg);
    free(pReserva);
}



int main() {
    Celula* topo = malloc(sizeof(Celula));
    printf("Criacao de Pilha, sem cabeca, composta por lista encadeada com 7 celulas: \n");
    Celula* p = criarPilhaSemCabeca(&topo, 7, 1);
    printf("Endereco do inicio da Pilha: %p\n", p);

    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoLista(p);
    printf("\n");
    printf("Enderecos das células da lista encadeada que faz parte da Pilha: \n");
    imprimirEnderecosLista(p, 1);
    printf("\n");

    printf("Deletando celula no inicio da Pilha: \n");
    deletarInicioPilhaSemCabeca(&p);
    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoLista(p);
    printf("\n");
    printf("Enderecos das células da lista encadeada que faz parte da Pilha: \n");
    imprimirEnderecosLista(p, 1);
    printf("\n");

    printf("Inserindo celula no inicio da Pilha: \n");
    insertInicioPilhaSemCabeca(&p);
    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoLista(p);
    printf("\n");
    printf("Enderecos das células da lista encadeada que faz parte da Pilha: \n");
    imprimirEnderecosLista(p, 1);
    printf("\n");

}
