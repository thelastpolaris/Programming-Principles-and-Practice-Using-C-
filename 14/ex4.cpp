/* Chapter 14 Exercise 4
Define a class Immobile_Circle, which is just like Circle but can’t be moved.
*/
#include "14.h"

int main() {
	Graph_lib::Immobile_Circle ic {Point {200,200}, 100};
	ic.move(50,50);
}