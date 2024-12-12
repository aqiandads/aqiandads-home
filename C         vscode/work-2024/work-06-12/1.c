#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的结点数据类型
typedef struct BTNode {
    char data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

// 定义栈元素的数据类型
typedef struct StackElement {
    BTNode *node;
    int isLeftChild; // 0表示右孩子，1表示左孩子
} StackElement;

// 定义栈的数据类型
typedef struct Stack {
    StackElement *elements;
    int top;
    int maxSize;
} Stack;

// 初始化栈
void initStack(Stack *s, int size) {
    s->elements = (StackElement *)malloc(size * sizeof(StackElement));
    s->top = -1;
    s->maxSize = size;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack *s) {
    return s->top == s->maxSize - 1;
}

// 入栈操作
void push(Stack *s, BTNode *node, int isLeftChild) {
    if (!isFull(s)) {
        s->elements[++s->top].node = node;
        s->elements[s->top].isLeftChild = isLeftChild;
    }
}

// 出栈操作
StackElement pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->elements[s->top--];
    }
    StackElement empty = {NULL, 0};
    return empty;
}

// 创建二叉树
void makeTree(BTNode **root) {
    *root = (BTNode *)malloc(sizeof(BTNode));
    (*root)->data = 'A';
    (*root)->left = (BTNode *)malloc(sizeof(BTNode));
    (*root)->left->data = 'B';
    (*root)->left->left = (BTNode *)malloc(sizeof(BTNode));
    (*root)->left->left->data = 'E';
    (*root)->left->left->left = NULL;
    (*root)->left->left->right = NULL;
    (*root)->left->right = (BTNode *)malloc(sizeof(BTNode));
    (*root)->left->right->data = 'F';
    (*root)->left->right->left = NULL;
    (*root)->left->right->right = NULL;
    (*root)->right = (BTNode *)malloc(sizeof(BTNode));
    (*root)->right->data = 'C';
    (*root)->right->left = (BTNode *)malloc(sizeof(BTNode));
    (*root)->right->left->data = 'H';
    (*root)->right->left->left = NULL;
    (*root)->right->left->right = NULL;
    (*root)->right->right = (BTNode *)malloc(sizeof(BTNode));
    (*root)->right->right->data = 'D';
    (*root)->right->right->left = (BTNode *)malloc(sizeof(BTNode));
    (*root)->right->right->left->data = 'I';
    (*root)->right->right->left->left = NULL;
    (*root)->right->right->left->right = NULL;
    (*root)->right->right->right = (BTNode *)malloc(sizeof(BTNode));
    (*root)->right->right->right->data = 'J';
    (*root)->right->right->right->left = NULL;
    (*root)->right->right->right->right = NULL;
}

// 释放二叉树
void freeTree(BTNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// H遍历
void HTraverse(BTNode *root) {
    Stack s;
    initStack(&s, 100);
    BTNode *current = root;
    BTNode *pre = NULL; // 记录前一个访问的节点

    while (current != NULL || !isEmpty(&s)) {
        // 下降到最左边的节点
        while (current != NULL) {
            push(&s, current, 1); // 标记为左孩子
            current = current->left;
        }

        // 当前节点为空，回溯
        if (!isEmpty(&s)) {
            StackElement se = pop(&s);
            current = se.node;
            // 如果当前节点是左孩子，且没有右孩子，或者右孩子已经访问过，则输出当前节点
            if (se.isLeftChild && (current->right == NULL || pre == current->right)) {
                printf("%c", current->data);
                pre = current;
                current = NULL; // 标记为已访问
            } else {
                // 如果当前节点是右孩子，或者左孩子有右孩子，则输出父节点
                if (se.isLeftChild && current->right != NULL) {
                    printf("%c", current->data);
                }
                // 如果当前节点是左孩子，且右孩子为空，则输出当前节点
                if (se.isLeftChild && current->right == NULL) {
                    printf("%c", current->data);
                }
                current = current->right;
                push(&s, current, 0); // 标记为右孩子
            }
        }
    }
}

int main() {
    BTNode *root;
    makeTree(&root);
    HTraverse(root);
    freeTree(root);
    return 0;
}