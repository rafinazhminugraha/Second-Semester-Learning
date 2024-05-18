#include <iostream>
using namespace std;

struct TREE
{
    int data;
    TREE *left, *right;
};

TREE *pohon, *root;

void deklarasi()
{
    pohon = NULL;
}

void insertTree(TREE **root, int nilai)
{
    TREE *new_node;

    if ((*root) == NULL)
    {
        new_node = new TREE;
        new_node->data = nilai;
        new_node->left = new_node->right = NULL;

        (*root) = new_node;
        (*root)->data = nilai;
        (*root)->left = (*root)->right = NULL;
        cout << "Data " << new_node->data << " sudah ditambahkan\n";
    }
    else if ((nilai < (*root)->data))
    {
        insertTree(&(*root)->left, nilai);
        cout << "Data " << nilai << " Sudah ditambahkan di sebelah kiri\n";
    }
    else
    {
        insertTree(&(*root)->right, nilai);
        cout << "Data " << nilai << " sudah ditambahkan di sebelah kanan\n";
    }
}

void preOrder(TREE *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TREE *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(TREE *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void findTree(TREE **root, int cari)
{
    int level = 0;
    TREE *temp;
    temp = new TREE;
    temp = (*root);

    while (temp != NULL)
    {
        level++;
        if (temp->data == cari)
        {
            cout << "Data " << cari << " ditemukan\n";
            return;
        }
        else if (temp->data > cari)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
            level--;
        }
    }
    cout << "Data " << cari << " tidak ditemukan\n";
    return;
}

void deleteTree()
{
    pohon = NULL;
    cout << "Data Sudah Terhapus\n";
}

int main() {

    deklarasi();
    insertTree(&pohon, 50);
    insertTree(&pohon, 17);
    insertTree(&pohon, 12);
    insertTree(&pohon, 23);
    insertTree(&pohon, 9);
    insertTree(&pohon, 14);
    insertTree(&pohon, 19);
    insertTree(&pohon, 72);
    insertTree(&pohon, 54);
    insertTree(&pohon, 70);
    insertTree(&pohon, 67);

    cout << endl;

    if (pohon == NULL) 
    {
        cout << "Tree dalam keadaan kosong" << std::endl;
    } 
    else 
    {
        cout << "Data Preorder" << endl;
        preOrder(pohon);
        cout << std::endl;

        cout << "Data InOrder" << endl;
        inOrder(pohon);
        cout << std::endl;

        cout << "Data PostOrder" << endl;
        postOrder(pohon);
        cout << std::endl;
    }

    findTree(&pohon, 10);
    findTree(&pohon, 4);
    deleteTree();

    if (pohon != NULL) 
    {
        postOrder(pohon);
    } 
    else {
        cout << "Tree dalam keadaan kosong" << endl;
    }

    return 0;
}
