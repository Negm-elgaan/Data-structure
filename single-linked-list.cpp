#include <iostream>

using namespace std;
struct node
{
    int data ;
    node* next;
};
class linkedlist
{
    public:
        node* head;
        linkedlist()
        {
            head = NULL;
        }
        bool isempty()
        {
            return (head == NULL);
        }
        void insertatfirst(int newval)
        {
            node* newnode = new node();
            newnode->data = newval;
            if(isempty())
            {
                newnode->next = NULL;
                head = newnode;
            }
            else
            {
                newnode->next = head ;
                head = newnode;
            }
        }
        void insertatlast(int newitem)
        {
            node *newnode = new node();
            newnode->data = newitem;
            if(isempty())
            {
                newnode->next = NULL;
                head = newnode;
            }
            else
            {
                node *temp = head;
                node *newnode = new node();
                newnode->data = newitem;
                while(temp->next != NULL)
                {
                temp = temp->next;
                }
                temp->next = newnode;
                newnode->next = NULL;
            }
        }
        bool isfound(int value)
        {
            node *temp = head ;
            while (temp->next != NULL)
            {
                if(temp->data == value)
                    return true;
                temp = temp->next;
            }
            if(temp->data == value)
                return true;
            else
                return false;
        }
        void insertafter(int value,int newitem)
        {
            node *temp = head;
            node *newnode = new node();
            newnode->data = newitem;
            while (temp->data != value)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        void insertbefore(int value,int newitem)
        {
           
            node *temp = head;
            node *newnode = new node();
            newnode->data = newitem;
            while (temp != NULL && temp->next->data != value)
            {
                //pre = temp;
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        void append(int value)
        {
            if(isempty())
                insertatfirst(value);
            else
            {
            node *temp = head;
            node *newnode = new node();
            newnode->data = value;
            newnode->next = NULL;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode ;
            }
        }
        void display()
        {
            node* temp = new node();
            temp = head ;
            int counter = 0 ;
            while(temp != NULL)
            {
                counter++;
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << counter << endl;
        }
        void deletenode(int value)
        {
            node *temp = head ;
            node *pre ;
            while (temp->next != NULL)
            {
                if(temp->data == value && temp == head)
                {
                    head = head->next;
                    delete temp;
                    return ;
                }
                else if(temp->data == value && temp != head)
                {
                    pre->next = temp->next;
                    delete temp;
                    return ;
                }
                else
                {
                    pre = temp ;
                    temp = temp->next;
                }
            }
        }
};

int main()
{
    linkedlist newlinked ;
    newlinked = linkedlist();
    newlinked.insertatlast(10);
    newlinked.insertatlast(20);
    newlinked.insertatlast(30);
    newlinked.insertatlast(40);
    newlinked.display();
    return 0;
}

