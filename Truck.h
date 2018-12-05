//
//  Header.h
//  FinalProject
//
//  Created by Mason Fisher on 11/13/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#ifndef Truck_h
#define Truck_h

#include "arrayListType.h"
#include "linkedListType.h"
#include "Validation.h"
#include "myQueue.h"
#include "stackType.h"
#include <ctime>



class Truck{
private:
    unorderedLinkedList<arrayListType<string>> list;
    queueType<char> commands;
    int stackSize = 3;
    myStack<char> responses;
    Validation check;
    bool eyes;
    char command;
    string speech;
    string action;
    
    
public:
    /**
     Truck()
     Constructor for truck. Loads files into truck member list and assigns each
     member of list a value 0-2 to corrispond with the file.
     */
    Truck(){
        arrayListType<string> temp;
        string fileNames[] = {"greetings.txt","buttonPress.txt","push.txt","tickle.txt","wait.txt"};
        string str, into;
        for(int i = 0; i < 5; i++){
            str = check.get_s(fileNames[i]);
            temp.insert(to_string(i));
            istringstream ss(str);
            while(getline(ss, into, ';'))
                temp.insert(into);
            list.insertLast(temp);
        }
        srand(time(NULL));
        myStack<char> stak(3);
        responses.copyStack(stak);
    };
    /**
     Destructor for truck.
     */
    ~Truck(){};
    /**
     * print()
     outputs the member values of the Truck object
     */
    void print();
    /**
     start()
     Begins the simulation and outputs the introduction.
     */
    void start();
    /**
     string getGreet()
     Returns a value from the list member corrisponding to the greetings file at random.
     */
    string getGreet();
    /**
     string getPress()
     Returns a value from the list member corrisponding to the buttonPress file at random.
     */
    string getPress();
    /**
     string getPush()
     Returns a value from the list member corrisponding to the push file at random.
     */
    string getPush();
    /**
     string getTickle()
     Returns a value from the list member corrisponding to the tickle file at random.
     */
    string getTickle();
    /**
     string getWait()
      Returns a value from the list member corrisponding to the wait file at random.
     */
    string getWait();
    /**
     getCommand()
     Gets one of the 4 commands and loads it into the commands member of Truck.
     */
    void getCommand();
    /**
     setCommand()
     Uses the contents of commands to set the members of Truck.
     */
    void setCommand();
    /**
     setAction()
     Uses the value held in command to set an action for that command. 
     */
    void setAction();
	/**
	 * isDoneWaiting()
	 * if responses stack is full returns true, otherwise returns true.
	 * */
	 bool isDoneWaiting(){return responses.isFullStack();};
	
};

void Truck :: print(){
	cout << action << endl;
	if(eyes)
		cout << "Chuck looks around.\n"; 
	else
		cout << "Chuck does not look around.\n";
	cout << "Chuck says: " << speech << endl;
}

void Truck :: setAction(){
	switch(toupper(command)){
		case 'B' : //button press
			action = "Chuck drives forward";
			eyes = false;
			speech = getPress();
			responses.initializeStack();
			break;
		case 'P' : //push Chuck
			action = "Chuck rushes forward";
			eyes = false;
			speech = getPush();
			responses.initializeStack();
			break;
		case 'T' : //tickle Chuck
			action = "Chuck laughes";
			eyes = true;
			speech = getTickle();
			responses.initializeStack();
			break;
		case 'N' : //do nothing
			action = "Chuck wonders where you went";
			eyes = true;
			speech = getWait();
			responses.push('w');
			break;
    }
            
}

void Truck :: setCommand(){
    command = commands.front();
    commands.deleteQueue();
    
}

void Truck :: getCommand(){
    string input;
    do{
        check.output("What would you like to do?");
        cin >> input;
        for(int i = 0; i < input.size(); i++){
            switch(toupper(input[i])){
                case 'B' :
                    commands.insertQueue('B');
                    break;
                case 'P' :
                    commands.insertQueue('P');
                    break;
                case 'T' :
                    commands.insertQueue('T');
                    break;
                case 'N' :
                    commands.insertQueue('N');
                    break;
                
            }
        }
    }while(commands.isEmptyQueue());
}

void Truck :: start(){
    fstream input;
    check.file(&input,"greeting.txt");
    cout << getGreet() << endl;
    cout << input.rdbuf();
    cout << endl;
    input.close();
}

string Truck :: getGreet(){
    linkedListIterator<arrayListType<string>> listIter;
    listIter = list.begin();
    while((*listIter).get(0)!= "0")
        ++listIter;
    int num = rand() % ((*listIter).listSize()-1);
    
    return (*listIter).get(num+1);
    
}

string Truck :: getPress(){
    linkedListIterator<arrayListType<string>> listIter;
    listIter = list.begin();
    while((*listIter).get(0)!= "1")
        ++listIter;
    int num = rand() % ((*listIter).listSize()-1);
    return (*listIter).get(num+1);
    
}

string Truck :: getPush(){
    linkedListIterator<arrayListType<string>> listIter;
    listIter = list.begin();
    while((*listIter).get(0)!= "2")
        ++listIter;
    int num = rand() % ((*listIter).listSize()-1);
    return (*listIter).get(num+1);
    
}

string Truck :: getTickle(){
    linkedListIterator<arrayListType<string>> listIter;
    listIter = list.begin();
    while((*listIter).get(0)!= "3")
        ++listIter;
    int num = rand() % ((*listIter).listSize()-1);
    return (*listIter).get(num+1);
    
}

string Truck :: getWait(){
    linkedListIterator<arrayListType<string>> listIter;
    listIter = list.begin();
    while((*listIter).get(0)!= "4")
        ++listIter;
    int num = rand() % ((*listIter).listSize()-1);
    return (*listIter).get(num+1);
    
}
#endif /* Header_h */
