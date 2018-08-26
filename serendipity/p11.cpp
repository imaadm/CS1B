// ----------------------------------------------------------------------------------------------------
// File name: p11.cpp
// Project name: cs1b
// ----------------------------------------------------------------------------------------------------
// Creator's name and email: Imaad Mohammed imaadmohammed@gmail.com
// Course-Section: CS 1B
// Creation date: 5/2/2018
// Date of Last Modification: 5/15/2018
// ----------------------------------------------------------------------------------------------------
// Purpose: Serendipity
// ----------------------------------------------------------------------------------------------------
// Algorithim:
// The full serendipity project utilizing linkedlists and classes.
// ----------------------------------------------------------------------------------------------------
//                                              Data Dictionary
// Constants
//
// Name           Data Type            Value
// -------------- -----------          ------------
//
//
// Variables
//
// Name           Data Type            Initial Value
// -------------- -----------          ---------------
// books			orderedLinkedList<inventoryBook>
// qbooks		orderedLinkedList<inventoryBook>
// wbooks		orderedLinkedList<inventoryBook>
// rbooks		orderedLinkedList<inventoryBook>
// soldbook		orderedLinkedList<soldBook>
// choice			int
// inFile		ifStream
// outFile 		ofStream
// bookCount	int
// BookData      class
// inventoryBook  class
// soldBook 	class
// myIterator linkedListIterator
// ----------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include "BookData.h"
#include "InventoryBook.h"
#include "soldBook.h"
#include "windows.h"
using namespace std;

void mainMenu(orderedLinkedList<inventoryBook> &l, orderedLinkedList<inventoryBook> &q, orderedLinkedList<inventoryBook> &w,
		orderedLinkedList<inventoryBook> &r,orderedLinkedList<soldBook> &s, int &bookCount);
void cashier(orderedLinkedList<inventoryBook> &l, orderedLinkedList<inventoryBook> &q, orderedLinkedList<inventoryBook> &w,
		orderedLinkedList<inventoryBook> &r,orderedLinkedList<soldBook> &s, int & bookCount);
void reports(orderedLinkedList<inventoryBook> l, orderedLinkedList<inventoryBook> q, orderedLinkedList<inventoryBook> w,
		orderedLinkedList<inventoryBook> r,orderedLinkedList<soldBook> s, int bookCount);
void repListing(orderedLinkedList<inventoryBook> l, int bookCount);
void repWholesale(orderedLinkedList<inventoryBook> l, int bookCount);
void repRetail(orderedLinkedList<inventoryBook> l, int bookCount);
void repQty(orderedLinkedList<inventoryBook>  l, int bookCount);
void repCost(orderedLinkedList<inventoryBook> l, int bookCount);
void repAge(orderedLinkedList<inventoryBook> l, int bookCount);
void invMenu(orderedLinkedList<inventoryBook> &l, orderedLinkedList<inventoryBook> &q, orderedLinkedList<inventoryBook> &w,
		orderedLinkedList<inventoryBook> &r, orderedLinkedList<soldBook> s, int bookCount);
void addBook(orderedLinkedList<inventoryBook> &l, orderedLinkedList<inventoryBook> &q, orderedLinkedList<inventoryBook> &w,
		orderedLinkedList<inventoryBook> &r, int &bookCount);
void editBook(orderedLinkedList<inventoryBook> &l, orderedLinkedList<inventoryBook> &q, orderedLinkedList<inventoryBook> &w,
		orderedLinkedList<inventoryBook> &r,orderedLinkedList<soldBook> s,int bookCount);
void lookUpBook(orderedLinkedList<inventoryBook> l, int bookCount);
void deleteBook(orderedLinkedList<inventoryBook> &l, orderedLinkedList<inventoryBook> &q, orderedLinkedList<inventoryBook> &w,
		orderedLinkedList<inventoryBook> &r, int &bookCount);

void bookInfo(inventoryBook b);


int main() {
	int bookCount = 0;
	string t;
	string x;
	string i;
	string a;
	string p;
	string d;
	int q;
	double w;
	double r;
	linkedListIterator<inventoryBook> myIterator;
	ifstream inFile;

	orderedLinkedList <inventoryBook> books;
	books.initializeList();

	orderedLinkedList <inventoryBook> qbooks;
	qbooks.initializeList();

	orderedLinkedList <inventoryBook> wbooks;
	wbooks.initializeList();

	orderedLinkedList <inventoryBook> rbooks;
	rbooks.initializeList();


	orderedLinkedList <soldBook> soldbooks;
	soldbooks.initializeList();

	inFile.open("database.txt");
	if(inFile.fail())
	{
		cout << "Error: could not open" << endl;
		inFile.close();
		system("pause");
		system("cls");
		 mainMenu(books, qbooks, wbooks, rbooks, soldbooks,bookCount);
	}

	do
		{
		getline(inFile,t);
	    getline(inFile,i);
	    getline(inFile,a);
	    getline(inFile,p);
	    getline(inFile,d);
		inFile >> q >> w >> r;
	    inventoryBook *newBook = new inventoryBook(t,i,a,p,d,q,w,r);
	    books.insert(*newBook);
	    inventoryBook *newBookq = new inventoryBook(t,i,a,p,d,q,w,r,1);
	    qbooks.insert(*newBookq);
	    inventoryBook *newBookw = new inventoryBook(t,i,a,p,d,q,w,r,2);
	    wbooks.insert(*newBookw);
	    inventoryBook *newBookr = new inventoryBook(t,i,a,p,d,q,w,r,3);
	    rbooks.insert(*newBookr);
	    bookCount++;


		}
		while(getline(inFile,t));



	inFile.close();

	 mainMenu(books,qbooks,wbooks,rbooks,soldbooks,bookCount);

}


