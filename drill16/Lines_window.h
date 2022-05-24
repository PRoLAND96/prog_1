#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

	bool wait_for_button();

private:
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	
	Menu color_menu;
	Button menu_button;
	
	Menu style_menu;
	Button smenu_button;
	
	void change(Color c) { lines.set_color(c); redraw(); }
	void change_style(Line_style ls) { lines.set_style(ls); hide_smenu(); redraw(); }
	
	void hide_menu() { color_menu.hide(); menu_button.show(); }
	void hide_smenu() { style_menu.hide(); smenu_button.show(); }
	
	void red_pressed() { change(Color::red); hide_menu(); } 
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void smenu_pressed() { smenu_button.hide(); style_menu.show(); }
	void next();
	void quit();
	
	static void cb_red(Address, Address addr) { reference_to<Lines_window>(addr).red_pressed(); }
	static void cb_blue(Address, Address addr) { reference_to<Lines_window>(addr).blue_pressed(); }
	static void cb_black(Address, Address addr) { reference_to<Lines_window>(addr).black_pressed(); }
	static void cb_menu(Address, Address addr) { reference_to<Lines_window>(addr).menu_pressed(); }
	static void cb_style_menu(Address, Address addr) { reference_to<Lines_window>(addr).smenu_pressed(); }	
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);	

};
