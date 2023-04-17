#include<stdio.h>
#include<stdlib.h>

/* Diâmetro de uma árvore binária 

- O diâmetro de uma árvore binária é o comprimento do caminho mais longo entre quaisquer dois nós 
em uma árvore. Este caminho pode ou não passar pela raiz.
- O comprimento de um caminho entre dois nós é representado pelo número de arestas entre eles.

Restrições:
 O número de nós na árvore está no intervalo [1, 104
].
 -100 <= Node.val <= 100


*/

// Definindo a estrutura de um nó da árvore binária
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

// Função para criar um novo nó da árvore
Node* createNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para calcular a altura de uma subárvore
int height(Node* TreeNode) {
    if (TreeNode == NULL)
        return 0;
    else {
        int leftHeight = height(TreeNode->left);
        int rightHeight = height(TreeNode->right);
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// Função para calcular o diâmetro de uma árvore binária
int diameterOfBinaryTree( struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else {
        // Calculando a altura das subárvores esquerda e direita
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Calculando o diâmetro do nó atual
        int currentDiameter = leftHeight + rightHeight + 1;

        // Calculando o diâmetro das subárvores esquerda e direita recursivamente
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        // Retornando o maior diâmetro encontrado
        if (currentDiameter > leftDiameter && currentDiameter > rightDiameter)
            return currentDiameter;
        else if (leftDiameter > rightDiameter)
            return leftDiameter;
        else
            return rightDiameter;
    }
}

// Função principal para testar o algoritmo
int main() {
    // Criando uma árvore binária
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculando o diâmetro da árvore
    int treeDiameter = diameterOfBinaryTree(root);

    // Imprimindo o resultado
    printf("O comprimento do diametro da arvore: %d\n", treeDiameter);
    return 0;
}