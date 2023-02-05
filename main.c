#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    FIB,
    LIT
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;


// function to create a new node
Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeValue(int value) {
    Node *newNode = makeFunc(LIT);
    newNode->value = value;
    return newNode;
}

// fibonacci function using dynamic programming
int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

// function to calculate the value of a node
int calc(Node* node) {
    if (node->type == ADD) {
        return node->left->value + node->right->value;
    }
    else if (node->type == SUB) {
        return node->left->value - node->right->value;
    }
    else if (node->type == MUL) {
        return node->left->value * node->right->value;
    }
    else if (node->type == DIV) {
        return node->left->value / node->right->value;
    }
    else if (node->type == ABS) {
        return abs(node->left->value);
    }
    else if (node->type == FIB) {
        return fibonacci(node->left->value);
    }
    else if (node->type == LIT) {
        return node->value;
    }
    printf("Invalid node type %d\n", node->type);
    exit(1);
}


int main() {

    Node *add = makeFunc(ADD);
    add->left = makeValue(10);
    add->right = makeValue(6);
    Node *mul = makeFunc(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);
    Node *sub = makeFunc(SUB);
    sub->left = makeValue(calc(add));
    sub->right = makeValue(calc(mul));
    Node *fibo = makeFunc(FIB);
    fibo->left = makeValue(abs(calc(sub)));
    fibo->right = makeValue(NULL);
    fibo->value = fibonacci(calc(fibo->left));
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

}