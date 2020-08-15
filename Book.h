#pragma once
#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

class LibraryThing abstract {
public:
	string name;
	string yearOfissue;
	int count;
};
class Newspaper :public LibraryThing {
};
class Book :public LibraryThing {
public:
	string nameAuthor;
};
class Journal :public LibraryThing {
};

