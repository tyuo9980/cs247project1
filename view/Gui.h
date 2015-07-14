#ifndef GUI_H
#define GUI_H

#include <gdkmm/pixbuf.h>
#include <vector>
#include "../model/Card.h"

class Gui {
public:
    Gui();
    virtual ~Gui();
    Glib::RefPtr<Gdk::Pixbuf> image(Rank f, Suit s);    // Returns the image for the specified card.
    Glib::RefPtr<Gdk::Pixbuf> null();                   // Returns the image to use for the placeholder.

private:
    std::vector< Glib::RefPtr< Gdk::Pixbuf > > deck;    // Contains the pixel buffer images.
};

#endif