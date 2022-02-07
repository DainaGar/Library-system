#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class library {
private:
	std::vector<book> inventory;
	std::string name, location, director;
	float price_per_card;

public:
	library();
	void set_library(std::string n, std::string l, std::string d, float p);
	void show_data();
	void add_book_to_inventory(book b);
	void show_books_in_library();
	int search_book_by_author(std::string auth);
	int search_book_by_title(std::string tit);
	int search_book_by_subject(std::string sub);
};

#endif