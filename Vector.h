#pragma once
using namespace std;
template <typename T>
class Vec
{
	class Node
	{
	public:
		Node* next;
		T data;
		Node(T x)
		{
			next = NULL;
			data = x;
		}
	};
	Node* head = NULL;
public:
	int Size = 0;
	Vec()
	{
		head = NULL;
		Size = 0;
	}
	void push_back(T Data)
	{
		Node* newnode = new Node(Data);
		if (head == NULL)
			head = newnode;
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newnode;
		}
		Size++;
	}
	bool have(T Data)
	{
		if (head->data == Data)
			return true;
		Node* temp = head;
		while (temp->next != NULL)
		{
			if (temp->data == Data)
				return true;
			temp = temp->next;
		}
		return false;
	}
	void insert(T Data, int index)
	{
		if (index < 0 || index > Size)
		{
			cout << "Index out of range!" << endl;
			return;
		}
		Node* newnode = new Node(Data);
		if (index == 0)
		{
			newnode->next = head;
			head = newnode;
			Size++;
			return;
		}
		Node* temp = head;
		for (int i = 0; i < index - 1; i++)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
		Size++;
	}
	T& operator[](int index)
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			if (count == index)
				return temp->data;
			temp = temp->next;
			count++;
		}
		cout << "out of range!"<<endl;
	 
	}
};