#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/fl_ask.H>

#include <string>
#include <cmath>

/// GLOBAL STATE

float number1 = 0;
float number2 = 0;
char current_operator = '\0';
std::string current_input = "";
Fl_Text_Buffer *main_buffer;
Fl_Text_Display *main_display;

void on_hello(Fl_Widget*, void*);
void on_exit(Fl_Widget*, void*);
void on_about(Fl_Widget*, void*);

Fl_Window* win;

// Display helper and calculator logic

void update_display(const std::string& text) {
	main_buffer->text(text.c_str());
}

float calculate(float num1, float num2, char op) {
	switch (op) {
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/':
			  if (num2 == 0) {
				  fl_alert("Cannot divide by zero!");
				  return 0;
			  }
			  return num1 / num2;
		default: return num2;
	}
}

// Button events

void on_number_button(Fl_Widget*, void* data) {
	const char* num = (const char* data);
	current_input += num;
	update_display(current_input);
}

void on_operator_button(Fl_Widget*, void* data) {
	char op = *(char*)data;

	if (current_operator != '\0' && !current_input.empty()) {
		number2 = std::stof(current_input);
		float result = calculate(number1, number2, current_operator);
		number1 = result;
		current_input = std::to_string(result);

		current_input.erase(current_input.find_last_not_of('0') + 1, std::string::npos);
	}
}

// Menu events

void on_exit(Fl_Widget*, void*) {
	win->hide();
}

void on_about(Fl_Widget*, void*) {
	fl_message(
			"= Calculator version 0.1.0 =\n"
			"by Dawid Gorski 2026.");
}

void on_usage(Fl_Widget*, void*) {
	fl_message(
			"= Navigation in menu bar =\n"
			"Press Alt + Letter, where Letter is marked letter on\n"
			"menu bar options. While in one of the menus, the same\n"
			"keybinding applies. Press arrows to navigate between options.");
}

int main(int argc, char** argv) {
	Fl::scheme("gleam");
	Fl::args(argc, argv);
	win = new Fl_Window(400, 310, "Calculator");

	Fl_Menu_Bar* menu = new Fl_Menu_Bar(0, 0, 400, 25);
	menu->add("&File/&Exit",         0, on_exit);
	menu->add("&Help/&About",        0, on_about);
	menu->add("&Help/&Usage",        0, on_usage);

	/// CALCULATOR BUTTONS
	Fl_Button *calc_button1 = new Fl_Button(10, 150, 60, 30, "1");
	Fl_Button *calc_button2 = new Fl_Button(80, 150, 60, 30, "2");
	Fl_Button *calc_button3 = new Fl_Button(150, 150, 60, 30, "3");
	Fl_Button *calc_button4 = new Fl_Button(10, 190, 60, 30, "4");
	Fl_Button *calc_button5 = new Fl_Button(80, 190, 60, 30, "5");
	Fl_Button *calc_button6 = new Fl_Button(150, 190, 60, 30, "6");
	Fl_Button *calc_button7 = new Fl_Button(10, 230, 60, 30, "7");
	Fl_Button *calc_button8 = new Fl_Button(80, 230, 60, 30, "8");
	Fl_Button *calc_button9 = new Fl_Button(150, 230, 60, 30, "9");
	Fl_Button *calc_button0 = new Fl_Button(80, 270, 60, 30, "0");

	Fl_Button *calc_button_clear = new Fl_Button(10, 110, 60, 30, "C");

	Fl_Button *calc_button_add = new Fl_Button(220, 110, 60, 30, "+");
	Fl_Button *calc_button_subtract = new Fl_Button(220, 150, 60, 30, "-");
	Fl_Button *calc_button_multiplicate = new Fl_Button(220, 190, 60, 30, "*");
	Fl_Button *calc_button_divide = new Fl_Button(220, 230, 60, 30, "/");

	win->end();
	win->show();

	return Fl::run();
}
