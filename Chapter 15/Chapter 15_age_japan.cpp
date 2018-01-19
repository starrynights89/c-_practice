#include "Graph.h"
#include "Simple_window.h"

struct Distribution
{
    int year, young, middle, old;
};

class Scale
{
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} { } 
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

istream& operator>>(istream& is, Distribution& d)
    //assume format: (year : young middle old)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if(is >> ch1 >> dd.year
          >> ch2 >> dd.young >> dd. middle >> dd.old
          >> ch3)
    {
        if(ch1!='('||ch2!=':'||ch3!=')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
    {
        return is;
    }
    d = dd;
    return is;

	string file_name = "japanese-age-data.txt";
	ifstream ifs{ file_name };
	if (!ifs) error("can't open", file_name);

	for (Distribution d; ifs >> d;)
	{
		if (d.year<base_year || end_year<d.year)
		{
			error("year out of range");
		}
		if (d.year + d.middle + d.old != 100)
		{
			error("percentages don't add up");
		}
	}
}

constexpr int xmax = 600; //window size
constexpr int ymax = 400; 

constexpr int xoffset = 100; //distance from left-hand side of window to y axis
constexpr int yoffset = 60; //distance from bottom of window to x axis

constexpr int xspace = 40; //space beyond axis
constexpr int yspace = 40;

constexpr int xlength = xmax-xoffset-xspace;  //length of axes
constexpr int ylength = ymax-yoffset-yspace;

constexpr int base_year = 1960;
constexpr int end_year = 2040;

constexpr double xscale = double(xlength)/(end_year-base_year);
constexpr double yscale = double(ylength)/100;

Scale xs {xoffset,base_year,xscale};
Scale ys {ymax-yoffset,0,-yscale};

int main()
{
}