//

#ifndef arrayType_h
#define arrayType_h

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator=
    (const arrayListType<elemType>&);
    //Overloads the assignment operator
    bool isEmpty() const;
    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty;
    //    otherwise, returns false.
    bool isFull() const;
    //Function to determine whether the list is full.
    //Postcondition: Returns true if the list is full;
    //    otherwise, returns false.
    int listSize() const;
    //Function to determine the number of elements in the list
    //Postcondition: Returns the value of length.
    int maxListSize() const;
    //Function to determine the size of the list.
    //Postcondition: Returns the value of maxSize.
    void print() const;
    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the
    //   standard output device.
    bool isItemAtEqual(int location, const elemType& item) const;
    //Function to determine whether the item is the same
    //as the item in the list at the position specified by
    //Postcondition: Returns true if the list[location]
    //    is the same as the item; otherwise,
    //               returns false.
    void insertAt(int location, const elemType& insertItem);
    //Function to insert an item in the list at the
    //position specified by location. The item to be inserted
    //is passed as a parameter to the function.
    //Postcondition: Starting at location, the elements of the
    //    list are shifted down, list[location] = insertItem;,
    //    and length++;. If the list is full or location is
    //    out of range, an appropriate message is displayed.
    void insertEnd(const elemType& insertItem);
    //Function to insert an item at the end of the list.
    //The parameter insertItem specifies the item to be inserted.
    //Postcondition: list[length] = insertItem; and length++;
    //    If the list is full, an appropriate message is
    //    displayed.
    void removeAt(int location);
    //Function to remove the item from the list at the
    //position specified by location
    //Postcondition: The list element at list[location] is removed
    //    and length is decremented by 1. If location is out of
    //    range,an appropriate message is displayed.
    void retrieveAt(int location, elemType& retItem) const;
    //Function to retrieve the element from the list at the
    //position specified by location.
    //Postcondition: retItem = list[location]
    //    If location is out of range, an appropriate message is
    //    displayed.
    void replaceAt(int location, const elemType& repItem);
    //Function to replace the elements in the list at the
    //position specified by location. The item to be replaced
    //is specified by the parameter repItem.
    //Postcondition: list[location] = repItem
    //    If location is out of range, an appropriate message is
    //    displayed.
    void clearList();
    //Function to remove all the elements from the list.
    //After this operation, the size of the list is zero.
    //Postcondition: length = 0;
    int seqSearch(const elemType& item) const;
    //Function to search the list for a given item.
    //Postcondition: If the item is found, returns the location
    //    in the array where the item is found; otherwise,
    //    returns -1.
    void insert(const elemType& insertItem);
    //Function to insert the item specified by the parameter
    //insertItem at the end of the list. However, first the
    //list is searched to see whether the item to be inserted
    //is already in the list.
    //Postcondition: list[length] = insertItem and length++
    //     If the item is already in the list or the list
    //     is full, an appropriate message is displayed.
    void remove(const elemType& removeItem);
    //Function to remove an item from the list. The parameter
    //removeItem specifies the item to be removed.
    //Postcondition: If removeItem is found in the list,
    //      it is removed from the list and length is
    //      decremented by one.
    
    void removeAll(const elemType& removeTime);
    //Function to remove all instances of an item from the list. The
    //parameter removeItem specifies the item to be removed.
    //Postcondition: If removeItem is found in the list,
    //       all instances are removed from the list and
    //       length is decremented by the # of instances removed.
    
    arrayListType(int size = 100);
    //constructor
    //Creates an array of the size specified by the
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0,
    //    and maxSize = size
    
    arrayListType(const arrayListType<elemType>& otherList);
    //copy constructor
    
    elemType min() const;
    //Function to return the smallest value within the array.
    //This function simply steps through the array, holding
    //the smallest value in a variable. The current smallest value is
    //compared to all other values that have not been checked yet.
    //Values are compared based on their ASCII equivalents.
    //EX: "he" is smaller than "hi".
    //Postcondition: The function returns the smallest value within
    //    the array.
    elemType max() const;
    //Function to return the largest value within the array.
    //This function simply steps through the array, holding
    //the largest value in a variable. The current largest value is
    //compared to all other values that have not been checked yet.
    //Values are compared based on their ASCII equivalents.
    //EX: "hi" is larger than "he".
    //Postcondition: The function returns the largest value within
    //    the array.
    
    /**
     operator == (arrayListType<elemType)
     For use in comparisons in other classes. returns true if every
     element in the array is equal to every element in the array passed.
     Otherwise returns false.
     */
    bool operator == (arrayListType<elemType> otherList){
        if(length == otherList.length){
            for(int i = 0; i<length; i++){
                if(list[i]!=otherList.list[i])
                    return false;
            }
            return true;
        }else
            return false;
    };
    /**
     elemType get(int)
     Returns the element of the list at index int.
     */
    elemType get(int num){if(num>=length&&num<0){cout << num << " is not a valid index.\n";return NULL;} return list[num];};
    ~arrayListType();
    //destructor
    //Deallocates the memory occupied by the array.
    
