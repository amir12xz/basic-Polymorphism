
#include <iostream>
using namespace std;

class function {
public:
    virtual void add() = 0;
    virtual void show() = 0;
};

class Node {
public:
    static Node* head; 
    Node* next = NULL;
    string name, id,type;

    Node(string name, string id,string type) {
        this->name = name;
        this->id = id;
        this->type = type;
        next = NULL;
    }
    Node() {}
};
Node* Node::head = NULL;

class worker : public Node, public function
{
    string name_w, id_w;
    static int count_w;
    Node** memory = new Node * [100];  

public:
    void add() override {
        cout << "enter your name: ";
        cin >> name_w;
        cout << "enter your id: ";
        cin >> id_w;

        Node* newnode = new Node(name_w, id_w,"worker");
        memory[count_w] = newnode;

        if (Node::head == NULL) {
            Node::head = newnode;
            count_w++;
        }
        else {
            bool test = false;
            if (head != NULL && count_w == 0)
            {
                count_w++;
                test = true;
            }
            memory[count_w - 1]->next = newnode;
            if (!test)
                count_w++;
        }
    }
    void show() override {
        for (int i = 0; i < count_w; i++) {
            cout << i + 1 << '-' << memory[i]->type << " " << memory[i]->name << " " << memory[i]->id << endl;
        }
    }
};
int worker::count_w = 0;

class employee : public Node, public function {
    string name_e, id_e;
    static int count_e;
    Node** memory = new Node * [100];
public:
    void add() override {
        cout << "enter your name: ";
        cin >> name_e;
        cout << "enter id: ";
        cin >> id_e;
        Node* newnode = new Node(name_e, id_e,"employee");
        memory[count_e] = newnode;
        if (Node::head == NULL) {
            Node::head = newnode;
            count_e++;
        }
        else {
            bool test = false;
            if (head != NULL && count_e == 0)
            {
                count_e++;
                test = true;
            }
            memory[count_e - 1]->next = newnode;
            if(!test)
            count_e++;
        }
    }
    void show() override {
        for (int i = 0; i < count_e; i++) {
            cout << i + 1<<'-' << memory[i]->type << " " << memory[i]->name << " " << memory[i]->id << endl;
        }
    }
};
int employee::count_e = 0;

int main() {
    worker w;
    employee e;
    int ch;
    while (true) {
        cout << "1-add worker|2-add employi|3-show worker|4-show empoloyee|5-exit ";
        cin >> ch;
        switch (ch) {
        case 1: w.add(); break;
        case 2: e.add(); break;
        case 3: w.show(); break;
        case 4: e.show(); break;
        case 5: return 0;
        default: cout << "invalid";
        }
    }
}
