/* Chapter 17 Exercise 10
Look at your solution of exercise 7. Is there any way that input could get the array to overflow; that is, is there any 
way you could enter more characters than you allocated space for (a serious error)? Does anything reasonable happen 
if you try to enter more characters than you allocated?
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <inttypes.h>

int main() try {
	char* ch = new char[10];
	char c;
	int length = 0;
	while(std::cin.get(c) && c != '!') {
		ch[length] = c;
		length++;
	}
	for(int i = 0; ch[i]; ++i) std::cout << ch[i];
	std::cout << '\n';
	delete[] ch;
}
catch(std::runtime_error& e) {
	std::cout<< e.what() << '\n';
}
catch(...) {
	std::cout << "Unknown error" << '\n';
}
From my participance in 2 MUN conferences I understood, that MUN is useful not only for International Relations/Business students. For Software Engineer like me it is a great pleasure to meet people, that work and study in completely different sphere. Sharing opinions, trying to find an answer for global problems is very interesting, especially, when there are young, open-minded people all around you.
One of the reasons, why I like the idea of MUN is that it is a great place not only to practice you English, but also to improve public speaking skills. This will help the participants of MUN in their future career, as I consider good communication and speaking skills very important for future leaders.
Last, but not the least, MUN makes people aware of today's problems. Showing the young generation the variety of ecological, social and political problems that we yet have to tackle is immensely important if we want to make the world a better place to live.

My first MUN took place in Miras University, in December 2014. It was a great chance to familiarize myself with the format of MUN and practice my English.
4 months later, in May 2015, I participated in New Silk Way International Model United Nations that was held in Al Farabi Kazakh National University. Incredible atmosphere, hot discussions and a lot of new friends made me fall in love with MUN.