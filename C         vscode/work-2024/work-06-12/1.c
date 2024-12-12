#include <stdio.h>
#include <stdlib.h>

// ����������Ľ����������
typedef struct BTNode {
    char data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

// ����ջԪ�ص���������
typedef struct StackElement {
    BTNode *node;
    int isLeftChild; // 0��ʾ�Һ��ӣ�1��ʾ����
} StackElement;

// ����ջ����������
typedef struct Stack {
    StackElement *elements;
    int top;
    int maxSize;
} Stack;

// ��ʼ��ջ
void initStack(Stack *s, int size) {
    s->elements = (StackElement *)malloc(size * sizeof(StackElement));
    s->top = -1;
    s->maxSize = size;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *s) {
    return s->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack *s) {
    return s->top == s->maxSize - 1;
}

// ��ջ����
void push(Stack *s, BTNode *node, int isLeftChild) {
    if (!isFull(s)) {
        s->elements[++s->top].node = node;
        s->elements[s->top].isLeftChild = isLeftChild;
    }
}

// ��ջ����
StackElement pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->elements[s->top--];
    }
    StackElement empty = {NULL, 0};
    return empty;
}

// ����������
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

// �ͷŶ�����
void freeTree(BTNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// H����
void HTraverse(BTNode *root) {
    Stack s;
    initStack(&s, 100);
    BTNode *current = root;
    BTNode *pre = NULL; // ��¼ǰһ�����ʵĽڵ�

    while (current != NULL || !isEmpty(&s)) {
        // �½�������ߵĽڵ�
        while (current != NULL) {
            push(&s, current, 1); // ���Ϊ����
            current = current->left;
        }

        // ��ǰ�ڵ�Ϊ�գ�����
        if (!isEmpty(&s)) {
            StackElement se = pop(&s);
            current = se.node;
            // �����ǰ�ڵ������ӣ���û���Һ��ӣ������Һ����Ѿ����ʹ����������ǰ�ڵ�
            if (se.isLeftChild && (current->right == NULL || pre == current->right)) {
                printf("%c", current->data);
                pre = current;
                current = NULL; // ���Ϊ�ѷ���
            } else {
                // �����ǰ�ڵ����Һ��ӣ������������Һ��ӣ���������ڵ�
                if (se.isLeftChild && current->right != NULL) {
                    printf("%c", current->data);
                }
                // �����ǰ�ڵ������ӣ����Һ���Ϊ�գ��������ǰ�ڵ�
                if (se.isLeftChild && current->right == NULL) {
                    printf("%c", current->data);
                }
                current = current->right;
                push(&s, current, 0); // ���Ϊ�Һ���
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