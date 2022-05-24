#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a13.out

*/

using namespace Graph_lib;

int main(){
	try {
		Point t1(300, 50);
		Simple_window win(t1, 1000, 800, "My window");
		win.wait_for_button();
		
		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for(int i = 100; i<=x_size; i+=100){
			grid.add(Point(i,0),Point(i,y_size));
			grid.add(Point(0,i),Point(x_size,i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		Rectangle r1 {Point{0, 0}, 100, 100};
		Rectangle r2 {Point{100, 100}, 100, 100};
		Rectangle r3 {Point{200, 200}, 100, 100};
		Rectangle r4 {Point{300, 300}, 100, 100};
		Rectangle r5 {Point{400, 400}, 100, 100};
		Rectangle r6 {Point{500, 500}, 100, 100};
		Rectangle r7 {Point{600, 600}, 100, 100};
		Rectangle r8 {Point{700, 700}, 100, 100};
		win.attach(r1);
		win.attach(r2);
		win.attach(r3);
		win.attach(r4);
		win.attach(r5);
		win.attach(r6);
		win.attach(r7);
		win.attach(r8);
	
		Closed_polyline poly_rect;
		
		r1.set_fill_color(Color::red);
		r2.set_fill_color(Color::red);
		r3.set_fill_color(Color::red);
		r4.set_fill_color(Color::red);
		r5.set_fill_color(Color::red);
		r6.set_fill_color(Color::red);
		r7.set_fill_color(Color::red);
		r8.set_fill_color(Color::red);
		
		win.wait_for_button();
		
		Image h (Point(0,0), "homer.jpeg");
		Image c (Point(200,200), "cooler.jpeg");
		Image b (Point(400,400), "bunny.jpeg");
		Image kk (Point(600,600), "kitty.jpeg");
		win.attach(h);
		win.attach(c);
		win.attach(b);
		win.attach(kk);
		win.set_label("images");
		win.wait_for_button();
    		
    		int k = 0;
    		int z = 0;
    		
    		while (true){
    			if(k/800 == 1){
    				k-=800;
    				z+=100;
    			}
    			if(z/800 == 1){
    				z=0;
    			}
    		Image movingImg(Point(k,z),"LoL-flash.jpeg");
    		win.attach(movingImg);
    		k+=100;
    		
    		win.wait_for_button();	
    		}
    		
    		
		    		
    		return 0;
		
	} catch (exception& e) {
		cerr << "exception: " << e.what() <<endl;
		return 1;
	} catch (...) {
		cerr << "exception\n";
		return 2;
	}
}
