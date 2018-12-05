//
//  main.cpp
//  FinalProject
//
//  Created by Mason Fisher on 11/13/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//


#include "Truck.h"

int main() {
    Truck truckObj;
    truckObj.start();
    while(!truckObj.isDoneWaiting()){
		truckObj.getCommand();
		truckObj.setCommand();
		truckObj.setAction();
		truckObj.print();
    }
    return 0;
}
