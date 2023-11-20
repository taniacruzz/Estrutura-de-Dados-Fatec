#include <stdio.h>
#include <stdlib.h>

typedef struct Doc {
    int content;
    struct Doc* nextDoc;
} Doc;

Doc* createSequenceToPrint (int count) {
    if(count == 0) {return NULL;}
    Doc* pDoc = malloc(sizeof(Doc));
    pDoc->content = rand() % 10;
    if (count == 1) {pDoc->nextDoc = NULL;}
    if (count > 1) {
        pDoc->nextDoc = createSequenceToPrint(count - 1);}
    return pDoc;
}

void checkSequence (Doc* pDoc) {
    if(pDoc->nextDoc != NULL) {
        printf("%d\n", pDoc->content);
        checkSequence(pDoc->nextDoc);
    } else if(pDoc->nextDoc == NULL) {
        printf("%d\n--------------\n", pDoc->content);
    }
}

void toPrint (Doc** p_pFirstDoc) {
    Doc* pReserva = *p_pFirstDoc;
    *p_pFirstDoc=(pReserva->nextDoc);
    free(pReserva);
}

void addDocToPrint (Doc* pFirstDoc) {
    if ((pFirstDoc->nextDoc)==NULL){
        Doc* p = malloc(sizeof(Doc));
        p->content = rand()%10;
        p->nextDoc = NULL;
        pFirstDoc->nextDoc=p;
    }
    else(addDocToPrint(pFirstDoc->nextDoc));
}

int main() {
    printf("Criacao de sequencia para imprimir composta por 7 documentos: \n");
    Doc* pFirstDoc = createSequenceToPrint(7);
    
    printf("Sequencia para impressao: \n");
    checkSequence(pFirstDoc);
    printf("\n");
   
    printf("Imprimindo primeiro documento da sequencia: \n");
    toPrint(&pFirstDoc);
    printf("Sequencia para impressao: \n");
    checkSequence(pFirstDoc);
    printf("\n");
   
    printf("Adicionando documento para impressão: \n");
    addDocToPrint(pFirstDoc);
    printf("Sequencia para impressao: \n");
    checkSequence(pFirstDoc);
    printf("\n");
    
}

