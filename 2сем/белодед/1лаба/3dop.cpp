#include <iostream>// то же что и в первом задании
#include <vector>
#include <string>
using namespace std;
enum temperature { minsk, vitebsk = -16, grodno, gomel = grodno + 10 };
int main()
{
	string s1 = "hello"; string s2 = "4321";
	s1.insert(3, s2);
	return 0;
}