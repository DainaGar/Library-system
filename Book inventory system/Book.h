#pragma once
#include <string>
#ifndef BOOK_H
#define BOOK_H

class book {
private:
	std::string author, title, publisher, subject, ID;
	int stock;
public:
	book();
	void add_book(std::string a, std::string t, std::string p, std::string s, std::string id, int sk);
	void show_data();
	void take_out_book();
	void return_book();
	std::string return_author();
	std::string return_title();
	std::string return_publisher();
	std::string return_subject();
	std::string return_ID();
	int return_stock();
};

#endif