// ---------------------------------------------------------
// File name: Person.h
// Project name: classes
// ---------------------------------------------------------
// Creator's name and email: Imaad Mohammed imaadmohammed@gmail.com
// Course-Selection: CS 1B
// Creation Date: 4/12/18
// Date of Last Modification: 4/12/18
// ---------------------------------------------------------
// Purpose: HW 10-1
// ---------------------------------------------------------
// Algorithm:
//  Create a header file for constructors and prototypes
// ---------------------------------------------------------
// -                 DATA DICTIONARY
// - CONSTANTS
// -
// - NAME			   DATA TYPE			VALUE
// - ---------------   ---------- 			--------
// -
// -
// - NAME			   DATA TYPE			INITIAL VALUE
// - ---------------   ---------- 			-------------
//   Person				class
//   fName				string
//   lname				stirng
//	address				string
//  height				double
//  dob					string
//   gender				char
// ---------------------------------------------------------

#ifndef BOOKDATA_H_
#define BOOKDATA_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "windows.h"

using namespace std;

class BookData
{
private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	int sortCode; //2 = sort by qty, 1 = sort by wholesale???

public:
	/**********************CONSTRUCTORS*****************/

	//Function: Person()
	// Sets attributes to default
	// Receives nothing
	// Returns nothing
	BookData()
	{
		setTitle("not set");
		setISBN ("not set");
		setAuthor("not set");
		setPub("not set");

	}

	//Function: BookData(all attributes)
	// Sets attributes to the inputs
	// Receives all attributes
	// Returns nothing
	BookData(string t, string i, string a, string p)
	{
		setTitle(t);
		setISBN (i);
		setAuthor(a);
		setPub(p);
	}

	//~BookData(void){
	//	cout << "Object is deleted" << endl;
	//}


	void setTitle(string t)
	{
		bookTitle = t;
	}


	void setISBN(string i)
	{
		isbn = i;
	}


	void setAuthor(string a)
	{
		author = a;
	}


	void setPub(string p)
	{
		publisher = p;
	}

	void setSortCode (int c){
		sortCode = c;
	}


	string getTitle() const
	{
		return bookTitle;
	}

	string getISBN() const
	{
		return isbn;
	}


	string getAuthor() const
	{
		return author;
	}


	string getPub() const
	{
		return publisher;
	}

	int getSortCode()
	{
		return sortCode;
	}

	void print()
	{
		cout << getTitle() << endl;
		cout << getISBN() << endl;
		cout << getAuthor() << endl;
		cout << getPub() << endl;
	}


	//overloaded operators for bookData


	bool operator>=(const BookData& other_Book) const{
	  		bool found = false;
	  		if (this != &other_Book) {
	 			if(this != &other_Book){
	  				if((strcmp(this->bookTitle.c_str(), other_Book.bookTitle.c_str())) >= 0){
	  					found = true;
	  				}
	  			}
	  		}
	  		return found;
	  	}

	  bool operator==(const BookData& other_Book) const{

	  		bool found = false;
	  		if (this != &other_Book) {
	  			if(this != &other_Book){
	  				if((strcmp(this->bookTitle.c_str(), other_Book.bookTitle.c_str())) == 0){
	  					found = true;
	  				}
	  			}
	  		}
	  		return found;
	  	}

	   bool operator!=(const BookData& other_Book) const{

	  		bool found = false;
	  		if (this != &other_Book) {
	  			if(this != &other_Book){
	 				if((strcmp(this->bookTitle.c_str(), other_Book.bookTitle.c_str())) == 0){
	  					found = true;
	  				}
	  			}
	  		}
	  		return !found;
	  	}

		friend ostream& operator<< (ostream& osObject, const BookData& c)
		{
			osObject << left << setfill(' ')<< " " << setw(29) << c.bookTitle.substr (0,28) <<  setw(11) << c.isbn << setw(15) << c.author.substr(0,14) <<
													  setw(11) << c.publisher.substr (0,14) <<  endl;
			return osObject;
		}

};








#endif /* BOOKDATA_H_ */
