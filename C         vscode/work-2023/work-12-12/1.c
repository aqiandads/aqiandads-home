#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 1. 尾插法创建单链表
Node *create_tail_list() {
    char arr;
    int shu;
    Node* head = NULL;
    Node* tail = NULL;
    do{
        printf("请输入一个数字:");
        scanf("%d",&shu);
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = shu;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
        printf("你想要添加一个数吗？y/n\n");
        getchar();
        scanf("%c",&arr);
    }while(arr != 'n');
    return head;
}

// 2. 头插法创建单链表
Node* create_head_list() {
    char arr;
    int shu;
    Node* head = NULL;
    do{
        printf("请输入一个数字:");
        scanf("%d",&shu);
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = shu;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        printf("你想要添加一个数吗？y/n\n");
        getchar();
        scanf("%c",&arr);
    }while(arr != 'n');
    return head;
}

// 3. 创建有序的单链表
Node* create_sorted_list() {
    printf("你想要添加一个数吗？y/n\n");
    getchar();
    char arr;
    int shu;
    scanf("%c",&arr);
    if(arr == 'y'){
        printf("请输入一个数字:");
        scanf("%d",&shu);
    }
    if(arr == 'n'){
        return NULL;
    }
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = shu;
    head->next = create_sorted_list();
    int temp = head->data;
    
    return head;
}

// 4. 打印单链表
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 5. 删除指定节点
Node* delete_node(Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head;
    int count = 0;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL || count == position) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    return head;
}

// 6. 单链表逆序
Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 7. 合并两个单链表
Node* merge_lists(Node* list1, Node* list2) {
    Node* dummy = (Node*) malloc(sizeof(Node));
    Node* current;
}


    int main(){
        printf("1.尾插法创建单链表\n");
        printf("2.头插法创建单链表\n");
        printf("3.创建有序的单链表\n");
        printf("4.打印单链表\n");
        printf("5.删除指定节点\n");
        printf("6.单链表逆序，并打印输出\n");
        printf("7.合并前面创建的两个单链表，并打印输出\n");
        printf("8.退出\n");
        printf("请选择相应的选项:");
        int i,a;
        Node *head1 = NULL;
        Node *head2 = NULL;
        Node *head3 = NULL;

        do{
            scanf("%d",&i);
            switch(i){
                case 1:
                    head1 = create_tail_list();     
                    break;
                case 2:
                    head2 = create_head_list();
                    break;
                case 3:
                    head3 = create_sorted_list();
                    break;
                case 4:
                    printf("打印哪个链表？1/2/3\n");
                    scanf("%d",&a);
                    if(a == 1){
                        print_list(head1);
                    }
                    if(a == 2){
                        print_list(head2);
                    }
                    if(a == 3){
                        print_list(head3);
                    }
                    break;
                case 5:break;
                case 6:break;
                case 7:break;
                case 8:break;
            }
            if(i != 8){
                printf("请选择相应的选项:");
            }
        }while(i != 8);
    }