//
//  main.cpp
//  Straights
//
//  Created by Peter Li on 2015-06-17.
//  Copyright (c) 2015 Peter Li. All rights reserved.
//

#include <iostream>
#include "model/Model.h"
#include "view/View.h"
#include "controller/Controller.h"

int main(int argc, const char * argv[]) {
    Model model;
    Controller controller( &model );
    View view( &controller, &model );
    
    return 0;
}