void mainMenu(orderedLinkedList<inventoryBook> &list,  orderedLinkedList<inventoryBook> &qlist, orderedLinkedList<inventoryBook> &wlist,
		orderedLinkedList<inventoryBook> &rlist, orderedLinkedList<soldBook> &sales, int &bookCount)
{
	 while(true) {
	        int choice = 0;
	        system("cls");
	        cout << "Serendipity Booksellers" << endl;
	        cout << "      Main Menu" << endl << endl;
	        cout << "1. Cashier Module" << endl;
	        cout << "2. Inventory Database Module" << endl;
	        cout << "3. Report Module" << endl;
	        cout << "4. Exit" << endl << endl;
	        cout << "Enter Your Choice: ";
	        cin >> choice;
	        if(choice < 1 || choice > 4) {
	            cout << "Error: Invalid input." << endl;
	            system("pause");
	            system("cls");
	        } else {
	            switch(choice) {
	                case 1:
	                    cashier(list, qlist,wlist,rlist,sales, bookCount);
	                    break;
	                case 2:
	                    invMenu(list, qlist,wlist,rlist, sales, bookCount);
	                    break;
	                case 3:
	                    reports(list, qlist,wlist,rlist, sales, bookCount);
	                    break;
	                case 4:
	                    exit(0);
	                    break;
	                default:
	                    mainMenu(list,qlist,wlist,rlist,sales,bookCount);
	                    break;
	            }
	        }
	    }
}
void cashier(orderedLinkedList<inventoryBook> &list,  orderedLinkedList<inventoryBook> &qlist, orderedLinkedList<inventoryBook> &wlist,
		orderedLinkedList<inventoryBook> &rlist, orderedLinkedList<soldBook> &sold, int &bookCount)
{
	linkedListIterator<inventoryBook> myIterator;
	linkedListIterator<inventoryBook> myIterator2;
	linkedListIterator<inventoryBook> myIterator3;
	linkedListIterator<inventoryBook> myIterator4;

	linkedListIterator<soldBook> myIteratorS;

	ofstream outFile;
	outFile.open("sold.txt");

	sold.initializeList();

	char date[9];
	//_strdate(date);
	bool buy = false;
	int quantity = 0;
	double subtotal = 0;
	double tax = 0;
	double total = 0;
    bool found = false;
    string search;
    char choice;
    char choice2;
    bool final = false;
    int cq = 0;

    while(buy == false) {
    	system("cls");
        cout << "Serendipity Booksellers\n";
        cout << "  Cashier Module\n\n\n";
        while(final == false) {
        cout << "   >>> Book Purchase <<<" << endl;
        cout << "    Book Title: >";
        cin.clear();
        cin.ignore();
        getline(cin, search);

    	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
            if((*myIterator).getTitle() == search || (*myIterator).getISBN() == search) {
                found = true;
                quantity = 0;
                cout << endl;
                cout << "RESULT>: " << (*myIterator).getTitle() << endl;
                cout << "Purchase this book? (Y/N): ";
                cin >> choice;
                if(choice == 'y' || choice == 'Y') {

                    while (quantity > (*myIterator).getQty() || quantity <= 0) {
                    cout << "How many books would you like to purchase?: ";
                    cin >> quantity;
                    }
                    	subtotal =  quantity * (*myIterator).getRetail();
                    	tax = subtotal * 0.06;
                    	total = subtotal + tax;
                    	cq = ((*myIterator).getQty() - quantity);
                        soldBook *book = new soldBook(quantity, tax, subtotal, total, (*myIterator).getTitle(), (*myIterator).getISBN(), (*myIterator).getAuthor(), (*myIterator).getPub(),
                        		(*myIterator).getDateAdded(), cq, (*myIterator).getWholesale(), (*myIterator).getRetail());
                        sold.insert(*book);

                        outFile << (*myIterator).getTitle() << endl;
                                      outFile << (*myIterator).getISBN() << endl;
                                      outFile << (*myIterator).getAuthor() << endl;
                                      outFile << (*myIterator).getPub() << endl;
                                      outFile << (*myIterator).getDateAdded() << endl;
                                      outFile << cq << endl;
                                      outFile << (*myIterator).getWholesale() << endl;
                                      outFile << (*myIterator).getRetail() << endl;

                        outFile.close();

                        if (cq > 0){
                        inventoryBook *newbook = new inventoryBook((*myIterator).getTitle(), (*myIterator).getISBN(), (*myIterator).getAuthor(), (*myIterator).getPub(),
                        										(*myIterator).getDateAdded(), cq, (*myIterator).getWholesale(), (*myIterator).getRetail(),0);
                        inventoryBook *qnewbook = new inventoryBook((*myIterator).getTitle(), (*myIterator).getISBN(), (*myIterator).getAuthor(), (*myIterator).getPub(),
                        										(*myIterator).getDateAdded(), cq, (*myIterator).getWholesale(), (*myIterator).getRetail(),1);
                        inventoryBook *wnewbook = new inventoryBook((*myIterator).getTitle(), (*myIterator).getISBN(), (*myIterator).getAuthor(), (*myIterator).getPub(),
                        										(*myIterator).getDateAdded(), cq, (*myIterator).getWholesale(), (*myIterator).getRetail(),2);
                        inventoryBook *rnewbook = new inventoryBook((*myIterator).getTitle(), (*myIterator).getISBN(), (*myIterator).getAuthor(), (*myIterator).getPub(),
                        										(*myIterator).getDateAdded(), cq, (*myIterator).getWholesale(), (*myIterator).getRetail(),3);
                        list.deleteNode((*myIterator));
                        list.insert(*newbook);

                    	for (myIterator2 = qlist.begin(); myIterator2 != qlist.end(); ++myIterator2)
                    	{
                            if((*myIterator2).getTitle() == search || (*myIterator2).getISBN() == search)
                    		qlist.deleteNode((*myIterator2));
                    	}
                    	for (myIterator3 = wlist.begin(); myIterator3 != wlist.end(); ++myIterator3)
                    	{
                            if((*myIterator3).getTitle() == search || (*myIterator3).getISBN() == search)
                    		wlist.deleteNode((*myIterator3));
                    	}
                    	for (myIterator4 = rlist.begin(); myIterator4 != rlist.end(); ++myIterator4)
                    	{
                            if((*myIterator4).getTitle() == search || (*myIterator4).getISBN() == search)
                    		rlist.deleteNode((*myIterator4));
                    	}

                        qlist.insert(*qnewbook);
                        wlist.insert(*wnewbook);
                        rlist.insert(*rnewbook);

                        }
                        else
                        {
                        	for (myIterator2 = qlist.begin(); myIterator2 != qlist.end(); ++myIterator2)
                        	{
                                if((*myIterator2).getTitle() == search || (*myIterator2).getISBN() == search)
                        		qlist.deleteNode((*myIterator2));
                        	}
                        	for (myIterator3 = wlist.begin(); myIterator3 != wlist.end(); ++myIterator3)
                        	{
                                if((*myIterator3).getTitle() == search || (*myIterator3).getISBN() == search)
                        		wlist.deleteNode((*myIterator3));
                        	}
                        	for (myIterator4 = rlist.begin(); myIterator4 != rlist.end(); ++myIterator4)
                        	{
                                if((*myIterator4).getTitle() == search || (*myIterator4).getISBN() == search)
                        		rlist.deleteNode((*myIterator4));
                        	}

                            bookCount--;
                        }
                    cout << "Do you want to process another transaction? (Y/N): ";
                    cin >> choice2;
                    if(toupper(choice2) != 'Y') {
                      final = true;
                      system("cls");
                 	 double soldSub = 0;
                	 double soldTax = 0;
                	 double soldTotal = 0;

                      cout << endl;
                      cout << "Serendipity Book Sellers" << endl;
                      cout << "Date: " << date << endl;
                    //  cout << "Time: " << asctime(localtime(&ctt)) << endl;
                      cout << "Qty     ISBN                 Title                      Price      Total"<< endl;
                      cout << "___________________________________________________________________________" << endl;

                      for (myIteratorS = sold.begin(); myIteratorS != sold.end(); ++myIteratorS)
                      {
                    	 // if (((*myIterator2).getTotal() > 0) && ((*myIterator2).getTotal() < 100000))
                    	  //{
                    		  soldSub += (*myIteratorS).getSubTotal();
                    		  soldTax += (*myIteratorS).getTax();
                    		  soldTotal += (*myIteratorS).getTotal();
                    	  //}
                      cout << (*myIteratorS).getQtySold() << "\t";
                      cout << left << setw(15) << (*myIteratorS).getISBN() << "   ";
                      cout << left << setw(25) << (*myIteratorS).getTitle() << "  $ ";
                      cout << fixed << showpoint << right << setprecision(2);
                      cout << setw(6) << (*myIteratorS).getRetail()<< "   $ ";
                      cout << setw(6) << (*myIteratorS).getSubTotal();
                      cout << endl;
                      }
                      cout << endl;
                      cout << endl;

                      cout << "                 Subtotal                                       $ ";
                      cout << setw(6) << soldSub << endl;
                      cout << "                 Tax                                            $ ";
                      cout << setw(6) << soldTax << endl;
                      cout << "                 Total                                          $ ";
                      cout << setw(6) << soldTotal << endl;
                      cout << endl;
                      cout << "Thank you for shopping at Serendipity!" << endl;
                      system("pause");
                      mainMenu(list,qlist,wlist,rlist,sold,bookCount);
                    }
                        else {
                          system("cls");
                          break;
                          continue;
                        }

                }
                else
                  mainMenu(list,qlist,wlist,rlist,sold,bookCount);

            }
        }
        if(!found) {
            cout << endl;
            cout << "No book found." << endl;
            system("pause");
            system("cls");
            mainMenu(list,qlist,wlist,rlist,sold,bookCount);

        	}
        }
    }
}

