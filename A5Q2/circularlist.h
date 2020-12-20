#include<iostream>
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
};
template<typename T>
class list {
	node<T>* head, * it;
	int n;
	node<T>* find_ptr(const T& val) {
		node<T>* temp;
		temp = head;
		do {
			if (temp->data == val)
				return temp;
			temp = temp->next;
		} while (temp != head);
		return NULL;
	}
public:
	list() {
		head = NULL;
		n = 0;
		it = NULL;
	}
	~list() {
		make_empty();
	}
	//O(1)
	void insert(const T& val) {
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		if (empty()) {
			head = temp;
			head->next = head;
		}
		else {
			temp->next = head->next;
			head->next = temp;
			head = temp;
		}
		n++;
	}
	//O(n)
	//Omega(1)
	bool find(const T& val) const {
		node<T>* temp;
		temp = head;
		do {
			if (temp->data == val)
				return true;
			temp = temp->next;
		} while (temp != head);
		return false;
	}
	//O(n)
	//Omega(1)
	bool update(const T& old_val, const T& new_val) {
		node<T>* temp;
		temp = find_ptr(old_val);
		if (temp != NULL) {
			temp->data = new_val;
			return true;
		}
		else
			return false;
	}
	//O(n)
	//Omega(1)
	bool erase(const T& val) {
		if (head == NULL)
			return false;
		node<T>* temp;
		temp = head;
		if (head == head->next && head->data == val) {
			head = NULL;
			delete temp;
			n--;
			return true;
		}
		while (temp->next != head) {
			if (temp->next->data == val) {
				node<T>* to_del;
				to_del = temp->next;
				temp->next = to_del->next;
				delete to_del;
				n--;
				return true;
			}
			temp = temp->next;
		}
		if (head->data == val) {
			node<T>* to_del;
			to_del = temp->next;
			temp->next = head->next;
			head = temp;
			delete to_del;
			n--;
			return true;
		}
		return false;
	}
	bool empty() const {
		return head == NULL;
	}
	bool full() const {
		node<T>* temp;
		temp = new node<T>;
		if (temp == NULL)
			return true;
		else {
			delete temp;
			return false;
		}
	}
	void make_empty() {
		while (head != NULL) {
			erase(head->data);
		}
		n = 0;
	}
	int length()const {
		return n;
	}
	void reset() {
		it = head->next;
	}
	bool is_last() const {
		return it == head->next;
	}
	T get_next() {
		T val;
		val = it->data;
		it = it->next;
		return val;
	}
};