protected:
    elemType *list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list
};

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item) const
{
    return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
        << "is out of range" << endl;
    else
        if (length >= maxSize)  //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];   //move the elements down
            
            list[location] = insertItem;  //insert the item at the
            //specified position
            
            length++;     //increment the length
        }
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    
    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem;   //insert the item at the end
        length++;   //increment the length
    }
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];
        
        length--;
    }
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt
(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
        << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt


template <class elemType>
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
        << "out of range." << endl;
    else
        list[location] = repItem;
    
} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;
    
    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }
    
    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    
    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and
    //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);
        
        if (loc == -1)    //the item to be inserted
            //does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
            << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
        
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
            << endl;
    }
} //end remove

template <class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem)
{
    do
    {
        remove(removeItem);
        
    }while(seqSearch(removeItem) != -1);
}   // end removeAll

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
        << "an array of size 100. " << endl;
        
        maxSize = 100;
    }
    else
        maxSize = size;
    
    length = 0;
    
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}


template <class elemType>
arrayListType<elemType>::arrayListType
(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);         //terminate if unable to allocate
    //memory space
    
    for (int j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
} //end copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
    if (this != &otherList)   //avoid self-assignment
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        
        list = new elemType[maxSize];  //create the array
        assert(list != NULL);   //if unable to allocate memory
        //space, terminate the program
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    
    return *this;
}

template<class elemType>

elemType arrayListType<elemType>::min() const
{
    elemType smallest;
    string stringOne;
    string stringTwo;
    int size, maxSizeOne, maxSizeTwo;
    int pointsStringOne = 0, pointsStringTwo = 0;
    
    smallest = list[0];
    
    //Testing to see if it's a word by checking it's first letter.
    //I'm guessing strings in an array act like a 2d array, because it works as far as I can tell.
    if( int(list[0][0]) >= 65 && int(list[0][0]) <= 122 )   // If it's a letter.
    {
        smallest = list[0];
        for( int i = 1; i < length; i++ )   // for loop for whole words.
        {
            stringOne = smallest;
            stringTwo = list[i];    // smallest word (in ASCII terms) always compared with next in array.
            
            size = list[i-1].size(); // just to get a starting limit for the following for loop.
            for( int n = 0; n < size; n++ )
            {
                if(stringOne.size() >= stringTwo.size()) // The larger word is the size we're using for the loop.
                {
                    
                    size = stringOne.size();
                }
                else
                {
                    size = stringTwo.size();
                }
                
                maxSizeOne = (stringOne.size());
                maxSizeTwo = (stringTwo.size());
                
                if( n <= maxSizeOne && n <= maxSizeTwo )    //If there are still more letters to check in both words.
                {
                    
                    
                    pointsStringOne = pointsStringOne + int(stringOne[n]);  // Accumulating ASCII values for each letter of word 1.
                    
                    
                    pointsStringTwo = pointsStringTwo + int(stringTwo[n]);  // Accumulating ASCII values for each letter of word 2.
                    
                }
                else if( n <= maxSizeOne && n > maxSizeTwo )    //If word 1 still has more letters to check, but word 2 does not.
                {
                    
                    pointsStringOne = pointsStringOne + int(stringOne[n]);
                }
                else if( n <= maxSizeTwo && n > maxSizeOne )
                {
                    
                    pointsStringTwo = pointsStringTwo + int(stringTwo[n]);  //If word 2 still has more letters to check, but word 1 does not.
                }
                
            }
            if( pointsStringOne <= pointsStringTwo) // If stringOne accumulated less ASCII points than stringTwo.
            {
                smallest = stringOne;
            }
            else
            {
                smallest = stringTwo;
            }
            
            pointsStringOne = 0;    // Bring the counters back to 0.
            pointsStringTwo = 0;
        }
    }
    else    // If the data type is not string or char.
    {
        
        for( int i = 0; i < length; i++ )
        {
            if( i != 0 )
            {
                // If the value in index i is less than the
                // value in index i-1, then that value
                // becomes the new smallest value.
                if( list[i] < list[i-1] )
                {
                    smallest = list[i];
                }
            }
        }
    }
    
    return smallest; // return smallest.
    
}

