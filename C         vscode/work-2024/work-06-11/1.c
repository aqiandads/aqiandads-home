#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode **children;
    int child_count;
} TreeNode;

TreeNode* create_node(int value) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(TreeNode *parent, TreeNode *child) {
    parent->child_count++;
    parent->children = (TreeNode**)realloc(parent->children, parent->child_count * sizeof(TreeNode*));
    parent->children[parent->child_count - 1] = child;
}

void free_tree(TreeNode *root) {
    if (root == NULL) return;
    for (int i = 0; i < root->child_count; i++) {
        free_tree(root->children[i]);
    }
    free(root->children);
    free(root);
}

void print_tree(TreeNode *root, int level) {
    if (root == NULL) return;
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("{%d}\\n", root->value);
    for (int i = 0; i < root->child_count; i++) {
        print_tree(root->children[i], level + 1);
    }
}

TreeNode* build_tree(const char *input) {
    TreeNode *root = NULL;
    TreeNode *current = NULL;
    char *token = strtok((char*)input, "(,)");

    while (token != NULL) {
        if (isdigit(token[0])) {
            int value = atoi(token);
            TreeNode *node = create_node(value);
            if (root == NULL) {
                root = node;
            }
            if (current != NULL) {
                add_child(current, node);
            }
            current = node;
        } else if (token[0] == '(') {
            // Do nothing, just move to the next token
        } else if (token[0] == ')') {
            current = current->children[0];
        }
        token = strtok(NULL, "(,)");
    }

    return root;
}

int main() {
    const char *input_str = "9(2(1,1(1)),4(1,3(2(2(1,1)),1)),3(1,1,1(1)))";
    TreeNode *tree = build_tree(input_str);
    print_tree(tree, 0);
    free_tree(tree);
    return 0;
}