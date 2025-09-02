#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    int32_t data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node(int32_t value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Error.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node *root, int32_t value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value <= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void in_order_traversal(Node *root, int32_t *arr, int *index) {
    if (root != NULL) {
        in_order_traversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        in_order_traversal(root->right, arr, index);
    }
}

void free_tree(Node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    if (!input_file) {
        perror("Error");
        return 1;
    }

    int32_t N;
    fread(&N, sizeof(int32_t), 1, input_file);
    if (N == 0) {
        FILE *output_file = fopen("output.bin", "wb");
        fclose(output_file);
        fclose(input_file);
        return 0;
    }

    int32_t *arr = (int32_t *)malloc(N * sizeof(int32_t));
    if (!arr) {
        fprintf(stderr, "Error.\n");
        fclose(input_file);
        return 1;
    }

    fread(arr, sizeof(int32_t), N, input_file);
    fclose(input_file);
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, arr[i]);
    }

    int index = 0;
    in_order_traversal(root, arr, &index);

    FILE *output_file = fopen("output.bin", "wb");
    if (!output_file) {
        perror("Error");
        free(arr);
        free_tree(root);
        return 1;
    }

    fwrite(arr, sizeof(int32_t), N, output_file);
    fclose(output_file);
    free(arr);
    free_tree(root);
    return 0;
}
