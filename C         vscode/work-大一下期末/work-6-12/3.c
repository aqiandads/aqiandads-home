#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
int isEmpty(Stack *s);
int precedence(char op);
void infixNotation(char postfix[], char infix[]);

int main() {
    char postfix[] = "ab+c*d+e*";
    char infix[MAX_SIZE];

    infixNotation(postfix, infix);

    printf("中缀表达式: %s\n", infix);

    return 0;
}

void infixNotation(char postfix[], char infix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;

    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isalpha(postfix[i])) {
            infix[j++] = postfix[i];
        } else if (postfix[i] == '+' || postfix[i] == '-') {
            while (!isEmpty(&s) && peek(&s) != '(' && precedence(postfix[i]) <= precedence(peek(&s))) {
                infix[j++] = pop(&s);
            }
            push(&s, postfix[i]);
        } else if (postfix[i] == '*' || postfix[i] == '/') {
            while (!isEmpty(&s) && peek(&s) != '(' && precedence(postfix[i]) <= precedence(peek(&s))) {
                infix[j++] = pop(&s);
            }
            push(&s, postfix[i]);
        } else if (postfix[i] == '(') {
            push(&s, postfix[i]);
        } else if (postfix[i] == ')') {
            while (peek(&s) != '(') {
                infix[j++] = pop(&s);
            }
            pop(&s); // 弹出左括号
        }
    }

    while (!isEmpty(&s)) {
        infix[j++] = pop(&s);
    }

    infix[j] = '\0';
}

void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (s->top >= 0) {
        return s->data[s->top];
    }
    return '\0';
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}