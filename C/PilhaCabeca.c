#include <stdio.h>
#include <stdlib.h>

// criar estrutura de celula
typedef struct Celula {
    int conteudo;
    struct Celula* seg;
} Celula;

typedef struct Pilha {
    Celula* pInicio;
    Celula* pFinal;
} Pilha;

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
//**********************************************************
Pilha* criarPilha (int tamanhoLista) {
    Pilha* pPilha = (Pilha*)malloc(sizeof(Pilha));
    pPilha->pInicio = criarListaEncadeada(tamanhoLista);
    pPilha->pFinal = pPilha->pInicio;
    for (Celula* p = pPilha->pInicio; p != NULL; p = p->seg) {
        // printf("endereco %p\n", p);
        pPilha->pFinal = p;
    }
    return pPilha;

}

void imprimirConteudoPilha (Pilha* pPilha) {
    imprimirConteudoLista(pPilha->pInicio);
}

void imprimirEnderecosPilha (Pilha* pPilha) {
    imprimirEnderecosLista(pPilha->pInicio, 1);
}

// p é pPilha->pInicio
void deletarFimPilha (Pilha* pPilha, Celula* p) {
    if (pPilha->pInicio == pPilha->pFinal) {
        free(pPilha->pInicio);
        pPilha->pInicio=NULL;
        pPilha->pFinal=NULL;
        return;
    }
    else if (p->seg == pPilha->pFinal) {
        free(p->seg);
        p->seg = NULL;
        pPilha->pFinal = p;
        return;
    }
    else {
        return deletarFimPilha(pPilha, p->seg);
    }
}

Pilha* insertFimPilha (Pilha* pPilha) {
    Celula* p = malloc(sizeof(Celula));
    p->conteudo = rand()%10;
    p->seg = NULL;
    (pPilha->pFinal)->seg = p; 
    pPilha->pFinal = p;
}

int main() {
    printf("Criacao de Pilha composta por lista encadeada com 7 celulas: \n");
    Pilha* pPilha = criarPilha(7);
    printf("Endereco do inicio da Pilha: %p\n", pPilha->pInicio);
    printf("Endereco do fim da Pilha: %p\n", pPilha->pFinal);

    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoPilha(pPilha);
    printf("\n");
    imprimirEnderecosPilha(pPilha);
    printf("\n");

    printf("Deletando celula no fim da Pilha: \n");
    deletarFimPilha(pPilha, pPilha->pInicio);
    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoPilha(pPilha);
    printf("\n");
    imprimirEnderecosPilha(pPilha);
    printf("\n");

    printf("Inserindo celula no fim da Pilha: \n");
    insertFimPilha(pPilha);
    printf("Conteudos da lista encadeada que faz parte da Pilha: \n");
    imprimirConteudoPilha(pPilha);
    printf("\n");
    imprimirEnderecosPilha(pPilha);
    printf("\n");

}