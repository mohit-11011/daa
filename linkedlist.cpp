#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;

void create()
{
    char c;
    int d;
    while (true)
    {
        node *temp = new node;
        cout<<"enter the value"<<endl;
        cin >> d;
        temp->data = d;
        temp->next = head;
        head = temp;

    condition:
        cout << "do you want to add other element(y/n)" << endl;
        cin >> c;
        if (c == 'y' || c == 'Y')
            continue;
        else if ((c == 'n' || c == 'N'))
            break;
        else
        {
            cout << "enter a valid option" << endl;
            goto condition;
        }
    }
}
void print()
{
    cout << endl;
    if (head == NULL)
        cout << "the list is empty" << endl;
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
void insatstart()
{
    int num;
    cout << "enter the value to be added in beginning" << endl;
    cin >> num;
    node *temp = new node;
    temp->data = num;
    temp->next = head;
    head = temp;
}
void insatmid()
{

    if (head == NULL)
    {
        cout << "the list is empty so value cannot be added";
    }
    else
    {
        int num, d;
        cout << "enter the value of node after which new number is to be inserted" << endl;
        cin >> num;
        cout << "enter the value to be added" << endl;
        cin >> d;
        node *datanode = new node;
        datanode->data = d;
        datanode->next = NULL;
        node *temp = new node;
        temp = head;
        while (temp!= NULL && (temp->data)!= num)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            cout << "The value was not found" << endl;
        else if (temp->next == NULL)
        {
            temp->next = datanode;
        }
        else
        {
            datanode->next = temp->next;
            temp->next = datanode;
        }
    }
}
void insatend()
{
    int d;
    cout << "enter the value to be added" << endl;
    cin >> d;
    node *datanode = new node;
    datanode->data = d;
    datanode->next = NULL;
    if (head == NULL)
        head = datanode;
    else
    {
        node *temp = new node;
        temp=head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = datanode;
    }
}
void delstart()
{
    if (head == NULL)
        cout << "the list is empty so nothing can be deleted" << endl;
    else
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }
}

void delend()
{
    if (head == NULL)
        cout << "the list is empty so nothing can be deleted" << endl;
    else
    {
        node *temp = head;
        node *pre = temp;
        while (temp->next != NULL)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp == head)
            head = NULL;
        else
            pre->next = NULL;
        delete temp;
    }
}
void delmid()
{
    if (head == NULL)
        cout << "the list is empty so nothing can be deleted" << endl;
    else
    {
        int d;
        node *temp = head;
        node *pre = temp;
        cout << "enter the value to be deleted" << endl;
        cin >> d;
        while (temp != NULL && temp->data != d)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            cout << "The value was not found" << endl;
        else if (temp == head)
            head = head->next;
        else if (temp->next == NULL)
            pre->next = NULL;
        else
            pre->next = temp->next;
        delete temp;
    }
}
void search()
{
    int d, c = 1;
    cout << "enter the node to be search" << endl;
    cin >> d;
    node *temp = head;
    while (temp != NULL && temp->data != d)
    {

        temp = temp->next;
        c++;
    }
    if (temp == NULL)
        cout << "value was not found" << endl;
    else
        cout << "value was found at " << c << "location" << endl;
}
int main()
{
    int choice;
    while (true)
    {
        cout << "\nenter the choice" << endl
             << "1.)create" << endl
             << "2.)display" << endl
             << "3.)insertion at start" << endl
             << "4.)insertion in specific location" << endl
             << "5.)insertion at end" << endl
             << "6.)del from begin" << endl
             << "7.)del at end" << endl
             << "8.)del in specific location" << endl
             << "9.) search" << endl
             << "10.)exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            print();
            break;
        case 3:
            insatstart();
            break;
        case 4:
            insatmid();
            break;
        case 5:
            insatend();
            break;
        case 6:
            delstart();
            break;
        case 7:
            delend();
            break;
        case 8:
            delmid();
            break;
        case 9:
            search();
            break;
        case 10:
            return 0;

        default:
            cout << "no valid command was given" << endl;
            break;
        }
    }
    return 0;
}