template<class elemType>

elemType arrayListType<elemType>::max() const
{
    elemType largest;
    string stringOne;
    string stringTwo;
    int size, maxSizeOne, maxSizeTwo;
    int pointsStringOne = 0, pointsStringTwo = 0;
    
    largest = list[0];
    
    //Testing to see if it's a word by checking it's first letter.
    //I'm guessing strings in an array act like a 2d array, because it works as far as I can tell.
    if( int(list[0][0]) >= 65 && int(list[0][0]) <= 122 )   // If it's a letter.
    {
        largest = list[0];
        for( int i = 1; i < length; i++ )   // for loop for whole words.
        {
            stringOne = largest;
            stringTwo = list[i];    // smallest word (in ASCII terms) always compared with next in array.
            
            size = list[i-1].size(); // just to get a starting limit for the following for loop.
            for( int n = 0; n < size; n++ )
            {
                if(stringOne.size() >= stringTwo.size()) // The larger word is the size we're using for the loop.
                {
                    
                    size = stringOne.size();
                }
                else
                {
                    size = stringTwo.size();
                }
                
                maxSizeOne = (stringOne.size());
                maxSizeTwo = (stringTwo.size());
                
                if( n <= maxSizeOne && n <= maxSizeTwo )    //If there are still more letters to check in both words.
                {
                    
                    
                    pointsStringOne = pointsStringOne + int(stringOne[n]);  // Accumulating ASCII values for each letter of word 1.
                    
                    
                    pointsStringTwo = pointsStringTwo + int(stringTwo[n]);  // Accumulating ASCII values for each letter of word 2.
                    
                }
                else if( n <= maxSizeOne && n > maxSizeTwo )    //If word 1 still has more letters to check, but word 2 does not.
                {
                    
                    pointsStringOne = pointsStringOne + int(stringOne[n]);
                }
                else if( n <= maxSizeTwo && n > maxSizeOne )
                {
                    
                    pointsStringTwo = pointsStringTwo + int(stringTwo[n]);  //If word 2 still has more letters to check, but word 1 does not.
                }
                
            }
            if( pointsStringOne >= pointsStringTwo) // If stringOne accumulated less ASCII points than stringTwo.
            {
                largest = stringOne;
            }
            else
            {
                largest = stringTwo;
            }
            
            pointsStringOne = 0;    // Bring the counters back to 0.
            pointsStringTwo = 0;
        }
    }
    else    // If the data type is not string or char.
    {
        
        for( int i = 0; i < length; i++ )
        {
            if( i != 0 )
            {
                // If the value in index i is less than the
                // value in index i-1, then that value
                // becomes the new largest value.
                if( list[i] >= list[i-1] )
                {
                    largest = list[i];
                }
            }
        }
    }
    
    return largest; // return largest.
}



#endif
