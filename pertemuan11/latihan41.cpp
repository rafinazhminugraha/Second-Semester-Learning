#include <iostream>
using namespace std;

const int kapasitas = 5;
enum Color { BLUE, RED, GREEN };

struct Node {
    Color data;
    Node* next;
};

struct Stack {
    Node* top;
    
    Stack() : top(nullptr) {}

    void push(Color data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    Color peek() {
        if (top != nullptr) {
            return top->data;
        }
        return BLUE; // default value
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void print() {
        Node* temp = top;
        while (temp != nullptr) {
            switch(temp->data) {
                case BLUE: cout << "Bola Biru\n"; break;
                case RED: cout << "Bola Merah\n"; break;
                case GREEN: cout << "Bola Hijau\n"; break;
            }
            temp = temp->next;
        }
        cout << "----\n";
    }
};

void moveBall(Stack& from, Stack& to) {
    Color ball = from.peek();
    from.pop();
    to.push(ball);
}

int main() {
    Stack tubes[4];

    // Inisialisasi tabung
    tubes[0].push(GREEN); tubes[0].push(RED); tubes[0].push(BLUE);
    tubes[1].push(GREEN); tubes[1].push(RED); tubes[1].push(RED);
    tubes[2].push(BLUE); tubes[2].push(BLUE); tubes[2].push(GREEN);

    // Pindahkan bola-bola ke tabung yang sesuai
    while (!tubes[0].isEmpty() || !tubes[1].isEmpty() || !tubes[2].isEmpty()) {
        for (int i = 0; i < 3; ++i) {
            if (!tubes[i].isEmpty()) {
                Color ball = tubes[i].peek();
                tubes[i].pop();
                tubes[ball].push(ball);
            }
        }
    }

    // Cetak isi setiap tabung
    for (int i = 0; i < 4; ++i) {
        cout << "Tabung " << i+1 << ":\n";
        tubes[i].print();
    }

    return 0;
}
