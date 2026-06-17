#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_ask.H>
// #include <FL/Fl_Status_Bar.H>

// Forward declarations
void on_hello(Fl_Widget*, void*);
void on_exit(Fl_Widget*, void*);
void on_about(Fl_Widget*, void*);

Fl_Window* win;

void on_hello(Fl_Widget*, void*) {
	fl_message("Hello world from FLTK!");
}

void on_exit(Fl_Widget*, void*) {
	win->hide();
}

void on_about(Fl_Widget*, void*) {
	fl_message("This is an FLTK Hello World example");
}

int main(int argc, char** argv) {
	Fl::args(argc, argv);
	// Fl::scheme("gleam");
	win = new Fl_Window(400, 300, "Hello World");

	Fl_Menu_Bar* menu = new Fl_Menu_Bar(0, 0, 400, 25);
	menu->add("&File/&Hello...\t^h", 0, on_hello);
	menu->add("&File/&Exit",         0, on_exit);
	menu->add("&Help/&About",        0, on_about);

	// Fl_Box* main_label = new Fl_Box(30, 30, 60, 60, "This is a test text label!");

	win->end();
	win->show();

	return Fl::run();
}
