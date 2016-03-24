#include <cstdio>

struct node {
    int value;
    node *left, *right;
    node() {}
} data[200000];

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d", root->value);
    inorder(root->right);
}

void preorder(node *root) {
    if (root == NULL)
        return;
    printf(" %d", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->value);
}

int main() {
    int n, value, i;
    bool print = false;
    while (scanf("%d", &n) != EOF) {
        if (print)
            printf("\n");
        print = true;
        node *root;
        if (n != 0) {
            scanf("%d", &value);
            root = data;
            root->value = value;
            root->left = root->right = NULL;
            for (i = 1; i < n; i++) {
                scanf("%d", &data[i].value);
                data[i].left = data[i].right = NULL;
                node *temp = root, *last;
                while (temp != NULL) {
                    last = temp;
                    if (data[i].value <= temp->value)
                        temp = temp->left;
                    else
                        temp = temp->right;
                }
                if (data[i].value <= last->value)
                    last->left = data + i;
                else
                    last->right = data + i;
            }
        } else
            root = NULL;
        printf("Inorder:");
        inorder(root);
        printf("\n");
        printf("Preorder:");
        preorder(root);
        printf("\n");
        printf("Postorder:");
        postorder(root);
        printf("\n");
    }
    return 0;
}