void invMenu(orderedLinkedList<inventoryBook> &list, orderedLinkedList<inventoryBook> &qlist, orderedLinkedList<inventoryBook> &wlist,
		orderedLinkedList<inventoryBook> &rlist, orderedLinkedList<soldBook> sold, int bookCount)
{
    int choice = 0;
    while(true) {
        system("cls");
        cout << "\nSerendipity Booksellers\n";
        cout << "  Inventory Database\n\n\n";
        cout <<    "1.  Look Up a Book\n";
        cout << "2.  Add a Book\n";
        cout << "3.  Edit a Book's Record\n";
        cout << "4.  Delete a Book\n";
        cout << "5.  Return to the Main Menu\n\n\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        if(choice < 1 || choice > 5) {
            cout << "\nPlease enter a number in the range 1-5." << endl;
            system("pause");
            system("cls");
        } else {
            switch(choice) {
                case 1:
                    lookUpBook(list, bookCount);
                    break;
                case 2:
                    addBook(list, qlist,wlist,rlist, bookCount);
                    break;
                case 3:
                    editBook(list,qlist,wlist,rlist, sold, bookCount);
                    break;
                case 4:
                    deleteBook(list,qlist,wlist,rlist, bookCount);
                    break;
                case 5:
                    mainMenu(list,qlist,wlist,rlist,sold,bookCount);
                    break;
                default:
                    break;
            }
        }
    }
}


