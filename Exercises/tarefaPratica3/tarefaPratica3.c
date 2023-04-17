#include <stdio.h>
#include <stdlib.h>

//Root Input: {1,2,3,4,5}
//Root output: 3

/* Restrições:
 O número de nós na árvore está no intervalo [1, 104
].
 -100 <= Node.val <= 100 */

 
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
};

int diameterOfBinaryTree(struct TreeNode* root){
    if (root == NULL) return 0;
    int leftHeight = diameterOfBinaryTree(root->left);
    int rightHeight = diameterOfBinaryTree(root->right);
    
     int maxHeight;
    if (leftHeight > rightHeight) {
        maxHeight = leftHeight;
    } else {
        maxHeight = rightHeight;
    }
    
    return 1 + maxHeight;
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    return 0;
}