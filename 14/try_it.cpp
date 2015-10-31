#include "../fltk/Simple_window.h"   // get access to our window library
#include "../fltk/Graph.h"                    // get access to our graphics library facilities 
#include <iostream>

class B1 {
public:
	virtual void vf() const { cout << "B1:vf" << endl;};
	virtual void pvf() const =0;
	void f() const { cout << "B1:f" << endl;};
};

class D1 : public B1 {
public:
	void vf() const override { cout << "D1:vf" << endl;};
	void f() const { cout << "D1:f" << endl;};
};

class D2 : public D1 {
public:
	void pvf() const override { cout << "D2:pvf" << endl;};
	void vf() const override { cout << "D2:vf" << endl;};
	void f() const { cout << "D2:f" << endl;};
};

void call(B1& b) {
	b.vf();
	b.f();
}

class B2 {
public:
	virtual void pvf() =0;
};

class D21 : public B2 {
public:
	void pvf() override { cout << s << endl;};
	D21(string ss) :s{ss}{}
	D21() :s{"default"}{}
	void set_string(string ss) {s = ss;};
	void get_string() {cout << s << " ";};
private:
	string s;

};

class D22 : public D21 {
public:
	virtual void pvf() { set_string("w");get_string();cout << n << endl;};
	D22(int nn) :n{nn}{}
private:
	int n;
};

void call(B2& b) {
	b.pvf();
}

int main()
{
	/*B1 b;
	b.vf();
	b.f();
	D1 d;
	d.vf();
	d.f();
	call(d);
	D2 dd;
	//call(dd);
	dd.vf();
	dd.f();
	dd.pvf();*/
	D21 d {"test"};
	call(d);
	D22 dd {50};
	call(dd);

}