void reports(orderedLinkedList<inventoryBook> list, orderedLinkedList<inventoryBook> qlist, orderedLinkedList<inventoryBook> wlist,
		orderedLinkedList<inventoryBook> rlist, orderedLinkedList<soldBook> sold, int bookCount) {

	while(true) {
    system("cls");
    int choice = 0;
    cout << "Serendipity Booksellers\n";
    cout << "        Reports\n\n\n";
    cout <<    "1. Inventory Listing\n";
    cout << "2. Inventory Wholesale Value\n";
    cout << "3. Inventory Retail Value\n";
    cout << "4. Listing by Quantity\n";
    cout << "5. Listing by Cost\n";
    cout << "6. Listing by Age\n";
    cout << "7. Return to Main Menu\n\n\n";
    cout << "Enter Your Choice:";
    cin >> choice;
    if(choice < 1 || choice > 7) {
        cout << "\nPlease enter a number in the range 1-7." << endl;
        system("pause");
        system("cls");
    }
    else {
        switch(choice) {
            case 1:
            	system("cls");
    			cout << "Book Listings | Current Book Count: " << bookCount << " | Page 1" << endl;
            	cout << "Title                                ISBN           Author        Publisher          Date      Quantity  Wholesale  Retail"<< endl;
            	cout << "__________________________________________________________________________________________________________________________"<< endl;
                repListing(list, bookCount);
                system("pause");
                break;
            case 2:
            	system("cls");
    			cout << "Wholesale Listings | Current Book Count: " << bookCount << " | Page 1" << endl;
    			cout << "Title                                          ISBN        Quantity    Wholesale"<< endl;
    			cout << "________________________________________________________________________________"<< endl;
            	repWholesale(wlist, bookCount);
            	system("pause");
                break;
            case 3:
            	system("cls");
    			cout << "Retail Listings | Current Book Count: " << bookCount << " | Page 1" << endl;
            	cout << "Title                                         ISBN        Quantity       Retail"<< endl;
            	cout << "_______________________________________________________________________________"<< endl;
            	repRetail(rlist, bookCount);
            	system("pause");
                break;
            case 4:
            	system("cls");
    			cout << "Quantity Listings | Current Book Count: " << bookCount << " | Page 1" << endl;
	          	cout << "Title                                         ISBN         Quantity"<< endl;
	          	cout << "___________________________________________________________________"<< endl;

            	repQty(qlist, bookCount);
            	system("pause");
                break;
            case 5:
            	system("cls");
    			cout << "Cost Listings | Current Book Count: " << bookCount << " | Page 1" << endl;
            	cout << "Title                                          ISBN        Quantity    Wholesale"<< endl;
            	cout << "________________________________________________________________________________"<< endl;
        		repCost(wlist, bookCount);
        		system("pause");
                break;
            case 6:
            	system("cls");
    			cout << "Age Listings | Current Book Count: " << bookCount << " | Page 1" << endl;
    			cout << "Title                                        ISBN         Quantity     Date Added"<< endl;
    			cout << "_________________________________________________________________________________"<< endl;
            	repAge(list, bookCount);
        		system("pause");
                break;
            case 7:
            	mainMenu(list,qlist,wlist,rlist,sold,bookCount);
            	break;
            default:
            	break;
        }
    }
	}
}


