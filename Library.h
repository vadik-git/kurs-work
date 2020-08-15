#pragma once
#include"Book.h"
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include"Exception.h"
#include<fstream>
#include"ClientLibrary.h"
using namespace std;
class BadNameBook :public exception {
public:
	BadNameBook(const string &msg) :exception(msg.c_str()) {}
};
class IncorectYear :public exception {
public:
	IncorectYear(const string &msg) : exception(msg.c_str()) {}
};
class Library{
	Book book;
	Newspaper newspaper;
	Journal journal;
	ClientLibrary client;
	list<Book>listbook;
	list<Newspaper>listnewspaper;
	list<Journal>listjournal;
	list<ClientLibrary>listDebtorBook;
	list<ClientLibrary>listDebtorJournal;
	list<ClientLibrary>listDebtorNewspaper;
public:
	Library() = default;
	//func Exception
	void nameBook() {
		for (int i = 0; i < book.name.length(); i++) {
			if (book.name[i] >= '0'&&book.name[i] <= '9') {
				throw BadNameBook("Book title cannot contain numbers");
				
				return;
			}
		}
	}
	void yearIncorect() {
		if (book.yearOfissue.size() > 4) {
			throw IncorectYear("Incorect year");
			return;
		}
	}
	/////////////////////
	/*ofstream fout;
	fout.open(fname, ofstream::app);
	if (!fout.is_open()) {
		cout << "eroor open file";
	}
	else {
		cout << "file oopen" << endl;
		fout << nameProduct << endl;
		fout << priceProduct << endl;
		fout << quanituProduct << endl;
	}
	fout.close();*/
	void addBook() {
	
		ofstream fout;
		fout.open("Book.txt", ofstream::app);
		if (!fout.is_open()) {
			cout << "Error open file" << endl;
		}
		else {
			cout << "Enter name book" << endl;
			cin >> book.name;
			try {
				nameBook();
			}
			catch (exception&ex) {
				cout << ex.what() << endl;
			}
			cout << "Enter name author" << endl;
			cin >> book.nameAuthor;

			cout << "Enter year of issue" << endl;
			cin >> book.yearOfissue;
			try {
				yearIncorect();
			}
			catch (exception&ex) {
				cout << ex.what() << endl;
				return;
			}
			cout << "Enter count book" << endl;
			cin >> book.count;

			fout << book.name;
			fout << book.nameAuthor;
			fout << book.yearOfissue;
			fout << book.count;

			listbook.push_back(book);
			fout.close();
		}

			
	}
	void addNewspaper() {
		cout << "Enter name newspaper" << endl;
		cin >> newspaper.name;
		cout << "Enter year of issue newspaper" << endl;
		cin >> newspaper.yearOfissue;
		cout << "Enter count newspaper" << endl;
		cin >> newspaper.count;
		listnewspaper.push_back(newspaper);
	}
	void addJournal() {
		cout << "Enter name journal" << endl;
		cin >> journal.name;
		cout << "Enter year of issue journal" << endl;
		cin >> journal.yearOfissue;
		cout << "Enter count journal" << endl;
		cin >> journal.count;
		listjournal.push_back(journal);
	}
	/////////////////////
	void deletebook() {
		string name;
		cout << "enter name book delete" << endl;
		cin >> name;
		for (auto it = listbook.begin(); it != listbook.end(); it++) {
			if (it->name == name) {
				listbook.erase(it);
				return;
			}
		}
	}
	void deletejournal() {
		string name;
		cout << "enter name journal delete" << endl;
		cin >> name;
		for (auto it = listjournal.begin(); it != listjournal.end(); it++) {
			if (it->name == name) {
				listjournal.erase(it);
				return;
			}
		}
	}
	void deletenewspaper() {
		string name;
		cout << "enter name newspaper delete" << endl;
		cin >> name;
		for (auto it = listnewspaper.begin(); it != listnewspaper.end(); it++) {
			if (it->name == name) {
				listnewspaper.erase(it);
				return;
			}
		}
	}
	void deleteLibrary() {
		listbook.clear();
		listjournal.clear();
		listnewspaper.clear();
	}
	////////////////////////////
	void toTakeBook() {
		cout << "Enter your name" << endl;
		cin>>client.name;
		cout << "Enter name book which you want to take" << endl;
		cin >> client.nameBook;
		for (Book book : listbook) {
			if (client.nameBook == book.name) {
				listDebtorBook.push_back(client);
			}
		}
	}
	void toTakeJournal() {
		cout << "Enter your name" << endl;
		cin >> client.name;
		cout << "Enter name journal which you want to take" << endl;
		cin >> client.nameJournal;
		for (Journal journal:listjournal) {
			if (client.nameJournal == journal.name) {
				listDebtorJournal.push_back(client);
			}
		}
	}
	void toTakeNewspaper() {
		cout << "Enter your name" << endl;
		cin >> client.name;
		cout << "Enter name book which you want to take" << endl;
		cin >> client.nameNewspaper;
		for (Newspaper newspaper:listnewspaper) {
			if (client.nameNewspaper == newspaper.name) {
			   listDebtorNewspaper.push_back(client);
			}
		}
	}
	/////////////////////////////
	void printLibrary() {
		
		ifstream fin;
		fin.open("Book.txt");
		if (!fin.is_open()) {
			cout << "File not open" << endl;
		}
		else {
			listbook.sort([](const Book&a, const Book&b) {return a.name < b.name; });
			cout << "Booook" << endl;
			for (Book a : listbook) {
				cout << a.name << "<>" << a.nameAuthor << "<>" << a.yearOfissue << " <> " << a.count;
				cout << endl;
				string str;
				while (!fin.eof()) {
					str = "";
					getline(fin, str);
					cout << str << endl;
				}
			}
		}

		

		listnewspaper.sort([](const Newspaper&a, const Newspaper&b) {return a.name < b.name; });
		cout << "Newspaper" << endl;
		for (Newspaper a : listnewspaper) {
			cout << a.name << "<>"<< a.yearOfissue<<"<>"<<a.count;
			cout << endl;
		}
		listjournal.sort([](const Journal&a, const Journal&b) {return a.name < b.name; });
		cout << "Journal" << endl;
		for (Journal a : listjournal) {
			cout << a.name << "<>" << a.yearOfissue<<"<>"<<a.count;
			cout << endl;
		}
	}
	void printListDebtor() {
		for (ClientLibrary client : listDebtorBook) {
			cout << "List debtor book " << endl;
		    cout <<"Name client >> "<< client.name <<" || "<<" Name book >> "<< client.nameBook << endl;
		}
		for (ClientLibrary client : listDebtorJournal) {
			cout << "List debtor journal " << endl;
			cout << "Name client >> " << client.name <<" || "<< " Name journal >> " << client.nameJournal << endl;
		}
		for (ClientLibrary client : listDebtorNewspaper) {
			cout << "List debtor newspaper " << endl;
			cout << "Name client >> " << client.name << " || "<<" Name newspaper >> " << client.nameNewspaper << endl;
		}
	}
	/////////////////////////////
	void toGiveBook() {
		string name;
		string namebook;
		cout << "enter your name" << endl;
		cin >> name;
		cout << "enter name book" << endl;
		cin >> namebook;
		for (auto it = listDebtorBook.begin(); it != listDebtorBook.end(); it++) {
			if (it->name == name && it->nameBook==namebook) {
				cout << "thanks" << endl;
				listDebtorBook.erase(it);
				return;
			}
		}
		system("cls");
		
	}
	void toGiveJournal() {
		string name;
		string nameJournal;
		cout << "enter your name" << endl;
		cin >> name;
		cout << "enter name journal" << endl;
		cin >> nameJournal;
		for (auto it = listDebtorJournal.begin(); it != listDebtorJournal.end(); it++) {
			if (it->name == name && it->nameJournal==nameJournal) {
				cout << "thanks" << endl;
				listDebtorJournal.erase(it);
				return;
			}
		}
		system("cls");
	}
	void toGiveNewspaper() {
		string name;
		string nameNewspaper;
		cout << "enter your name" << endl;
		cin >> name;
		cout << "enter name newspaper" << endl;
		cin >> nameNewspaper;
		for (auto it = listDebtorNewspaper.begin(); it != listDebtorNewspaper.end(); it++) {
			if (it->name == name && it->nameNewspaper == nameNewspaper) {
				cout << "thanks" << endl;
				listDebtorBook.erase(it);
				return;
			}
		}
		system("cls");
	}
	///////////////////////////
	void reaaadLiric(const string&fname) {
		ifstream fin;
		fin.open(fname);
		if (!fin.is_open()) {
			cout << "eroor file not open" << endl;
		}
		else {
			cout << "file open" << endl;
			string str;
			while (!fin.eof()) {
				str = "";
				getline(fin, str);
				cout << str << endl;
			}
		}
	}

};

