#include <iostream>
using namespace std;

class test
{
public:
    string name, last_name;
    test* right, * left, * pre;

    test()
    {
        right = NULL;
        left = NULL;
    }

    test* add(test*&, string, string);
    bool search(test*, string, string);
};
bool connect(test* current, test* newnode)
{
    if (current->left == NULL)
    {
        current->left = newnode;
        return true;
    }
    else if (current->right == NULL)
    {
        current->right = newnode;
        return true;
    }
    if (connect(current->left, newnode))
        return true;
    return connect(current->right, newnode);
}

test* test::add(test*& head, string newName, string newLastName)
{
    test* newnode = new test();
    newnode->name = newName;
    newnode->last_name = newLastName;

    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    connect(head, newnode);
    return head;
}

bool test::search(test* head, string Name, string Lastname)
{
    if (head == NULL)
        return false;

    if (head->name == Name && head->last_name == Lastname)
        return true;

    if (head->left && search(head->left, Name, Lastname))
        return true;

    if (head->right && search(head->right, Name, Lastname))
        return true;

    return false;
}

int main()
{
    bool start = true;
    int check;
    string name, lastName;
    test* head = NULL;

    while (start)
    {
        cout << "1-add | 2-search | 3-exit: ";
        cin >> check;

        switch (check)
        {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter last name: ";
            cin >> lastName;
            head = test().add(head, name, lastName);
            break;

        case 2:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter last name: ";
            cin >> lastName;
            if (test().search(head, name, lastName))
                cout << name << " " << lastName << " exists." << endl;
            else
                cout << "Not exist." << endl;
            break;

        case 3:
            start = false;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}