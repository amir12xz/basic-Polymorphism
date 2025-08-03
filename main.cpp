
#include <iostream>
using namespace std;

class function {
public:
    virtual void add() = 0;
    virtual void show() = 0;
    virtual void Delete() = 0;
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
    ~Node() {
       
    }
};
Node* Node::head = NULL;

class worker : public Node, public function
{
    string name_w, id_w,temp_id;
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
    void Delete()override
    {
        int index = 0;
        cout << "enter id ";
        cin >> temp_id;
        for (int i = 0; i < worker::count_w; i++)
        {
            if (memory[i]->id == temp_id)
            {
                index = i;
                break;
            }
            if (i == worker::count_w-1)
            {
                cout << "not found";
                return;
            }
        }
        if (index == 0&&memory[index]->next==NULL)
        {
            delete memory[index];
            cout << "deleted";
            worker::count_w--;
        }
        else if (index == 0 && memory[index]->next != NULL)
        {
            Node* to_delete = memory[index];
            memory[index] = memory[index]->next;
            delete to_delete;
            cout << "deleted";
            worker::count_w--;
            cout << "deleted";
        }
        else
        {
            Node* temp,*next_temp;
            temp = memory[index-1];
            next_temp = memory[index]->next;
            temp->next = next_temp;
            delete temp;
            worker::count_w--;
            cout << "deleted";
        }
    }
    ~worker() {
        delete[]memory;
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
    void Delete() override
    {
        int index = 0;
        cout << "enter id ";
        cin >> id_e;
        for (int i = 0; i < employee::count_e; i++)
        {
            if (memory[i]->id == id_e)
            {
                index = i;
                break;
            }
            if (i == employee::count_e - 1)
            {
                cout << "not found";
                return;
            }
        }
        if (index == 0 && memory[index]->next == NULL)
        {
            delete memory[index];
            cout << "deleted";
            employee::count_e--;
        }
        else if (index == 0 && memory[index]->next != NULL)
        {
            Node* to_delete = memory[index];
            memory[index] = memory[index]->next;
            delete to_delete;
            cout << "deleted";
            employee::count_e--;
            cout << "deleted";
        }
        else
        {
            Node* temp, * next_temp;
            temp = memory[index - 1];
            next_temp = memory[index]->next;
            temp->next = next_temp;
            delete temp;
            employee::count_e--;
            cout << "deleted";
        }
    }
    ~employee() {
        delete[]memory;
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
