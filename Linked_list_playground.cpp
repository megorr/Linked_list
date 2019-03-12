#include <iostream>
#include "Linked_list.h"

using namespace std;

int main()
{
	Linked_list<int> a(10);
	a.push(15);
	a.push(13);
	a.print();

	return 0;
}