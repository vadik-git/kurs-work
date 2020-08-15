#pragma once
#include"Library.h"
#include"Book.h"
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
class Menu {
	Library a;
	int action;
	string fname = "liric.txt";
public:
	Menu() = default;
	int menu() {
		
        int b;
		do {
			cout << "1.Client library" << endl;
			cout << "2.Admin library" << endl;
			cout << "0.Exit" << endl;
			cin >> b;
			switch (b) {
			case 1:
				int c;
				do {
					cout << "1.Watch library" << endl;
					cout << "2.To take literature" << endl;
					cout << "3.To give literature" << endl;
					cout << "4.Read lirics" << endl;
					cout << "0.Exit" << endl;
					cin >> c;
					switch (c) {
					case 1:
						a.printLibrary();
						break;
					case 2:
						int tmp;
						do {
							cout << "1.To take Book" << endl;
							cout << "2.To take Journal" << endl;
							cout << "3.To take Newspaper" << endl;
							cout << "0.Exit" << endl;
							cin >> tmp;
							switch (tmp) {
							case 1:
								a.toTakeBook();
								break;
							case 2:
								a.toTakeJournal();
								break;
							case 3:
								a.toTakeNewspaper();
								break;
							case 0:
								break;
							}
						} while (tmp != 0);
						break;
					case 3:
						int d;
						do {
							cout << "1.To give book" << endl;
							cout << "2.To give journal" << endl;
							cout << "3.To give newspaper" << endl;
							cout << "0.Exit" << endl;
							cin >> d;
							switch (d) {
							case 1:
								a.toGiveBook();
								break;
							case 2:
								a.toGiveJournal();
								break;
							case 3:
								a.toGiveNewspaper();
								break;
							case 0:
								break;
							}

						} while (d != 0);

						break;
					case 4:
						int read;
						do {

							cout << "1.Read" << endl;
							cout << "0.Exit" << endl;
							cin >> read;
							switch (read) {
							case 1:
								a.reaaadLiric(fname);
								break;
							case 0:
								//return 0;
								break;
							}
						} while (read != 0);
						break;
					case 0:
						//return 0; 
						break;
					}
				} while (c!=0);

				break;

			case 2:
				do {
					cout << "1.Add library" << endl;
					cout << "2.Print library" << endl;
					cout << "3.Print debtor" << endl;
					cout << "4.Delete library" << endl;
					cout << "0.Exit" << endl;
					cin >> action;
					switch (action) {
					case 1:
						int act;
						do {
							cout << "1.Add Book" << endl;
							cout << "2.Add Journal" << endl;
							cout << "3.Add Newspaper" << endl;
							cout << "0.Exit" << endl;
							cin >> act;
							switch (act) {
							case 1:
								a.addBook();
								break;
							case 2:
								a.addJournal();
								break;
							case 3:
								a.addNewspaper();
								break;
							}
						} while (act != 0);
						break;
					case 2:
						a.printLibrary();
						break;
					case 3:
						a.printListDebtor();
						break;
					case 4:
						int actt;
						do {
							cout << "1.Delete book" << endl;
							cout << "2.Delete journal" << endl;
							cout << "3.Delete Newspaper" << endl;
							cout << "4.Delete library" << endl;
							cout << "0.Exit" << endl;
							cin >> actt;
							switch (actt) {
							case 1:
								a.deletebook();
								break;
							case 2:
								a.deletejournal();
								break;
							case 3:
								a.deletenewspaper();
								break;
							case 4:
								a.deleteLibrary();
								break;
							case 0:
								//return 0;
								break;
							}
						} while (actt != 0);
						break;
					case 0:
						//return 0;
						break;
					}
				} while (action != 0);
				break;
			case 0:
				return 0;
				break;
			}
		} while (b!=0);
	}
};




