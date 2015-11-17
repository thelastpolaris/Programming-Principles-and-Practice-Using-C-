#include "../fltk/Fl_GUI.h"


namespace Graph_lib {
//Exercise 1
	struct My_window : Window{
		My_window(Point xy, int x, int w, const string& label);
		void wait_for_button();
	private:
		Button next_button;
		Button quit_button;
		bool is_pressed;
		bool b_quit;
		void next();
		void quit();
	};
//Exercise 2
	struct Button_window : My_window{
		Button_window(Point xy, int x, int w, const string& label, int xn, int yn);
	private:
		Menu v1;
		Menu v2;
		Menu v3;
		Menu v4;
		void b11();
		void b12();
		void b13();
		void b14();

	//Callback. Second menu
		void b21();
		void b22();
		void b23();
		void b24();

	//Callback. Third menu
		void b31();
		void b32();
		void b33();
		void b34();

	//Callback. Fourth menu
		void b41();
		void b42();
		void b43();
		void b44();
		void get_xy(Point p);
		Out_box out_xy;
	};

	//Exercise 3
	struct Button_image : My_window {
		Button_image(Point xy,Point bxy, int w, int h, string img_name);
		void rand_move();
	private:
		Menu mb;
		Vector_ref<Button> vb;
		Image i;
	};

	inline int rand_int(int min, int max);

	//Exercise 4
	struct Shape_window : Window {
		Shape_window(Point xy, int x, int y, string label);
	protected:
		In_box coor_x;
		In_box coor_y;
		Menu buttons;
		Vector_ref<Shape> shapes;
		void draw_shape(string s);
		void draw_shape(string s, int x, int y);
	};

	//Exercise 5
	struct Single_window : Window {
		Single_window(Point xy, int x, int y, string label);
	private:
		Out_box coor;
		Menu buttons;
		Vector_ref<Shape> shapes;
		Button next;
		Point p;
		void draw_shape(string s);
		void nextShape();
		Point getCoordinates();
		string shape;
	};

	//Exercise 6
	struct Triangle : Polygon {
		Triangle(Point xy, int x, int y);
		int width() {return w;};
		int height() {return h;};
		void rotate(Point center, int degree);
	private:
		int w;
		int h;
	};

	struct Clock : Window {
		Clock(Point xy, int x, int y, string label);
		void runClock();
		static void cb_runClock(void*);
	private:
		Circle cl;
		Lines big_notches;
		Lines small_notches;
		Vector_ref<Text> digits;
		Circle center;
		Triangle big;
		Triangle small;
		Line seconds;
		tm* get_time();
		int current_min = 0;
	};

	//Exercise 7
	struct Airplane : Window {
		Airplane(Point xy, int x, int y, string label, string image, int x_step, int y_step);
		static void cb_fly(void*);
		void fly();
	private:
		Button start;
		Button stop;
		Image plane; //Address of image
		bool is_flying;
		struct Step {
			int x_orig;
			int y_orig;
			int x_step;
			int y_step;
			void reset_step() {x_step = x_orig;y_step = y_orig;};
		};
		Step step;
	};

	//Exercise 8
	struct Currency_converter : Window {
		Currency_converter(Point xy, int x, int y, string label, string file);
	private:
		Menu from;
		Menu to;
		string cur_from;
		string cur_to;
		In_box in_cur;
		Out_box out_cur;
		Button convert;
		Circle current_from;
		Circle current_to;
		struct Cur_pair{
			string from;
			double value;
		};
		std::vector<Cur_pair> pairs;
		void cb_from(int);
		void cb_to(int);
		void convert_cur();
	};

	//Exercise 9
	struct Calculator : Window {
		Calculator(Point xy, int x, int y, string label);
		void add_ch(string ch);
		void compute();
	private:
		//Numbers
		Button zero;
		Button one;
		Button two;
		Button three;
		Button four;
		Button five;
		Button six;
		Button seven;
		Button eight;
		Button nine;
		//Operators and signs
		Button comma;
		Button period;
		Button l_parenthesis;
		Button r_parenthesis;
		Button equal;
		Button plus;
		Button minus;
		Button division;
		Button multi;
		Button mod;
		//Functions
		Button power;
		Button fac;
		Button sqrt;
		//Input/output
		In_box input;
		Out_box output;
		bool is_result = false;
	};

	//Exercise 10
	struct Graph_window : Window {
		Graph_window(Point xy, int x, int y, string label);
	private:
		Axis x_axis;
		Axis y_axis;
		In_box r1;
		In_box r2;
		//Buttons
		Button sin;
		Button cos;
		Button tg;
		Button ctg;
		Button sqr;
		Button cube;
		Button four;
		Button five;
		//Functions
		void sin_g();
		void cos_g();
		void tg_g();
		void ctg_g();
		void sqr_g();
		void cube_g();
		void four_g();
		void five_g();
	};
} 
