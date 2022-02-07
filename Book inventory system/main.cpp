#include <iostream>
#include <random>
#include <string>
#include "Book.h"
#include "Library.h"

using namespace std;

int Menu();

int Menu() {
	int c;
	cout << "\n\t\tPlease choose what to do";
	cout << "\n\t\t1) Add a book";
	cout << "\n\t\t2) Search for a book by author";
	cout << "\n\t\t3) Search for a book by title";
	cout << "\n\t\t4) Search for a book by subject";
	cout << "\n\t\t5) Show all books in library";
	cout << "\n\t\t6) Exit program\n";
	cin >> c;
	return c;
}

int main() {
	srand(time(0));
	book b;
	library l;
	bool ch = true;
	string a, t, p, s, id;
	float ppp;
	int sk, choice = 0, id_random_part, c;
	string subject[] = { "Computer Science, information and general works",
		"Philosophy/Psychology", "Religion", "Social Sciences", "Language",
		"Science", "Technology", "Arts/Recreation", "Literature", "History/Geography" };
	cout << "\n\t\tPlease add a library: ";
	cout << "\n\t\tLibrary's name: ", cin >> a;
	cin.ignore();
	cout << "\n\t\tLibrary's location: ", cin >> t;
	cin.ignore();
	cout << "\n\t\tLibrary's director: ", cin >> p;
	cout << "\n\t\tPrice of library card: $", cin >> ppp;
	l.set_library(a, t, p, ppp);
	while (ch){
		choice = Menu();
		switch (choice) {
		case 1:
			cout << "\n\t\tAuthor: ", cin >> a;
			cin.ignore();
			cout << "\n\t\tTitle: ", cin >> t;
			cout << "\n\t\tPublisher: ", cin >> p;
			cout << "\n\t\tSubject: \n";
			for (sk = 0; sk < sizeof(subject) / sizeof(subject[0]); sk++)
				cout << "\t\t" << sk + 1 << ". " << subject[sk] << "\n";
			cout << "\n\t\tPlease choose with a number: ", cin >> c;
			id_random_part = (rand() % 99 + 10);
			switch (c) {
			case 1:
				s = subject[0];
				id = "0";
				id.append(to_string(id_random_part));
				cout << "\n\t\t" << s << " " << id;
				break;
			case 2:
				s = subject[1];
				id = "1";
				id.append(to_string(id_random_part));
				break;
			case 3:
				s = subject[2];
				id = "2";
				id.append(to_string(id_random_part));
				break;
			case 4:
				s = subject[3];
				id = "3";
				id.append(to_string(id_random_part));
				break;
			case 5:
				s = subject[4];
				id = "4";
				id.append(to_string(id_random_part));
				break;
			case 6:
				s = subject[5];
				id = "5";
				id.append(to_string(id_random_part));
				break;
			case 7:
				s = subject[6];
				id = "6";
				id.append(to_string(id_random_part));
				break;
			case 8:
				s = subject[7];
				id = "7";
				id.append(to_string(id_random_part));
				break;
			case 9:
				s = subject[8];
				id = "8";
				id.append(to_string(id_random_part));
				break;
			case 10:
				s = subject[9];
				id = "9";
				id.append(to_string(id_random_part));
				break;
			}
			cout << "\n\t\tAmount in stock: ", cin >> sk;
			b.add_book(a, t, p, s, id, sk);
			b.show_data();
			l.add_book_to_inventory(b);
			l.show_books_in_library();
			break;
		case 2:
			cout << "\n\t\tAuthor: ", cin >> a;
			l.search_book_by_author(a);
			break;
		case 3:
			cout << "\n\t\tTitle: ", cin >> t;
			l.search_book_by_title(t);
			break;
		case 4:
			for (sk = 0; sk < sizeof(subject) / sizeof(subject[0]); sk++)
				cout << "\t\t" << sk + 1 << ". " << subject[sk] << "\n";
			cout << "\n\t\tPlease choose with a number: ", cin >> c;
			l.search_book_by_subject(subject[c]);
			break;
		case 5:
			l.show_books_in_library();
			break;
		case 6:
			ch = false;
			break;
		}
	}
	cout << "";
	return 0;
}