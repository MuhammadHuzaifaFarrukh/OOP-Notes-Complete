#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T val;
    Node<T>* next;
    Node(T v = 0, Node<T>* n = nullptr) : val(v), next(n) {}
};
template <typename T>
class List
{
    Node<T>* head;
    Node <T>* tail;
public:
    int size = 0;
    //You can also keep the count of size if you want
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void push_front_list(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
        return;
    }
    //Can also use one line code : head = new Node(val , head) instead of all the code for push_front

    void push_back_list(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next= newNode;
            tail = newNode;
        }
        size++;
        return ;
    }
    //If our Linked List class doesn't have a tail pointer then we need to iterate through the list for adding the new element at right side

    void pop_front_list()
    {
        if(head == nullptr)
        {
            cout<<"List is empty "<<endl;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            temp->next = nullptr;   //Disconnect temp from the list (Optional here)
            size--;
            delete temp;    //Now Deallocate the Node from the list
        }
        return ;
    }
    /*
    We can also do for else part :
    Node<T>* temp = head->next;
    head->next = nullptr;   (Optional here)
    delete head;
    head = temp;
    */

    void pop_back_list()
    {
        if(head == nullptr)
        {
            cout<<"List is empty "<<endl;
        }
        else
        {
            Node<T>* temp = head;
            while(temp->next != tail) //Can also use temp->next->next != nullptr
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;    //Delete the last node
            tail = temp;    //Update tail to previous node
            size--;
        }
        return ;
    }
    void insert_node(T val, int ind)
    {
        if(ind<0 || ind>size)
        {
            cout<<"Invalid Index "<<endl;
            return;
        }
        else if(ind == 0)   //Push_front() Case
        {
            push_front_list(val);
            return ;
        } //If you want then you can also write push_back case but its not needed here
        else if(ind == size)
        {
            push_back_list(val);
            return ;
        }
        else
        {
            Node<T>* temp = head;
            for(int i = 0 ; i<ind-1 && temp!= nullptr ; i++)
            {
                temp = temp->next;
            }

            // Check if we reached end of list prematurely
            if (temp == nullptr)
            {
                push_back_list(val);
                return;
            }
            //We could also use ind == size instead of temp==nullptr to check for the last position and do push back
            Node<T>* newNode = new Node<T>(val);
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
            return ;
        }
    }
    void remove_node_val(T val)
    {
        // Handle empty list
        if (head == nullptr)
        {
            return;
        }

        // Remove from beginning if value matched
        while (head != nullptr && head->val == val)
        {
            pop_front_list();
        }

        // Remove from middle/end
        Node<T>* temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->next->val == val)
            {
                Node<T>* newNode = temp->next;
                temp->next = newNode->next;

                // Update tail if deleting last node
                if (newNode == tail)
                {
                    tail = temp;
                }

                delete newNode;
                size--;
            }
            else
            {
                temp = temp->next;
            }
        }
        return ;
    }
    void remove_node(int ind)
    {
        if(ind < 0 || ind >= size)
        {
            cout<<"Invalid Size "<<endl;
            return ;
        }
        else if(ind == 0 )
        {
            pop_front_list();
        }
        else if(ind == size-1)
        {
            pop_back_list();
        }
        else
        {
            // Find the node BEFORE the one to delete
            Node<T>* temp = head;
            for(int i = 0; i < ind - 1; i++)
            {
                temp = temp->next;
            }
            // Node to delete is temp->next
            Node<T>* newNode = temp->next;
            temp->next = newNode->next;  // Bypass the node to delete (Changing the connection)

            newNode->next = nullptr;     // Optional: Disconnect before delete
            delete newNode;              // Delete the node
            size--;
        }
    }
    int linear_search(T target) //Returns Index
    {
        Node<T>* temp = head;
        int ind = 0;
        while(temp != nullptr)
        {
            if(temp->val == target)
            {
                return ind;
            }
            temp = temp->next;
            ind++;
        }
        return -1;
    }

    T at_list(int ind)
    {
        if(ind<0 || ind>=size)
        {
            cout<<"Invalid Position "<<endl;
            return -1;
        }
        Node<T> *temp = head;
        for(int i = 0 ; i<ind && temp != nullptr ; i++)
        {
            temp = temp->next;
        }
        return (temp->val);
    }

    //Using Selection Sort on List :
    void selectionSort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;  // Empty list or single node already sorted
        }

        Node<T>* current = head;

        while (current != nullptr)
        {
            // Find the minimum node in the remaining list
            Node<T>* minNode = current;
            Node<T>* temp = current->next;

            while (temp != nullptr)
            {
                if (temp->val < minNode->val)
                {
                    minNode = temp;
                }
                temp = temp->next;
            }

            // Swap values between current and minNode
            if (minNode != current)
            {
                T swapVal = current->val;
                current->val = minNode->val;
                minNode->val = swapVal;
            }

            // Move to next node
            current = current->next;
        }
    }

    void print_list()
    {
        Node<T>* temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void clear_list()
    {

        Node<T>* temp = head;
        //You can also call pop_front() or pop_back() in a while loop
//        while(temp != nullptr)
//        {
//            pop_front();
//        }
        while (temp != nullptr)
        {
            Node<T>* nextNode = temp->next;  // Save next pointer first
            temp->next= nullptr;          // Optional (Remove the connection)
            delete temp;                  // Delete current node
            temp = nextNode;              // Move to next node
        }
        head = tail = nullptr;  //Optional (Already Dangling Pointers)
        size = 0;
    }
    ~List()
    {
        clear_list();
    }
    //Make your own copy constructor and assignment operator for deep copy

    // Copy Constructor :
    List(const List<T>& other)
    {
        head = nullptr;
        if (other.head!= nullptr)
        {
            //Copy the Size Also :
            size = other.size;
            // Copy first node
            head = new Node<T>(other.head->val);
            Node<T>* current = head;
            Node<T>* otherCurrent = other.head->next;

            // Copy remaining nodes
            while (otherCurrent != nullptr)
            {
                current->next = new Node<T>(otherCurrent->val);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    // Copy Assignment Operator
    List<T>& operator=(const List<T>& other)
    {
        if (this != &other)    // Protect against self-assignment
        {
            // Clear current list
            clear_list();

            //Copy the Size Also :
            size = other.size;

            // Copy from other list (same logic as copy constructor)
            if (other.head!= nullptr)
            {
                head = new Node<T>(other.head->val);
                Node<T>* current = head;
                Node<T>* otherCurrent = other.head->next;

                while (otherCurrent != nullptr)
                {
                    current->next = new Node<T>(otherCurrent->val);
                    current = current->next;
                    otherCurrent = otherCurrent->next;
                }
            }
        }
        return *this;
    }

    friend ostream& operator << (ostream &out, const List<T>&list)
    {
        for (Node<T>*temp = list.head; temp != nullptr ; temp = temp -> next)
            out << temp -> val << ' ';
        out << '\n';
        return out;
    }
};
int main()
{
    List<string> l1;

    l1.push_back_list("banana");
    l1.push_back_list("apple");
    l1.push_back_list("cherry");
    l1.push_back_list("Avocado");
    l1.insert_node("Zebra",4);
    List<string> l2;
    l2 = l1;
//    for(string c :  l1)
//    {
//        cout<<c<<" ";
//    }
    cout<<l1<<endl;

    l2.print_list();
    l2.selectionSort();
    l2.print_list();
    cout<<"\n"<<l2.size;
    return 0;
}
