# <h1 align="center">Laporan Praktikum Modul 10 Tree </h1>
<p align="center">Rizky Al Kahfi</p>

## Dasar Teori
- Pengertian Rekursif

Secara harfiah, rekursif adalah suatu proses pengulangan yang dilakukan dengan cara kesamaan-diri, yaitu suatu prosedur atau fungsi yang memanggil dirinya sendiri secara langsung maupun tidak langsung. Dalam pemrograman, rekursif digunakan untuk menyelesaikan permasalahan dengan cara memecah masalah besar menjadi submasalah yang lebih kecil hingga mencapai kondisi dasar (base case).
Prosedur dan fungsi merupakan bentuk subprogram yang sangat bermanfaat dalam pemrograman, khususnya pada program atau proyek berskala besar. Salah satu teknik yang sering digunakan dalam subprogram adalah rekursi, karena dapat menyederhanakan logika penyelesaian masalah tertentu.
Manfaat penggunaan subprogram, termasuk subprogram rekursif, antara lain sebagai berikut:
1. Meningkatkan readability, yaitu mempermudah pembacaan dan pemahaman kode program.
2. Meningkatkan modularity, yaitu memecah program yang kompleks menjadi modul-modul atau bagian-bagian kecil sesuai dengan fungsinya, sehingga memudahkan proses pengecekan, pengujian (testing), dan pelokalan kesalahan.
3. Meningkatkan reusability, yaitu subprogram dapat digunakan kembali berkali-kali hanya dengan memanggilnya, tanpa perlu menuliskan ulang perintah-perintah yang sama.

Dengan demikian, penggunaan rekursif dalam subprogram dapat membantu menghasilkan program yang lebih terstruktur, mudah dipahami, dan efisien dalam pengembangan maupun pemeliharaan.
## Guided

### 1. [bst.h]

```C++
#ifndef BST_H
#define BST_H

#define Nil NULL

// Struktur node BST
struct BST {
    int angka;
    BST *left;
    BST *right;
};

// Tipe data
typedef BST* node;
typedef BST* BinTree;

// Fungsi dasar
bool isEmpty(BinTree tree);
void createTree(BinTree &tree);

// Alokasi & dealokasi
node alokasi(int angkaInput);
void dealokasi(node nodeHapus);

// Operasi BST
void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angkaCari);

// Traversal
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

// Delete
bool deleteNode(BinTree &tree, int angka);

// Utility
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);

// Informasi tree
int size(BinTree tree);
int height(BinTree tree);

#endif
```
Berisi pendefinisian struktur node serta deklarasi prototipe fungsi BST yang berfungsi sebagai penghubung antara main.cpp dan bst.cpp.

### 2. [bst.cpp]

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree)
```

Merupakan file implementasi yang memuat logika dan algoritma Binary Search Tree (BST). Pada file ini didefinisikan seluruh fungsi BST, meliputi pembuatan tree, penyisipan node secara rekursif, pencarian data, traversal (preorder, inorder, dan postorder), penghapusan node berdasarkan kondisi (leaf, satu child, atau dua child), serta perhitungan ukuran dan tinggi tree. File ini menjadi inti dari proses pengolahan struktur data BST.

### 3. [main.cpp]

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Merupakan file program utama yang berisi fungsi main() beserta menu interaktif. File ini berperan sebagai antarmuka pengguna untuk memanggil fungsi-fungsi BST yang didefinisikan pada bst.cpp melalui bst.h. Melalui menu yang tersedia, pengguna dapat melakukan operasi seperti insert, delete, search, traversal, serta operasi BST lainnya.

## Unguided 

## SOAL 1
### 1. [bstree.h]

```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInOrder(address root);

#endif
```
### 2. [bstree.cpp]
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == NULL || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " ";
        printInOrder(root->right);
    }
}
```
### 3. [main.cpp]

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);

    return 0;
}
```

#### Output:
<img width="436" height="95" alt="image" src="https://github.com/user-attachments/assets/ee27c4e4-6770-41a0-ad72-27f0eb42b525" />


Program ini berfungsi untuk mengelola data bertipe integer menggunakan struktur Binary Search Tree (BST). Data disimpan secara terurut dan ditampilkan dalam bentuk urutan naik melalui proses traversal InOrder.


#### Full code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a63f0ae3-bab9-4ac7-b55c-8d509d9f0f35" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2e47b137-ea51-45ea-bade-5af3149b7edf" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/c06080cd-3eef-4962-9541-145a50c25bc7" />


## SOAL 2
### 1. [bstree.h]

```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
};

