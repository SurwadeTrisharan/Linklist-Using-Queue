#include<iostream>
using namespace std;

struct node
{
	int info;
	node* link;
};
node* front = 0, * rear = 0;
void enqueue(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = 0;
	if (front == 0 && rear == 0)
		front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}
	return;
}

int dequeue()
{
	int x;
	node* p;
	if (front == 0 && rear == 0)
	{
		cout << "Queue is empty"<<endl;
		return -1;
	}
	x = front->info; 
	p = front;
	if (front == rear)
		front = rear = 0;
	else
		front = front->link;
		delete p;
		return x;

}

void display()
{
	node* t;
	t = front;
	if (t == 0)
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	while (t != 0)
	{
		cout <<"The Elements of Queue is: " << t->info << endl;
		t = t->link;
	}
	return;
}

int main()
{
	int value, choice;
	do
	{
		cout << "Enter 1.Enqueue 2.Dequeue 3.Display 4.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the value to Enqueue" << endl;
			cin >> value;
			enqueue(value);
			break;
		case 2:value = dequeue();
			cout << "The value deleted is: " << value << endl;
			break;
		case 3:display();
			break;
		default:cout << "Exiting" << endl;
			choice = 4;
		}
	} while (choice != 4);
}