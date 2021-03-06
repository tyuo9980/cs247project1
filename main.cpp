#include <gtkmm/main.h>
#include <stdlib.h>
#include "model/Model.h"
#include "view/View.h"
#include "controller/Controller.h"

int main(int argc, char * argv[]) {
    Gtk::Main kit(argc, argv);

    Model model;                                        //create model
    Controller controller(&model);                      //create controller
    View view(&controller, &model);                     //create view
    Gtk::Main::run(view);

    return 0;
}
