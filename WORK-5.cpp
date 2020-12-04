/*
Name : Mohammed yousif musa idress
Department : Computer 
Class : Secand Class
*/
#include <iostream>
#include <string>
using namespace std;
const int maxSize = 10;
/*LINKED LIST*/
class Linked_List
{
private:
    struct Node
    {
        int item;
        Node*next;
    };
    Node*first;
    Node*last;
    int length;
public:
    Linked_List(){
    first = last = NULL;
    length = 0;
    }

    bool isEmpty() //To check if the list is empty
    {
        return length == 0;
    }

    void addFirst(int num) //To add an item and place it at the beginning of the list
    {
     
     Node*newNode = new Node;
     newNode->item = num;
     if (length==0)
     {
         first = last = newNode;
         newNode->next = NULL;
     }   
     else {
         newNode->next=first;
         first = newNode;
     }
     length++;
    }

    void addLast(int num) //To add an item and place it at the end of the list
    {
        
        Node *newNode = new Node;
        newNode->item = num;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else{
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        length++;
    }

    void addAtpos(int pos, int num) //To add an item from any position in the list
    {

        if(pos < 0 || pos > length)
        cout<<"Out of Range\n";
        else
        {
            Node*newNode = new Node;
            newNode->item = num;
            if(pos==0)
                addFirst(num);
            else if(pos == length)
                addLast(num);
            else
            {
                Node * cur = first;
                for (int i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }
                newNode->next = cur->next;
                cur->next = newNode;
                length++;
            }
        }
         
    }

    void remove(int num) //Function to remove the required item from the list
    {
        if (isEmpty()) //Verify that the list is not empty
        {
            cout << "Empty List can't Remove\n";
            return;
        }
        Node *curr, *prev;
        if (first->item == num)
        {
            curr = first;
            first = first->next;
            delete curr;
            length--;
            if (length==0)
            {
                last = NULL;
            }
        }
        else
        {
                curr = first->next;
                prev = first;
            
            
            while (curr != NULL)
            {
               if (curr->item == num)
               break;
               prev = curr;
               curr = curr->next;
            }

            if (curr == NULL)
               cout <<"NOT FOUND!\n";
            
            else
            {
                prev->next = curr->next;
                if (last == curr)
                {
                    last = prev;
                    delete curr;
                    length--;
                }
                
            }
        }
        
    }

    void print() //A function that prints list items
    {
        cout << "THE LINKED LIST\n";
        Node*cur = first;
        cout << "[ ";
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur=cur->next;
        }
        cout << "]\n";
    }
};

/*STACK*/
class Stack
{
    private:
        int stackArray [maxSize];
        int Top;

    public:
       Stack():Top (-1){}

       void push(int element) //Function of adding elements to Stack
       {
           if (Top >= maxSize - 1)
           {
               cout << "Stack is Full! \n";
           }
           else
           {
               Top++;
               stackArray[Top] = element;
           }
        }

        bool isEmpty()
        {
            return Top < 0;
        }

        void pop() //Function of delete elements from Stack
        {
            if (isEmpty())
            {
                cout << "Stack is Empty !\n";
            }
            else
            {
                Top--;
            }
        }

        void print() //A function that prints Stack items
        {
            cout<<"STACK"<<endl;
            cout <<"---\n";
            for (int i = Top; i >= 0; i--)
            {
                cout << stackArray[i] << endl;
            }
            cout << "---";
        }
    
};
/*QUEUE*/
class Queue
{
    int front, end, length, queueArray[maxSize];
public:
    Queue(){
        front = 0;
        end = maxSize - 1;
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == maxSize;
    }

    void addQ(int num) //Function of adding elements to Queue
    {
        if (isFull()) //Check if the Queue isfull
        {
            cout << "Queue is Full you can't ADD\n";
        }
        else
        {
            end = (end + 1) % maxSize;
            queueArray[end] = num;
            length++;
        }
    }

