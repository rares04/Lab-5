#include "Tests.h"
#include <iostream>

using std::cout;

int main() {
	Tests t;
	t.testAdd();
	t.testDelete();
	t.testUpdate();
	t.testAdministrator();
	t.testUser();

	cout << "\nTest End\n\n";
}