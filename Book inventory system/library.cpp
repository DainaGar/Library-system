#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"
using namespace std;

library::library() {
	name = "";
	location = "";
	director = "";
	price_per_card = 0.0;
}
void library::set_library(string n, string l, string d, float p) {
	name = n;
	location = l;
	director = d;
	price_per_card = p;
}
void library::show_data() {
	cout << "\n\t\tLibrary's name: " << name;
	cout << "\n\t\tLibrary's location: " << location;
	cout << "\n\t\tLibrary's director: " << director;
	cout << "\n\t\tPrice of library card: $" << price_per_card;
}
void library::add_book_to_inventory(book b) { inventory.push_back(b); }
void library::show_books_in_library() {
	int size_of_inventory = inventory.size();
	for (int i = 0; i < size_of_inventory; i++) {
		cout << i + 1 << ". ";
		inventory[i].show_data();
	}
}
int library::search_book_by_author(string auth) {
	int size_of_inventory = inventory.size();
	for (int i = 0; i < size_of_inventory; i++) {
		if (inventory[i].return_author() == auth && inventory[i].return_stock() > 0) {
			cout << "\n\t\tThe book is available";
			inventory[i].show_data();
			return 1;
		}
		else if (inventory[i].return_author() == auth && inventory[i].return_stock() == 0) {
			cout << "\n\t\tThe library has the book, but it's unavailable right now";
			inventory[i].show_data();
			return 0;
		}
		else {
			cout << "\n\t\tCouldn't find the book, please check the spelling";
			return 0;
		}
	}
}
int library::search_book_by_title(string tit) {
	int size_of_inventory = inventory.size();
	for (int i = 0; i < size_of_inventory; i++) {
		if (inventory[i].return_title() == tit && inventory[i].return_stock() > 0) {
			cout << "\n\t\tThe book is available";
			inventory[i].show_data();
			return 1;
		}
		else if (inventory[i].return_title() == tit && inventory[i].return_stock() == 0) {
			cout << "\n\t\tThe library has the book, but it's unavailable right now";
			inventory[i].show_data();
			return 0;
		}
		else {
			cout << "\n\t\tCouldn't find the book, please check the spelling";
			return 0;
		}
	}
}
int library::search_book_by_subject(string sub) {
	int size_of_inventory = inventory.size(), i;
	vector<book> books_of_subject;
	for (i = 0; i < size_of_inventory; i++) {
		if (inventory[i].return_subject() == sub && inventory[i].return_stock() > 0)
			books_of_subject.push_back(inventory[i]);
	}
	int size = books_of_subject.size();
	if (size != 0) {
		for (i = 0; i < size; i++)
			books_of_subject[i].show_data();
		return 1;
	}
	else {
		cout << "\n\t\tSorry! There doesn't seem to be any\n\t\tbooks on that subject\n";
		return 0;
	}
}