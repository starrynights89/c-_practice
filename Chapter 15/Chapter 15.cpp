#include "Graph.h"
#include "Simple_window.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }

int main()
{
    constexpr int xmax = 600; //window size
    constexpr int ymax = 400; 

    constexpr int x_orig = xmax/2; //position of (0,0) is center of window
    constexpr int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    constexpr int r_min = -10; //range [-10:11)
    constexpr int r_max = 11; 

    constexpr int n_points = 400; //number of points used in range

    constexpr int x_scale = 30; //scaling factors
    constexpr int y_scale = 30;

    Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

    Function s(one,r_min,r_max,orig,n_points,x_scale,y_scale);
    Text ts(Point(100,y_orig-40),"one");
    win.attach(s);
    win.attach(ts);
    win.wait_for_button();

    Function s2(slope,r_min,r_max,orig,n_points,x_scale,y_scale);
    Text ts2(Point(100,y_orig+y_orig/2-20),"x/2");
    win.attach(s2);
    win.attach(ts2);
    win.wait_for_button();

    Function s3(square,r_min,r_max,orig,n_points,x_scale,y_scale);
    Text ts3(Point(x_orig-100,20),"x*x");
    win.attach(s3);
    win.attach(ts3);
    win.set_label("Function graphing: label functions");
    win.wait_for_button();
}