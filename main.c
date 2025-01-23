#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"
int precedence(char op) {

        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
        return 0;
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Remove '('
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';
}
int evaluate_postfix(const char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to int
        } else {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (ch) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }
    }

    return pop(&stack);
}

int main()
{
    const char* infix = "4*(3+2)-4";
    char postfix[100];
    infix_to_postfix(infix,postfix);
    printf("The result of evaluating postfix expression : %d\n",evaluate_postfix(postfix));

    return 0;
}