void addBook(orderedLinkedList<inventoryBook> &list, orderedLinkedList<inventoryBook> &qlist, orderedLinkedList<inventoryBook> &wlist,
		orderedLinkedList<inventoryBook> &rlist,int &bookCount) {

	ofstream outFile;
	outFile.open("database.txt");
    string currentTitle = "EMPTY";
    string currentIsbn = "EMPTY";
    string currentAuthor = "EMPTY";
    string currentPublisher = "EMPTY";
    string currentDate = "EMPTY";
    int currentQty = 0;
    double currentWholesale = 0;
    double currentRetail = 0;
    while(true) {
        system("cls");
        int choice;
        cout << setw(80) << setfill('*') << "" << endl;
        cout << "*" <<  setw(50) << right << setfill(' ') << "SERENDIPITY BOOKSELLERS" << setw(29) << "*" << endl;
        cout << "*" <<  setw(43) << right << setfill(' ') << "ADD BOOK" << setw(36) << "*" << endl;
        cout << "*" << setw(79) << right << "*" << endl;
        cout << "*" << setw(33) << right << " CURRENT BOOK COUNT:  " << setw(2) << bookCount << setw(44) << "*" << endl;
        cout << "*" << setw(79) << right << "*" << endl;
        cout << "*" << setw(69) << right << "                " << setw(10) << right << "*" << endl;
        cout << "* <1> Enter Book Title              >  --" << setw(38) << left << currentTitle.substr(0,38) << "*" << endl;
        cout << "* <2> Enter ISBN                    >  --" << setw(38) << left << currentIsbn << "*" << endl;
        cout << "* <3> Enter Author                  >  --" << setw(38) << left << currentAuthor << "*" << endl;
        cout << "* <4> Enter Publisher               >  --" << setw(38) << left << currentPublisher << "*" << endl;
        cout << "* <5> Enter Date Added (mm/dd/yyyy) >  --" << setw(38) << left << currentDate << "*" << endl;
        cout << "* <6> Enter Quantity on Hand        >  --" << setw(38) << left << currentQty << "*" << endl;
        cout << "* <7> Enter Wholesale Cost          >  --$" << setw(37) << left << setprecision(2) << fixed << currentWholesale << "*" << endl;
        cout << "* <8> Enter Retail Price            >  --$" << setw(37) << left << setprecision(2) << fixed << currentRetail << "*" << endl;
        cout << "* <9> Save Book To Database              " << setw(39) << right << "*" << endl;
        cout << "* <0> Return to Inventory Menu           " << setw(39) << right << "*" << endl;
        cout << "*" << setw(79) << right << "*" << endl;
        cout << setw(80) << setfill('*') << "" << endl;
        cout << setw(20) << setfill(' ') << right << "Choice<0-9>:";
        cin >> choice;
        string input;
        int inputInt;
        double inputDouble;
        switch(choice) {
            case 1:

                cout << "Enter value: ";
                cin.ignore();
                getline(cin, input);
                currentTitle = input;
                break;
            case 2:
                cout << "Enter value: ";
                cin.ignore();
                getline(cin, input);
                currentIsbn = input;
                break;
            case 3:
                cout << "Enter value: ";
                cin.ignore();
                getline(cin, input);
                currentAuthor = input;
                break;
            case 4:
                cout << "Enter value: ";
                cin.ignore();
                getline(cin, input);
                currentPublisher = input;
                break;
            case 5:
                cout << "Enter value: ";
                cin.ignore();
                getline(cin, input);
                currentDate = input;
                break;
            case 6:
                cout << "Enter value: ";
                cin >> inputInt;
                currentQty = inputInt;
                break;
            case 7:
                cout << "Enter value: ";
                cin >> inputDouble;
                currentWholesale = inputDouble;
                break;
            case 8:
                cout << "Enter value: ";
                cin >> inputDouble;
                currentRetail = inputDouble;
                break;
            case 9:{

                inventoryBook *newbook = new inventoryBook(currentTitle, currentIsbn, currentAuthor, currentPublisher,
                										currentDate,currentQty,currentWholesale,currentRetail, 0);
                inventoryBook *newbookq = new inventoryBook(currentTitle, currentIsbn, currentAuthor, currentPublisher,
                										currentDate,currentQty,currentWholesale,currentRetail, 1);
                inventoryBook *newbookw = new inventoryBook(currentTitle, currentIsbn, currentAuthor, currentPublisher,
                										currentDate,currentQty,currentWholesale,currentRetail, 2);
                inventoryBook *newbookr = new inventoryBook(currentTitle, currentIsbn, currentAuthor, currentPublisher,
                										currentDate,currentQty,currentWholesale,currentRetail, 3);
                list.insert(*newbook);
                qlist.insert(*newbookq);
                wlist.insert(*newbookw);
                rlist.insert(*newbookr);

                outFile << currentTitle << endl;
                outFile << currentIsbn << endl;
                outFile << currentAuthor << endl;
                outFile << currentPublisher << endl;
                outFile << currentDate << endl;
                outFile << currentQty << endl;
                outFile << currentWholesale << endl;
                outFile << currentRetail << endl;

                bookCount++;
                currentTitle = "EMPTY";
                currentIsbn = "EMPTY";
                currentAuthor = "EMPTY";
                currentPublisher = "EMPTY";
                currentDate = "EMPTY";
                currentQty = 0;
                currentWholesale = 0;
                currentRetail = 0;
                break;
            }
            case 0:
                outFile.close();
                return;
            default:
                break;
        }
    }
}

