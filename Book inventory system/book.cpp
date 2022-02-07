#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

book::book() {
	author = "";
	title = "";
	publisher = "";
	subject = "";
	ID = "";
	stock = 0;
}
void book::add_book(string a, string t, string p, string s, string id, int sk) {
	author = a;
	title = t;
	publisher = p;
	subject = s;
	stock = sk;
	ID = id;
	//Add date yyyy
}
void book::show_data() {
	cout << "\n\t\tAothor: " << author;
	cout << "\n\t\tTitle: " << title;
	cout << "\n\t\tPublisher: " << publisher;
	cout << "\n\t\tSubject: " << subject;
	cout << "\n\t\tID: " << ID;
	cout << "\n\t\tAmount in stock: " << stock;
}
void book::take_out_book() {
	if (stock != 0)
		stock--;
	else
		cout << "\n\t\tThere's no more in stock!\n";
}
void book::return_book() { stock++; }
string book::return_author() { return author; }
string book::return_title() { return title; }
string book::return_publisher() { return publisher; }
string book::return_subject() { return subject; }
string book::return_ID() { return ID; }
int book::return_stock() { return stock; }