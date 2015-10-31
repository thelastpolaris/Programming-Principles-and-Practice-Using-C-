// Bjarne Stroustrup 1/15/2010
// Chapter 8 Exercise 14

/*
	Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in each string.
	Also find the longest and shortest string and the lexicographically first and last string.
	How many separate functions would you use for these tasks? Why?
*/

#include "std_lib_facilities.h"	

vector<int> get_sizes(const vector<string>& vs)
{
	vector<int> res(vs.size());
	for (int i =0; i<vs.size(); ++i)
		res[i] = vs[i].size();
	return res;
}

/*
	There are quite a few ways of writing a function that finds the longest string.

	We must deal with the possibility of an empty vector argument;
	I decided just to throw an exception because "people shouldn't do that". The alternative
	would have been to return a -1 or something and hope that callers would remember to check for that.

	I decided to return the index of the longest string; that can be used for quite a variety of things
	by a caller.
*/

int longest(const vector<string>& v)
{
	if (v.size()==0) error("longest(): empty vector");	// protect against the empty string

	int m = v[0].size();		// we now know that there is a v[0]
	int max_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (m<v[i].size()) {
			max_index = i;
			m = v[i].size();
		}
	return max_index;
}

/*
	There are quite a few ways of writing a function that finds the shortest string.

	Here, I have deliberatly chosen one that makes different choices from longest().
	In a real program, we would want a single consistent approach.

	I decided to return a reference to the shortest string. Returning a reference to
	a string value implies the caller isn't told exactly where in the vector the string was found.
	However, retruning a reference means that the called can change its value.
*/

string& shortest(vector<string>& v)
{
	if (v.size()==0) error("shortest(): empty vector");	// protect against the empty string

	int m = v[0].size();		// we now know that there is a v[0]
	int min_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[i].size()<m) {
			min_index = i;
			m = v[i].size();
		}
	return v[min_index];
}

/*
	For the function finding the lexicographically first string, I decided just to return
	a copy of that string - or the empty string (that means that you can't tell from a call
	of lex_first() whether it was empty contained an empty string), but you can always check
	the vector's size if you are interested.

	Also, I return a copy of the lexicographically first string. 
*/

string lex_first(const vector<string>& v)
{
	if (v.size()==0) return "";	// the empty string is first

	int first_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[i]<v[first_index])
			first_index = i;
	return v[first_index];
}

/*
	For the function finding the lexicographically last string, I decided to return
	the index of the string. However, I chose a sneeky way of getting a result out:
	I put it into an argument (a non-const reference argument).
	
	I also returned -1 to indicate the empty vector. That's redundant (the caller could
	as easily have check for the empty vector before calling as checking for -1 afterwards)
	and dangerous. Why?
*/

void lex_last(vector<string>& v, int& last)
{
	if (v.size()==0) {
		last = -1;	// -1 indicates "the empty vector"
		return;
	}

	int last_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[last_index]<v[i])
			last_index = i;
	last = last_index;	// copy last_index out of function
}

/*
	Why did I choose to write 5 functions, rather than bundeling all the functionality into get_sizes()?
	I could have done that and gotten all the information from a single pass over the vector<string>.
	I might have chosen to do that if I knew that this was exactly the information I always wanted.
	However, I chose separate functions, each being simple because each does a single thing and each
	doing its individual task without overhead from producing related results that I may not need.
*/

int main()
try
{
	vector<string> vs;
	vs.push_back("Technicalities");
	vs.push_back("a");
	vs.push_back("A");
	vs.push_back("hellohellohell");	// same length as "Technicalities"
	vs.push_back("Hellohellohell");	// lexicographically 'H' < 'h'
//	vs.push_back("");	// the empty string
	vs.push_back("Technicalities");	// More technicalities
	vs.push_back("!");	// same length as "a"

	cout << "sizes: ";
	vector<int> lengths = get_sizes(vs);
	for (int i=0; i<lengths.size(); ++i) cout << lengths[i] << ' ';
	cout << '\n';

	int i = longest(vs);
	cout << "longest(): index==" << i << "; string=='" << vs[i] << "'\n";	// note the quotes: I want to be able to see the empty string

	cout << "shortest(): '" << shortest(vs) << "'\n";	// note the quotes: I want to be able to see the empty string

	cout << "lex_first(): '" << lex_first(vs) << "'\n";
	
	lex_last(vs,i);	// pass 'i' for lex_last() to return into
	cout << "lex_last(): index==" << i << "; string=='" << vs[i] << "'\n";	// note the quotes: I want to be able to see the empty string
																			// note: had vs been empty, this code would have accessed vs[-1]; Ouch!

	keep_window_open("~");	// For some Windows(tm) setups
}
catch (runtime_error e) {	// this code is to produce error messages
	cout << e.what() << '\n';
	keep_window_open("~");	// For some Windows(tm) setups
}

/*
	This solution is a bit short on test cases. Maybe it has bugs?

	Certainly this solution is messy: The four functions for finding a string in a vector<string each provides a different
	style of interface. That would never do in real code! Consistency in code is a virtue. Which style
	is best: I'll plunge for the first, longest():
		throwing an exception for bad input (the empty string) is error handling that cannot be forgotten or ignored.
		returning an index gives the caller not just a string value but a position.
	Can we do better still? Yes, we'll see how in Chapter 20.

	Note that the different styles implies different styles of use and different kinds of information returned
	to the called. You could fairly say that if I had been more presice about what I wanted those functions to do,
	it would have been much easier to write them and they would naturally exhibited a common style. Saying so
	would be correct: A good precise specification of what is required of a solution is most valuable,
	but unfortunately we don't always get good requirements (in the real world as well as for exercises).
*/
