#ifndef linkedListType_h
#define linkedListType_h

template <class Type>
struct nodeType{
    Type info;
    nodeType * link;
};

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement an iterator
// to a linked list.
//***********************************************************
template <class Type>
class linkedListIterator
{
public:
    linkedListIterator();
    //Default constructor
    //Postcondition: current = NULL;
    linkedListIterator(nodeType<Type> *ptr);
    //Constructor with a parameter.
    //Postcondition: current = ptr;
    Type operator*();
    //Function to overload the dereferencing operator *.
    //Postcondition: Returns the info contained in the node.
    linkedListIterator<Type> operator++();
    //Overload the preincrement operator.
    //Postcondition: The iterator is advanced to the next node.
    bool operator==(const linkedListIterator<Type>& right) const;
    //Overload the equality operator.
    //Postcondition: Returns true if this iterator is equal to
    // the iterator specified by right, otherwise it returns
    // false.
    bool operator!=(const linkedListIterator<Type>& right) const;
    //Overload the not equal to operator.
    //Postcondition: Returns true if this iterator is not equal to
    // the iterator specified by right, otherwise it returns
    // false.
private:
    nodeType<Type> *current; //pointer to point to the current
    //node in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}
template <class Type>
linkedListIterator<Type>::
linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of a linked list. This is an abstract class.
// We cannot instantiate an object of this class.
//***********************************************************
template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=
    (const linkedListType<Type>&);
    //Overload the assignment operator.
    void initializeList();
    //Initialize the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0;
    bool isEmptyList() const;
    //Function to determine whether the list is empty.
    //Postcondition: Returns true if the list is empty, otherwise
    // it returns false.
    void print() const;
    //Function to output the data contained in each node.
    //Postcondition: none
    int length() const;
    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.
    void destroyList();
    //Function to delete all the nodes from the list.
    //Postcondition: first = NULL, last = NULL, count = 0;
    Type front() const;
    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program terminates;
    // otherwise, the first element of the list is returned.
    Type back() const;
    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program
    // terminates; otherwise, the last
    // element of the list is returned.
    virtual bool search(const Type& searchItem) const = 0;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list,
    // otherwise the value false is returned.
    virtual void insertFirst(const Type& newItem) = 0;
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to
    // the last node in the list, and count is incremented by
    // 1.
    virtual void insertLast(const Type& newItem) = 0;
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the end of the list, last points to the
    // last node in the list, and count is incremented by 1.
    virtual void deleteNode(const Type& deleteItem) = 0;
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is
    // deleted from the list. first points to the first node,
    // last points to the last node of the updated list, and
    // count is decremented by 1.
    linkedListIterator<Type> begin();
    //Function to return an iterator at the beginning of the
    //linked list.
    //Postcondition: Returns an iterator such that current is set
    // to first.
    linkedListIterator<Type> end();
    //Function to return an iterator one element past the
    //last element of the linked list.
    //Postcondition: Returns an iterator such that current is set
    // to NULL.
    linkedListType();
    //default constructor
    //Initializes the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0;
    linkedListType(const linkedListType<Type>& otherList);
    //copy constructor
    ~linkedListType();
    //destructor
    //Deletes all the nodes from the list.
    //Postcondition: The list object is destroyed.
protected:
    int count; //variable to store the number of list elements
    //
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last; //pointer to the last node of the list
private:
    void copyList(const linkedListType<Type>& otherList);
    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and assigned
    // to this list.
};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}
template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}
template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp; //pointer to deallocate the memory
    //occupied by the node
    while (first != NULL) //while there are nodes in the list
    {
        temp = first; //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp; //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
    //been set to NULL by the while loop
    count = 0;
}
template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}
template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; //pointer to traverse the list
    current = first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print
template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);
    return first->info; //return the info of the first node
}//end front
template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info; //return the info of the last node
}//end back
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}
template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list
    if (first != NULL) //if the list is nonempty, make it empty
        destroyList();
    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
        //list to be copied
        count = otherList.count;
        //copy the first node
        first = new nodeType<Type>; //create the node
        first->info = current->info; //copy the info
        first->link = NULL; //set the link field of the node to NULL
        last = first; //make last point to the first node
        current = current->link; //make current point to the next
        // node
        //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>; //create a node
            newNode->info = current->info; //copy the info
            newNode->link = NULL; //set the link of newNode to NULL
            last->link = newNode; //attach newNode after last
            last = newNode; //make last point to the actual last
            //node
            current = current->link; //make current point to the
            //next node
        }//end while
    }//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType
(const linkedListType<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    return *this;
}

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************
template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list,
    // otherwise the value false is returned.
    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to
    // the last node, and count is incremented by 1.
    //
    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the end of the list, last points to the
    // last node, and count is incremented by 1.
    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem
    // is deleted from the list. first points to the first
    // node, last points to the last node of the updated
    // list, and count is decremented by 1.
};

template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    current = linkedListType<Type>::first; //set current to point to the first
    //node in the list
    while (current != NULL && !found) //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
    //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
    newNode->link = linkedListType<Type>::first; //insert newNode before first
    linkedListType<Type>::first = newNode; //make first point to the actual first node
    linkedListType<Type>::count++; //increment count
    if (linkedListType<Type>::last == NULL) //if the list was empty, newNode is also
        //the last node in the list
        linkedListType<Type>::last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
    newNode->link = NULL; //set the link field of newNode to NULL
    if (linkedListType<Type>::first == NULL) //if the list is empty, newNode is
        //both the first and last node
    {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++; //increment count
    }
    else //the list is not empty, insert newNode after last
    {
        linkedListType<Type>::last->link = newNode; //insert newNode after last
        linkedListType<Type>::last = newNode; //make last point to the actual
        //last node in the list
        linkedListType<Type>::count++; //increment count
    }
}//end insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (linkedListType<Type>::first == NULL) //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
        << endl;
    else
    {
        if (linkedListType<Type>::first->info == deleteItem) //Case 2
        {
            current = linkedListType<Type>::first;
            linkedListType<Type>::first = linkedListType<Type>::first->link;
            linkedListType<Type>::count--;
            if (linkedListType<Type>::first == NULL) //the list has only one node
                linkedListType<Type>::last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = linkedListType<Type>::first; //set trailCurrent to point
            //to the first node
            current = linkedListType<Type>::first->link; //set current to point to
            //the second node
            while (current != NULL && !found)
            {
                if (!(current->info == deleteItem))
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while
            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                linkedListType<Type>::count--;
                if (linkedListType<Type>::last == current) //node to be deleted was the
                    //last node
                    linkedListType<Type>::last = trailCurrent; //update the value of last
                delete current; //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

#endif
