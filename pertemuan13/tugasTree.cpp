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

void printJudul()
{
    cout << "\033[2J\033[1;1H";
    cout << "==============================\n";
    cout << "   TUGAS SDA PERT 13 - TREE\n";
    cout << "rafi nazhmi nugraha - 2301303\n";
    cout << "==============================\n\n";
}

void pause()
{
    cout << "\n";
    system("pause");
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
        cout << "Data " << nilai << " sudah ditambahkan di sebelah kiri\n";
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
    TREE *temp;
    temp = (*root);

    while (temp != NULL)
    {
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
        }
    }
    cout << "Data " << cari << " tidak ditemukan\n";
}

void deleteTree()
{
    if (root != NULL)
    {
        pohon = NULL;
        cout << "Data Sudah Terhapus\n";
    }
}

int countNodes(TREE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}


int main()
{
    int cari;
    deklarasi();

    while (true)
    {
        printJudul();
        cout << "[1] Input data tree\n";
        cout << "[2] Penelusuran preOrder\n";
        cout << "[3] Penelusuran inOrder\n";
        cout << "[4] Penelusuran postOrder\n";
        cout << "[5] Cari data tree\n";
        cout << "[6] Hapus seluruh node\n";
        cout << "[7] Hitung jumlah node dalam tree\n";
        cout << "[8] Out\n";

        int choice;
        cout << "\n> "; cin >> choice;

        if (choice == 1)
        {
            printJudul();
            int banyakData;
            cout << "Berapa banyak data yang ingin anda masukkan: "; cin >> banyakData;
            printJudul();
            for (int i = 0; i < banyakData; i++)
            {
                int nilai;
                cout << "Masukkan nilai ke-" << i+1 << ": "; cin >> nilai;
                insertTree(&pohon, nilai);
                cout << "\n";
            }
            pause();
        }
        else if (choice == 2)
        {
            printJudul();
            if (pohon != NULL)
            {
                cout << "Penelusuran preOrder: ";
                preOrder(pohon);
                cout << endl;
                pause();
            }
            else
            {
                cout << "Tree dalam keadaan kosong\n";
                pause();
            }
        }
        else if (choice == 3)
        {
            printJudul();
            if (pohon != NULL)
            {
                cout << "Penelusuran inOrder: ";
                inOrder(pohon);
                cout << endl;
                pause();
            }
            else
            {
                cout << "Tree dalam keadaan kosong\n";
                pause();
            }
        }
        else if (choice == 4)
        {
            printJudul();
            if (pohon != NULL)
            {
                cout << "Penelusuran postOrder: ";
                postOrder(pohon);
                cout << endl;
                pause();
            }
            else
            {
                cout << "Tree dalam keadaan kosong\n";
                pause();
            }
        }
        else if (choice == 5)
        {
            printJudul();
            int cari;
            cout << "Masukkan nilai yang dicari: "; cin >> cari;
            findTree(&pohon, cari);
            pause();
        }
        else if (choice == 6)
        {
            printJudul();
            deleteTree();
            pohon = NULL;
            cout << "Seluruh node telah dihapus\n";
            pause();
        }
        else if (choice == 7)
        {
            printJudul();
            cout << "Jumlah node dalam tree: " << countNodes(pohon) << endl;
            pause();
        }
        else if (choice == 8)
        {
            cout << "Terimakasih\n";
            break;
        }
        else
        {
            cout << "Pilihan tidak valid\n";
        }
    }

    return 0;
}