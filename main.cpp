//
//  main.cpp
//  Straights
//
//  Created by Peter Li on 2015-06-17.
//  Copyright (c) 2015 Peter Li. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "model/Model.h"
#include "view/View.h"
#include "controller/Controller.h"


int main(int argc, const char * argv[]) {
    Model model;                                            //create model
    
    if (argc == 2){
        Controller controller(&model, atoi(argv[1]));       //create controller
        View view(&controller);                             //create view - handles input
    }else{
        Controller controller(&model);                      //create controller
        View view(&controller);                             //create view - handles input
    }

    return 0;
}