typedef Node* address;

address createNode(int x);
void insertNode(address &root, int x);
void inOrder(address root);

int hitungJumlahNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root);

#endif
```
### 2. [bstree.cpp]
```C++
#include "bstree.h"

address createNode(int x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, int x) {
    if (root == NULL) {
        root = createNode(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL)
        return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotal(address root) {
    if (root == NULL)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root) {
    if (root == NULL)
        return 0;

    int kiri = hitungKedalaman(root->left);
    int kanan = hitungKedalaman(root->right);

    return (kiri > kanan ? kiri : kanan) + 1;
}
```
### 3. [main.cpp]

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "Hello world!" << endl;
    inOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
```

#### Output:
<img width="689" height="234" alt="image" src="https://github.com/user-attachments/assets/56c6418a-1813-4aa8-bcfb-b884c9687eb3" />

Program ini berfungsi untuk menyimpan dan memproses data numerik menggunakan struktur Binary Search Tree (BST). Data ditampilkan dalam urutan teratur, sekaligus dilakukan perhitungan terhadap kedalaman tree, jumlah node, serta total nilai dari seluruh node.

#### Full code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/99d0e496-68c6-4421-842c-aa81f6e3629b" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/465b93eb-d283-428e-bc63-4dd6702f5495" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/9e383a9a-48b6-437e-8eda-866238ad4c1d" />



## SOAL 3
### 1. [bstree.h]

```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BSTree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);

public:
    BSTree();
    void insert(int value);

    void printPreOrder();
    void printInOrder();
    void printPostOrder();
};

#endif
```
### 2. [bstree.cpp]
```C++
#include "bstree.h"

BSTree::BSTree() {
    root = nullptr;
}

Node* BSTree::insert(Node* node, int value) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);

    return node;
}

void BSTree::insert(int value) {
    root = insert(root, value);
}

void BSTree::preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BSTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void BSTree::postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void BSTree::printPreOrder() {
    preOrder(root);
    cout << endl;
}

void BSTree::printInOrder() {
    inOrder(root);
    cout << endl;
}

void BSTree::printPostOrder() {
    postOrder(root);
    cout << endl;
}
```
### 3. [main.cpp]

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    BSTree tree;

    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    tree.insert(2);
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);

    cout << "Pre-order traversal : ";
    tree.printPreOrder();

    cout << "In-order traversal  : ";
    tree.printInOrder();

    cout << "Post-order traversal: ";
    tree.printPostOrder();

    return 0;
}

```

#### Output:
<img width="694" height="201" alt="image" src="https://github.com/user-attachments/assets/645d0bc5-4b6b-476a-885e-71a138858a9c" />

Program ini digunakan untuk mengimplementasikan struktur data Binary Search Tree (BST) serta menampilkan hasil penelusurannya melalui metode traversal pre-order, in-order, dan post-order. Setiap data dimasukkan ke dalam BST mengikuti aturan bahwa nilai yang lebih kecil ditempatkan di kiri dan nilai yang lebih besar di kanan root. Setelah itu, traversal dilakukan untuk menampilkan urutan node sesuai metode yang dipilih.

#### Full code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/8af9e4e1-6cb8-454c-a734-e604419108d0" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/3a15441d-adf2-4b52-83a8-50994633aa6a" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6033c98d-62f3-4dae-a563-1706d55ba2ee" />


## Kesimpulan
Berdasarkan hasil praktikum dan pembelajaran pada Modul 10, materi yang dipelajari berfokus pada Binary Search Tree (BST). Melalui praktikum ini, diperoleh pemahaman mengenai struktur data tree serta penerapan konsep rekursi dalam proses insert, search, traversal, dan delete. Hasil praktikum menunjukkan bahwa BST memudahkan pengelolaan data secara terurut dengan efisien. Selain itu, pembelajaran ini juga meningkatkan pemahaman terhadap struktur data non-linear serta penerapan pemrograman yang bersifat modular.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
