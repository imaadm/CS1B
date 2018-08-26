/*
 * inventoryBook.h
 *
 *  Created on: Apr 24, 2018
 *      Author: imohammed1
 */

#ifndef INVENTORYBOOK_H_
#define INVENTORYBOOK_H_


#include <iostream>
#include <string>
#include "BookData.h"

using namespace std;

class inventoryBook: public BookData
{
private:

	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
	int sortCode;
public:
	/**********************CONSTRUCTORS*****************/


	inventoryBook()
	{
		setDateAdded("not set");
		setQty(0);
		setWholesale(0);
		setRetail(0);

	}

	inventoryBook(string t, string i, string a, string p, string d, int q, double w, double r):BookData(t, i, a, p)
		{
			setDateAdded(d);
			setQty(q);
			setWholesale(w);
			setRetail(r);
		}

	inventoryBook(string t, string i, string a, string p, string d, int q, double w, double r, int s):BookData(t, i, a, p)
	{
		setDateAdded(d);
		setQty(q);
		setWholesale(w);
		setRetail(r);
		setSortCode(s);
	}

	//GETTERS


	string getDateAdded() const
	{
		return dateAdded;
	}

	int getQty()
	{
		return qtyOnHand;
	}

	double getWholesale()
	{
		return wholesale;
	}

	double getRetail()
	{
		return retail;
	}

	bool isEmpty()
	{
		if (qtyOnHand <= 0)
			return false;
		else
			return true;
	}

	void setDateAdded(string x)
	{
		dateAdded = x;
	}

	void setQty(int x)
	{
		qtyOnHand = x;
	}

	void setSortCode(int x)
	{
		sortCode = x;
	}

	void setWholesale(double x)
	{
		wholesale = x;
	}

	void setRetail(double x)
	{
		retail = x;
	}

	void print()
	{
		BookData:print();
		cout << getDateAdded() << endl;
		cout << getQty() << endl;
		cout << getWholesale() << endl;
		cout << getRetail() << endl;
	}

	friend ostream& operator<< (ostream& is, inventoryBook &b)
	{
		string title = b.getTitle();
		string ISBN = b.getISBN();
		string author = b.getAuthor();
		string publisher = b.getPub();
		string dateAdded = b.getDateAdded();
		int qtyOnHand = b.getQty();
		double wholesale = b.getWholesale();
		double retail = b.getRetail();
		is << title;
		is << ISBN;
		is << author;
		is << publisher;
		is << dateAdded;
		is << qtyOnHand;
		is << wholesale;
		is << wholesale;
		is << retail;
	}

	friend istream& operator>> (istream& is, inventoryBook &b)
	{
		string title = b.getTitle();
		string ISBN = b.getISBN();
		string author = b.getAuthor();
		string publisher = b.getPub();
		string dateAdded = b.getDateAdded();
		int qtyOnHand = b.getQty();
		double wholesale = b.getWholesale();
		double retail = b.getRetail();
		is >> title;
		is >> ISBN;
		is >> author;
		is >> publisher;
		is >> dateAdded;
		is >> qtyOnHand;
		is >> wholesale;
		is >> wholesale;
		is >> retail;
	}

	bool operator>=(const inventoryBook& other_Book) const{
		  		bool found = false;
		  		string temp1 = this->getTitle();
		  		string temp2 = other_Book.getTitle();
		  		string temp3 = this->getDateAdded();
		  		string temp4 = other_Book.getDateAdded();

		  		switch (other_Book.sortCode) {

		  		case 0:
		  			if (temp1.compare(temp2) >= 0)
		  				found = true;
		  			break;
		  		  case 1: //qtyOnHand
		  					if((this->qtyOnHand <= other_Book.qtyOnHand) )
		  						found = true;
			  			break;

		  		  case 2:
			  				  if((this->wholesale <= other_Book.wholesale) )
			  				  	found = true;
			  			 break;
		  		 case 3:
		  					  if((this->retail <= other_Book.retail) )
		  					  	found = true;
		  				 break;
		  		case 4:
		  				  	if((temp3.compare(temp4) >= 0) )
		  				  	   found = true;
		  				  break;
		  		}
		  	return found;
	}

	  bool operator==(const inventoryBook& other_Book) const{
		  string temp1 = this->getTitle();
		  string temp2 = other_Book.getTitle();
		  string temp3 = this->getDateAdded();
		  string temp4 = other_Book.getDateAdded();
	  		bool found = false;

	  		switch (other_Book.sortCode) {
	  						case 0:
	  									if (temp1.compare(temp2) == 0)
	  										found = true;
	  									break;
	  				  		 case 1:
	  				  					if((this->qtyOnHand == other_Book.qtyOnHand) )
	  				  						found = true;
	  					  	  		break;

	  				  		 case 2:
	  				  				  if((this->wholesale == other_Book.wholesale) )
	  				  				  	found = true;
	  				  				 break;
	  				  		 case 3:
	  				  			  	if((this->retail == other_Book.retail) )
	  				  			  		found = true;
	  				  			  	 break;
	  				  		case 4:
	  				  			  	if((temp3.compare(temp4) == 0) )
	  				  			  		found = true;
	  				  			  	break;
	  		}
	  		return found;
	  	}

	   bool operator!=(const inventoryBook& other_Book) const{
			  string temp1 = this->getTitle();
			  string temp2 = other_Book.getTitle();
			  string temp3 = this->getDateAdded();
			  string temp4 = other_Book.getDateAdded();
	  		bool found = false;

	  		switch (other_Book.sortCode) {
	  						case 0:
	  			  				if (temp1.compare(temp2) == 0)
	  			  						found = true;
	  			  				break;
	  				  		  case 1:
	  				  					if((this->qtyOnHand == other_Book.qtyOnHand) )
	  				  						found = true;
	  				  			break;
	  				  		  case 2:
	  				  				  	if((this->wholesale == other_Book.wholesale) )
	  				  				  		found = true;

	  				  			break;
	  				  		 case 3:
	  				  			  		if((this->retail == other_Book.retail) )
	  				  			         found = true;
	  				  			   break;
	  				  		case 4:
	  				  			  		if((temp3.compare(temp4) == 0) )
	  				  			  	    found = true;
	  				  			  	 break;
	  			}

	  		return !found;
	  	}

};



#endif /* INVENTORYBOOK_H_ */
