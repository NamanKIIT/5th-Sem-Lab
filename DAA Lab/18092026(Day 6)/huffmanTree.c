#include <stdio.h>
#include <stdlib.h>

struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left, *right;
};

void insert(struct SYMBOL *q[], int *n, struct SYMBOL *x) {
    int i = (*n)++;
    q[i] = x;

    while (i > 0 && q[(i - 1) / 2]->frequency > q[i]->frequency) {
        struct SYMBOL *t = q[i];
        q[i] = q[(i - 1) / 2];
        q[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

struct SYMBOL *removeMin(struct SYMBOL *q[], int *n) {
    struct SYMBOL *x = q[0];
    q[0] = q[--(*n)];

    int i = 0;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < *n && q[l]->frequency < q[s]->frequency)
            s = l;

        if (r < *n && q[r]->frequency < q[s]->frequency)
            s = r;

        if (s == i)
            break;

        struct SYMBOL *t = q[i];
        q[i] = q[s];
        q[s] = t;
        i = s;
    }

    return x;
}

void inorder(struct SYMBOL *root) {
    if (root == NULL)
        return;

    inorder(root->left);

    if (root->alphabet != '\0')
        printf("%c ", root->alphabet);

    inorder(root->right);
}

int main() {
    int n, i, f;
    char c;
    struct SYMBOL *q[100], *left, *right, *root;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    printf("Enter the alphabets: ");
    for (i = 0; i < n; i++) {
        scanf(" %c", &c);
        q[i] = malloc(sizeof(struct SYMBOL));
        q[i]->alphabet = c;
        q[i]->left = q[i]->right = NULL;
    }

    printf("Enter its frequencies: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &f);
        q[i]->frequency = f;
    }

    int size = n;

    for (i = n / 2 - 1; i >= 0; i--) {
        int j = i;

        while (1) {
            int l = 2 * j + 1;
            int r = 2 * j + 2;
            int s = j;

            if (l < size && q[l]->frequency < q[s]->frequency)
                s = l;

            if (r < size && q[r]->frequency < q[s]->frequency)
                s = r;

            if (s == j)
                break;

            struct SYMBOL *t = q[j];
            q[j] = q[s];
            q[s] = t;
            j = s;
        }
    }

    while (size > 1) {
        left = removeMin(q, &size);
        right = removeMin(q, &size);

        root = malloc(sizeof(struct SYMBOL));
        root->alphabet = '\0';
        root->frequency = left->frequency + right->frequency;
        root->left = left;
        root->right = right;

        insert(q, &size, root);
    }

    root = q[0];

    printf("In-order traversal of the tree (Huffman): ");
    inorder(root);
    printf("\n");

    return 0;
}