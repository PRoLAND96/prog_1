#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    color_menu{Point{x_max()-150,40},150,40,Menu::vertical,"color"},
    menu_button{Point{x_max()-150,40},150,40,"color menu",cb_menu},
    style_menu{Point{x_max()-150,160},150,40,Menu::vertical,"line style"},
    smenu_button{Point{x_max()-150,160},150,40,"style menu", cb_style_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button(Point{0,0},0,0,"red",cb_red));
    color_menu.attach(new Button(Point{0,0},0,0,"blue",cb_blue));
    color_menu.attach(new Button(Point{0,0},0,0,"black",cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    attach(lines);

    style_menu.attach(new Button(Point{0,0},0,0,"solid",
    [](Address, Address addr) {reference_to<Lines_window>(addr).change_style(Line_style::solid); }));
	style_menu.attach(new Button(Point{0,0},0,0,"dash",
    [](Address, Address addr) {reference_to<Lines_window>(addr).change_style(Line_style::dash); }));
	style_menu.attach(new Button(Point{0,0},0,0,"dot",
	[](Address, Address addr) {reference_to<Lines_window>(addr).change_style(Line_style::dot); }));
	style_menu.attach(new Button(Point{0,0},0,0,"dashdot",
    [](Address, Address addr) {reference_to<Lines_window>(addr).change_style(Line_style::dashdot); }));
	style_menu.attach(new Button(Point{0,0},0,0,"dashdotdot",
	[](Address, Address addr) {reference_to<Lines_window>(addr).change_style(Line_style::dashdotdot); }));
	attach(style_menu);

    style_menu.hide();
    attach(smenu_button);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