    void deleteQ() //Function of delete elements from Queue
    {
        if (isEmpty()) //Check if the Queue is empty
        {
            cout << "Queue is Empty you can't DELETE\n";
        }
        else
        {
            front = (front+1) % maxSize ;
            length--;
        }  
    }

    void printQ() //A function that prints Queue items
    {
        cout << "[ ";
        for (int i = front; i != end+1; i = (i+1) % maxSize)
        {
            cout << queueArray[i] << " ";
        }
        cout << "]";
    }   
};

/*MAIN FUNCTION*/
int main()
{
Linked_List l; Stack s; Queue q; //objects
int choice, pos, element, Choice;
string Exit;
cout << "Choose the number of What do you want:\n  1-Linked List:\n  2-STACK:\n  3-QUEUE: \n ";
cin >> choice;// Choosing one of the choices to work with it

    switch (choice)
{
case 1:
    cout << "First Add 3 Elements to Linked List: "<<endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number "<<i<<": ";
        cin >> element;
        l.addLast(element);
    }
    l.print();

    do
    {
        cout << "\nnow To add more Element:\npress 1 and the Element will be the FIRST one \n";
        cout << "Enter 2 and the Element will be the LAST one \n";
        cout << "Enter 3 to ADD AT POSITION --Enter the POSITION and then Enter the ELEMENT-- \n";
        cout << "Enter 4 To REMOVE Element : ";
        try
        {
            cin >> Choice;
            if (Choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                l.addFirst(element);
            }
            else if (Choice == 2)
            {
                cout << "The Element = ";
                cin >> element;
                l.addLast(element);
            }
            else if (Choice == 3)
            {
                cout  << "The Position = ";
                cin >> pos;
                cout << "The Element = ";
                cin >> element;
                l.addAtpos(pos,element);
            }
            else if (Choice == 4)
            {
                cout << "The Element = ";
                cin >> element;
                l.remove(element);
                cout << element << " Have been Deleted!\n";
            }
            
            
            else
            {
                throw "Something went wrong!"; //Excileption
            }
                
        }
        catch(char const*e)
        {
            cerr <<"ERROR : "<< e << '\n';
        }
    
        l.print();
        cout<< "\nDo you want to Exit? | type (yes) to exit or (no) to continue : ";
        cin >> Exit;
    } while (Exit != "yes");

break;

case 2:
    cout << "First Add 3 Elements to Stack: " << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number " << i << ": ";
        cin >> element;
        s.push(element);
    }
    s.print();

    do
    {
        cout << "\nEnter 1 To Push Element on TOP:\n Enter 2 To Pop Element from TOP: ";
        try
        {
            cin >> Choice;
            if (Choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                s.push(element);
            }
            else if (Choice == 2)
            {
                s.pop();
            }
            else
            {
                throw "Out of Range!\n"; //Excileption
            }            
        }
        catch(char const*e)
        {
            cerr << "\nERROR : " << e << '\n';
        }
        s.print();
    cout << "\nDo you want to Exit? | type (yes) to exit or (no) to continue : ";
    cin >> Exit;
    } while (Exit != "yes");

break;

case 3:
    cout << "First Add 3 Elements to Queue: " << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number " << i << ": ";
        cin >> element;
       q.addQ(element);
    }
    q.printQ();
    
    do
    {
        cout << "\nEnter 1 To Add Element to Queue:\n Enter 2 To delete Element from Queue: ";
        try
        {
            cin >> Choice;
            if (Choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                q.addQ(element);
            }
            else if (Choice == 2)
            {
                q.deleteQ();
            }
            else
            {
                throw "Out of Range!\n"; //Excileption
            }
        }
        catch (char const *e)
            {
                cerr << "\nERROR : " << e << '\n';
            }
           q.printQ();

    cout << "\nDo you want to Exit? | type (yes) to exit or (no) to continue : ";
    cin >> Exit;
    } while (Exit != "yes");

break;

default:
    cout << "Something went wrong!";
    break;
}

return 0;
}
