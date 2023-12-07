#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// nenhuma função de árvore precisa usar ponteiro de ponteiro
// usar a searchminimum dentro da função.
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node, Node* root) {
    // caso em que a árvore está vazia
    if (root == NULL) {
        return node;
    }
    if (node->value > root->value) {
        // aqui eu já considero a possibilidade de não ter filho a direita
        if (root->right == NULL) {
            root->right = node;
        }
        else {insertNode(node, root->right);}
    }
    else {
        // aqui eu já considero a possibilidade de não ter filho a direita
        if (root->left == NULL) {
            root->left = node;
        }
        else {insertNode(node, root->left);}
    }
    return root;
}

Node* search(int valueToFind, Node* root) {
    if (root==NULL || valueToFind == root->value) {
        return root;
    } 
    else if (valueToFind > root->value){
        search(valueToFind, root->right);
    }
    else {search(valueToFind, root->left);}
}

Node* searchMininum(Node* p) {
    if (p->left == NULL) {
        return p;
    }
    else {searchMininum(p->left);}
}



Node* deleteRoot(Node* root) {
   Node* p;
   Node* q;
   // também pega a situação em que só há um nódulo
   if (root->right == NULL) {
    q = root->left;
   }
   else if (root->left == NULL) {
    q = root->right;
   }
   else {
    q = root->right;
    p = root;
    while (q->left != NULL) {
        p = q;
        q = q->left;
    }
    if (p!=root) {
        p->left = q->right;
        q->right = root->right;
    }
    q->left = root->left;
   }
   free (root);
   return q;
        
}



void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->value);
        printTree(root->right);
    }
}




int main() {

    Node* root = NULL;
         
    int elements[] = {8, 4, 5, 10, 2, 9, 3, 11, 1, 16};
    int size = sizeof(elements) / sizeof(elements[0]);
    
    for (int i = 0; i < size; i++) {
            Node* newNode = createNode(elements[i]);
            root = insertNode(newNode, root);
    }

    printTree(root);
    printf("\n");

    Node* new_root = deleteRoot(root);
    printTree(new_root);



}