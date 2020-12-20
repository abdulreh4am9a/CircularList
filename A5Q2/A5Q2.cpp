#include"circularlist.h"
int main() {
	list<int> l1;
	l1.insert(2);
	l1.insert(5);
	l1.insert(3);
	l1.insert(1);
	l1.insert(4);
	l1.reset();
	do {
		cout << l1.get_next() << " ";
	} while (!l1.is_last());
	cout << endl;
	l1.update(1, 0);
	l1.reset();
	do {
		cout << l1.get_next() << " ";
	} while (!l1.is_last());
	cout << endl;
	l1.update(0, 6);
	l1.reset();
	do {
		cout << l1.get_next() << " ";
	} while (!l1.is_last());
	cout << endl;
	l1.erase(2);
	l1.reset();
	do {
		cout << l1.get_next() << " ";
	} while (!l1.is_last());
	cout << endl;
	int val = 1;
	if (l1.find(val)) {
		cout << "Found " << val << endl;
	}
	else {
		cout << "Can't find " << val << endl;
	}
	val = 6;
	if (l1.find(val)) {
		cout << "Found " << val << endl;
	}
	else {
		cout << "Can't find " << val << endl;
	}
	return 0;
}