void editBook(orderedLinkedList<inventoryBook> &list, orderedLinkedList<inventoryBook> &qlist, orderedLinkedList<inventoryBook> &wlist,
		orderedLinkedList<inventoryBook> &rlist, orderedLinkedList<soldBook> sold, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
    system("cls");
    bool found = false;
    string searchString;

    cout << setw(80) << setfill('*') << "" << endl;
    cout << "*" <<  setw(50) << right << setfill(' ') << "SERENDIPITY BOOKSELLERS" << setw(29) << "*" << endl;
    cout << "*" <<  setw(43) << right << setfill(' ') << "EDIT BOOK" << setw(36) << "*" << endl;
    cout << "*" << setw(79) << right << "*" << endl;
    cout << "*" << setw(33) << right << " CURRENT BOOK COUNT:  " << setw(2) << bookCount << setw(20) << right << endl;
    cout << "*" << setw(79) << right << "*" << endl;
    cout << setw(80) << setfill('*') << "" << endl;
    cout << "    Search: >";
    cin.ignore();
    getline(cin, searchString);
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
        if((*myIterator).getTitle() == searchString || (*myIterator).getISBN() == searchString) {
            found = true;
            char choice;
            cout << endl;
            cout << "RESULT>: " << (*myIterator).getTitle() << endl;
            cout << "View this book record? (Y/N): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y') {
                bookInfo((*myIterator));
                system("pause");
                cout << "Is this the book you want to EDIT? (Y/N): ";
                cin >> choice;
                if(choice == 'y' || choice == 'Y') {
                    string currentTitle = (*myIterator).getTitle();
                    string currentIsbn = (*myIterator).getISBN();
                    string currentAuthor = (*myIterator).getAuthor();
                    string currentPublisher = (*myIterator).getPub();
                    string currentDate =(*myIterator).getDateAdded();
                    int currentQty = (*myIterator).getQty();
                    double currentWholesale = (*myIterator).getWholesale();
                    double currentRetail = (*myIterator).getRetail();
                    while(true) {
                        cout << setw(80) << setfill('*') << "" << endl;
                        cout << "*" <<  setw(50) << right << setfill(' ') << "SERENDIPITY BOOKSELLERS" << setw(29) << "*" << endl;
                        cout << "*" <<  setw(43) << right << setfill(' ') << "EDIT BOOK" << setw(35) << "*" << endl;
                        cout << "*" << setw(79) << right << "*" << endl;
                        cout << "*" << setw(33) << right << " CURRENT BOOK COUNT:  " << setw(2) << bookCount << setw(20) << right << "*" << endl;
                        cout << "*" << setw(79) << right << "*" << endl;
                        cout << "*" << setw(69) << right << "               " << setw(10) << right << "*" << endl;
                        cout << "* <1> Enter Book Title              >  --" << setw(38) << left << (*myIterator).getTitle() << "*" << endl;
                        cout << "* <2> Enter ISBN                    >  --" << setw(38) << left << (*myIterator).getISBN() << "*" << endl;
                        cout << "* <3> Enter Author                  >  --" << setw(38) << left << (*myIterator).getAuthor() << "*" << endl;
                        cout << "* <4> Enter Publisher               >  --" << setw(38) << left << (*myIterator).getPub() << "*" << endl;
                        cout << "* <5> Enter Date Added (mm/dd/yyyy) >  --" << setw(38) << left << (*myIterator).getDateAdded() << "*" << endl;
                        cout << "* <6> Enter Quantity on Hand        >  --" << setw(38) << left << (*myIterator).getQty() << "*" << endl;
                        cout << "* <7> Enter Wholesale Cost          >  --$" << setw(37) << left << setprecision(2) << fixed << (*myIterator).getWholesale() << "*" << endl;
                        cout << "* <8> Enter Retail Price            >  --$" << setw(37) << left << setprecision(2) << fixed << (*myIterator).getRetail() << "*" << endl;
                        cout << "* <9> Return to Inventory Menu           " << setw(39) << right << "*" << endl;
                        cout << "*" << setw(79) << right << "*" << endl;
                        cout << setw(80) << setfill('*') << "" << endl;
                        cout << setw(20) << setfill(' ') << right << "Choice<1-9>:";
                        string inputT = (*myIterator).getTitle();
                        string inputI = (*myIterator).getISBN();
                        string inputA = (*myIterator).getAuthor();
                        string inputP = (*myIterator).getPub();
                        string inputD =(*myIterator).getDateAdded();
                        int inputQ = (*myIterator).getQty();
                        double inputW = (*myIterator).getWholesale();
                        double inputR = (*myIterator).getRetail();
                        int choiceInt, inputInt;
                        double inputDouble;
                        cin >> choiceInt;
                        switch(choiceInt) {
                            case 1:
                                cout << "Enter value: ";
                                cin.ignore();
                                getline(cin, inputT);
                                currentTitle = inputI;
                                break;
                            case 2:
                                cout << "Enter value: ";
                                cin.ignore();
                                getline(cin, inputI);
                                currentIsbn = inputI;
                                break;
                            case 3:
                                cout << "Enter value: ";
                                cin.ignore();
                                getline(cin, inputA);
                                currentAuthor = inputA;
                                break;
                            case 4:
                                cout << "Enter value: ";
                                cin.ignore();
                                getline(cin, inputP);
                                currentPublisher = inputP;
                                break;
                            case 5:
                                cout << "Enter value: ";
                                cin.ignore();
                                getline(cin, inputD);
                                currentDate = inputD;
                                break;
                            case 6:
                                cout << "Enter value: ";
                                cin >> inputQ;
                                currentQty = inputQ;
                                break;
                            case 7:
                                cout << "Enter value: ";
                                cin >> inputW;
                                currentWholesale = inputW;
                                break;
                            case 8:
                                cout << "Enter value: ";
                                cin >> inputR;
                                currentRetail = inputR;
                                break;
                            case 9:{
                            	list.deleteNode((*myIterator));
                            	inventoryBook *book = new inventoryBook(currentTitle,currentIsbn,currentAuthor,currentPublisher,currentDate,currentQty,currentWholesale,currentRetail, 0);
                            	inventoryBook *qbook = new inventoryBook(currentTitle,currentIsbn,currentAuthor,currentPublisher,currentDate,currentQty,currentWholesale,currentRetail,1);
                            	inventoryBook *wbook = new inventoryBook(currentTitle,currentIsbn,currentAuthor,currentPublisher,currentDate,currentQty,currentWholesale,currentRetail,2);
                            	inventoryBook *rbook = new inventoryBook(currentTitle,currentIsbn,currentAuthor,currentPublisher,currentDate,currentQty,currentWholesale,currentRetail,3);

                            	list.insert(*book);
                            	qlist.insert(*qbook);
                            	wlist.insert(*wbook);
                            	rlist.insert(*rbook);

                                mainMenu(list,qlist,wlist,rlist,sold,bookCount);
                                break;
                            }
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
    if(!found) {
        cout << endl;
        cout << "No book found." << endl;
        system("pause");
    }

}

void deleteBook(orderedLinkedList<inventoryBook> &list, orderedLinkedList<inventoryBook> &qlist, orderedLinkedList<inventoryBook> &wlist,
		orderedLinkedList<inventoryBook> &rlist,int &bookCount) {
	ifstream bookFile;

    linkedListIterator<inventoryBook> myIterator;
    linkedListIterator<inventoryBook> myIterator2;
    linkedListIterator<inventoryBook> myIterator3;
    linkedListIterator<inventoryBook> myIterator4;

	while(true) {
        system("cls");
        bool found = false;
        string searchString;
        cout << setw(80) << setfill('*') << "" << endl;
        cout << "*" <<  setw(50) << right << setfill(' ') << "SERENDIPITY BOOKSELLERS" << setw(29) << "*" << endl;
        cout << "*" <<  setw(43) << right << setfill(' ') << "DELETE BOOK" << setw(36) << "*" << endl;
        cout << "*" << setw(79) << right << "*" << endl;
        cout << "*" << setw(33) << right << " CURRENT BOOK COUNT:  " << setw(2) << bookCount << setw(20) << right << endl;
        cout << "*" << setw(79) << right << "*" << endl;
        cout << setw(80) << setfill('*') << "" << endl;
        cout << "    Search: >";
        cin.ignore();
        getline(cin, searchString);
    	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
            if(((*myIterator).getTitle().find(searchString) != string::npos) || ((*myIterator).getISBN().find(searchString) != string::npos)) {
                found = true;
                char choice;
                cout << endl;
                cout << "RESULT>: " << (*myIterator).getTitle() << endl;
                cout << "View this book record? (Y/N): ";
                cin >> choice;
                if(choice == 'y' || choice == 'Y') {
                    bookInfo((*myIterator));
                    system("pause");
                    cout << "Is this the book you want to DELETE? (Y/N): ";
                    cin >> choice;
                    if(choice == 'y' || choice == 'Y') {
                            list.deleteNode((*myIterator));
                            for (myIterator2 = qlist.begin(); myIterator2 != qlist.end(); ++myIterator2)
                        	{
                                if((*myIterator2).getTitle() == searchString || (*myIterator2).getISBN() == searchString)
                        		qlist.deleteNode((*myIterator2));
                        	}
                        	for (myIterator3 = wlist.begin(); myIterator3 != wlist.end(); ++myIterator3)
                        	{
                                if((*myIterator3).getTitle() == searchString || (*myIterator3).getISBN() == searchString)
                        		wlist.deleteNode((*myIterator3));
                        	}
                        	for (myIterator4 = rlist.begin(); myIterator4 != rlist.end(); ++myIterator4)
                        	{
                                if((*myIterator4).getTitle() == searchString || (*myIterator4).getISBN() == searchString)
                        		rlist.deleteNode((*myIterator4));
                        	}

                        bookCount--;
                        cout << "Book Deleted." << endl;
                        system("pause");
                        cout << "Delete Another? (Y/N)";
                        cin >> choice;
                        if(choice != 'Y' && choice != 'y')
                            return;

                    }
                }
            }
        }
        if(!found) {
            cout << "Book not found." << endl;
            return;
        }
    }
}



void lookUpBook(orderedLinkedList<inventoryBook> list, int bookCount) {
    linkedListIterator<inventoryBook> myIterator;
	bool found = false;
    string searchString;
    cout << "   >>> BOOK LOOK UP <<<" << endl;
    cout << "    Search: >";
    cin.ignore();
    getline(cin, searchString);
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
    	if((*myIterator).getTitle() == searchString || (*myIterator).getISBN() == searchString) {
            found = true;
            char choice;
            cout << endl;
            cout << "RESULT>: " << (*myIterator).getTitle() << endl;
            cout << "View this book record? (Y/N): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y') {
                bookInfo((*myIterator));
                system("pause");
            }
            else
                continue;
        }
    }
    if(!found) {
        cout << endl;
        cout << "No book found." << endl;
        system("pause");
    }
}

void bookInfo(inventoryBook book)
{
    cout << "    Serendipity Booksellers\n";
    cout << "          Book Information\n\n\n";
    cout << "ISBN: " << book.getISBN() << endl;
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "Publisher: " << book.getPub() << endl;
    cout << "Date Added: " << book.getDateAdded() << endl;
    cout << "Quantity-On-Hand: " << book.getQty() << endl;
    cout << "Wholesale Cost: " << book.getWholesale() << endl;
    cout << "Retail Price: " << book.getRetail() << endl;

}


void repListing(orderedLinkedList<inventoryBook> list, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
	int count = 0;
	int page = 2;
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
		   cout << left << "  " << setw(29) << (*myIterator).getTitle().substr(0,29)
						<< "  " << setw(12) << (*myIterator).getISBN()
						<< "  " << setw(15) << (*myIterator).getAuthor().substr(0,13)
						<< "  " << setw(15) << (*myIterator).getPub().substr(0,12)
						<< "  " << setw(13) << (*myIterator).getDateAdded().substr(0,13)
						<< "  " << setw(6) << (*myIterator).getQty()
						<< "$" << setw(10) << (*myIterator).getWholesale()
					    << "  $" << setw(10) <<  (*myIterator).getRetail() << endl << endl;
		count++;
		if(count == 14){
			system("pause");
			system ("cls");
			cout << "Book Listings | Current Book Count: " << bookCount << " | Page " << page << endl;
			cout << "Title                                     ISBN           Author        Publisher          Date      Quantity  Wholesale  Retail"<< endl;
			cout << "__________________________________________________________________________________________________________________________"<< endl;
			count = 0;
			page++;
		}

	}
}

