#include <stdio.h>
#include <stdlib.h>

// criar estrutura de celula
typedef struct Celula {
    int conteudo;
    struct Celula* seg;
} Celula;

typedef struct Fila {
    Celula* pInicio;
    Celula* pFinal;
} Fila;

//***Funções para criação e impressão da lista encadeada***

Celula* criarListaEncadeada (int count) {
    if(count == 0) {return NULL;}
    Celula* newSeg = malloc(sizeof(Celula));
    newSeg->conteudo = rand() % 10;
    if (count == 1) {newSeg->seg = NULL;}
    if (count > 1) {
        newSeg->seg = criarListaEncadeada(count - 1);}
    return newSeg;
}

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
//**************Fila Com Cabeça**************
Fila* criarFilaCcabeca (int tamanhoLista) {
    Fila* pFila = (Fila*)malloc(sizeof(Fila));
    pFila->pInicio = criarListaEncadeada(tamanhoLista);
    pFila->pFinal = pFila->pInicio;
    for (Celula* p = pFila->pInicio; p != NULL; p = p->seg) {
        // printf("endereco %p\n", p);
        pFila->pFinal = p;
    }
    return pFila;
}

void imprimirConteudoFila (Fila* pFila) {
    imprimirConteudoLista(pFila->pInicio);
}

void imprimirEnderecosFila (Fila* pFila) {
    imprimirEnderecosLista(pFila->pInicio, 1);
}

Fila* deletarInicioFilaCabeca (Fila* pFila) {
    Celula* pReserva;
    pReserva = pFila->pInicio;
    pFila->pInicio = (pFila->pInicio)->seg;
    free(pReserva);
}

Fila* insertFimFilaCabeca (Fila* pFila) {
    Celula* p = malloc(sizeof(Celula));
    p->conteudo = rand()%10;
    p->seg = NULL;
    (pFila->pFinal)->seg = p; 
    pFila->pFinal = p;
}

//**************Fila Sem Cabeça**************

void deletarInicioFilaSemCabeca (Celula** p_pInicio) {
    Celula* pReserva = *p_pInicio;
    *p_pInicio=(pReserva->seg);
    free(pReserva);
}


void insertFimFilaSemCabeca (Celula* pInicio) {
    if ((pInicio->seg)==NULL){
        Celula* p = malloc(sizeof(Celula));
        p->conteudo = rand()%10;
        p->seg = NULL;
        pInicio->seg=p;
    }
    else(insertFimFilaSemCabeca(pInicio->seg));
}


int main() {
    // Celula* pInicio;
    // Celula* pFim;
    // printf("Criacao de fila composta por lista encadeada com 7 celulas: \n");
    // Fila* pFila = criarFilaCcabeca(7);
    // printf("Endereco do inicio da fila: %p\n", pFila->pInicio);
    // printf("Endereco do fim da fila: %p\n", pFila->pFinal);

    // printf("Conteudos da lista encadeada que faz parte da fila: \n");
    // imprimirConteudoFila(pFila);
    // printf("\n");
    // imprimirEnderecosFila(pFila);
    // printf("\n");

    // printf("Deletando celula no inicio da fila com cabeca: \n");
    // deletarInicioFilaCabeca(pFila);
    // printf("Conteudos da lista encadeada que faz parte da fila: \n");
    // imprimirConteudoFila(pFila);
    // printf("\n");
    // imprimirEnderecosFila(pFila);
    // printf("\n");

    // printf("Inserindo celula no fim da fila: \n");
    // insertFimFilaCabeca(pFila);
    // printf("Conteudos da lista encadeada que faz parte da fila: \n");
    // imprimirConteudoFila(pFila);
    // printf("\n");
    // imprimirEnderecosFila(pFila);
    // printf("\n");

//***********************************************************************
    printf("Criacao de fila SEM CABECA composta por lista encadeada com 7 celulas: \n");
    Celula* pInicio = criarListaEncadeada(7);
    printf("Endereco do inicio da fila: %p\n", pInicio);

    printf("Conteudos da lista encadeada que faz parte da fila: \n");
    imprimirConteudoLista(pInicio);
    printf("\n");
    imprimirEnderecosLista(pInicio, 1);
    printf("\n");

    printf("Deletando celula no inicio da fila SEM CABECA: \n");
    deletarInicioFilaSemCabeca(&pInicio);
    printf("Conteudos da lista encadeada que faz parte da fila: \n");
    imprimirConteudoLista(pInicio);
    printf("\n");
    imprimirEnderecosLista(pInicio, 1);
    printf("\n");

    printf("Inserindo celula no fim da fila SEM CABECA: \n");
    insertFimFilaSemCabeca(pInicio);
    printf("Conteudos da lista encadeada que faz parte da fila: \n");
    imprimirConteudoLista(pInicio);
    printf("\n");
    imprimirEnderecosLista(pInicio, 1);
    printf("\n");
}