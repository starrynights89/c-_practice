#include "Graph.h"
#include "Simple_window.h"


struct Point
{
    int x, y;
};

bool operator==(Graph_lib::Point a, Graph_lib::Point b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Graph_lib::Point a, Graph_lib::Point b) { return !('a'=='b'); }

//related lines
struct Lines : Shape 
{
	Lines() {}; //empty
	Lines(initializer_list<Graph_lib::Point>lst);

	void draw_lines() const;
	void add(Graph_lib::Point p1, Graph_lib::Point p2);
};



int main()
{
	//draw two lines
	Graph_lib::Lines x; 

	Simple_window win1{x,600, 400, "two lines" };

	x.add(Graph_lib::Point{100,100},Graph_lib::Point{200,100}); //first line:horizontal
	x.add(Graph_lib::Point{150,50},Graph_lib::Point{150,150}); //second line:vertical

	win1.wait_for_button(); //display!
}