void repWholesale(orderedLinkedList<inventoryBook> list, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
	int count = 0;
	int page = 2;
	double sum = 0;
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
		   cout << left << "  " << setw(39) << (*myIterator).getTitle().substr(0,39)
						<< "  " << setw(16) << (*myIterator).getISBN()
						<< "  " << setw(11) << (*myIterator).getQty()
						<< "$" << setw(10) << (*myIterator).getWholesale() << endl << endl;
		count++;
		sum += ((*myIterator).getQty()*(*myIterator).getWholesale());
		if(count == 14){
			system("pause");
			system ("cls");
			cout << "Wholesale Listings | Current Book Count: " << bookCount << " | Page " << page << endl;
			cout << "Title                                          ISBN        Quantity    Wholesale"<< endl;
			cout << "________________________________________________________________________________"<< endl;
			count = 0;
			page++;
		}

	}
	cout << endl;
	cout << "Total Wholesale Value: $" << sum << endl;

}

void repRetail(orderedLinkedList<inventoryBook> list, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
	int count = 0;
	int page = 2;
	double sum = 0;
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
		cout << left << "  " << setw(40) << (*myIterator).getTitle().substr(0,40)
			 << "  " << setw(15) << (*myIterator).getISBN()
			 << "  " << setw(10) << (*myIterator).getQty()
			 << "$" << setw(10) << (*myIterator).getRetail()
			 << endl << endl;
		count++;
		sum += ((*myIterator).getQty()*(*myIterator).getRetail());
		if(count == 14){
			system("pause");
			system ("cls");
			cout << "Retail Listings | Current Book Count: " << bookCount << " | Page " << page << endl;
        	cout << "Title                                         ISBN        Quantity       Retail"<< endl;
        	cout << "_______________________________________________________________________________"<< endl;
			count = 0;
			page++;
		}

	}
	cout << endl;
	cout << "Total Retail Value: $" << sum << endl;

}

void repQty(orderedLinkedList<inventoryBook> list, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
	int count = 0;
	int page = 2;
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
		cout << left << "  " << setw(40) << (*myIterator).getTitle().substr(0,40)
				<< "  " << setw(15) << (*myIterator).getISBN()
				<< "  " << setw(10) << (*myIterator).getQty() << endl << endl;
		count++;
		if(count == 14){
			system("pause");
			system ("cls");
			cout << "Quantity Listings | Current Book Count: " << bookCount << " | Page " << page << endl;
          	cout << "Title                                         ISBN         Quantity"<< endl;
          	cout << "___________________________________________________________________"<< endl;
			count = 0;
			page++;
		}


	}

}

void repCost(orderedLinkedList<inventoryBook> list, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
	int count = 0;
	int page = 2;
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
		   cout << left << "  " << setw(39) << (*myIterator).getTitle().substr(0,39)
								<< "  " << setw(16) << (*myIterator).getISBN()
								<< "  " << setw(11) << (*myIterator).getQty()
								<< "$" << setw(10) << (*myIterator).getWholesale() << endl << endl;
		count++;
		if(count == 14){
			system("pause");
			system ("cls");
			cout << "Cost Listings | Current Book Count: " << bookCount << " | Page " << page << endl;
			cout << "Title                                          ISBN        Quantity    Wholesale"<< endl;
			cout << "________________________________________________________________________________"<< endl;
			count = 0;
			page++;
		}

	}

}

void repAge(orderedLinkedList<inventoryBook> list, int bookCount) {
	linkedListIterator<inventoryBook> myIterator;
	int count = 0;
	int page = 2;
	for (myIterator = list.begin(); myIterator != list.end(); ++myIterator) {
		cout << left << setfill(' ') << "  " << setw(19) << (*myIterator).getTitle().substr(0,19) << "  "
			 << setw(11) << (*myIterator).getISBN().substr(0,11) << "  "
			 << setw(9) << (*myIterator).getQty() << setw(7) << (*myIterator).getDateAdded() << endl << endl;
		count++;
		if(count == 14){
			system("pause");
			system ("cls");
			cout << "Date Listings | Current Book Count: " << bookCount << " | Page " << page << endl;
			cout << "Title                                        ISBN         Quantity     Date Added"<< endl;
			cout << "_________________________________________________________________________________"<< endl;
			count = 0;
			page++;
		}

	}

}

