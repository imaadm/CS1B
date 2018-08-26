/*
 * soldBook.h
 *
 *  Created on: Apr 24, 2018
 *      Author: imohammed1
 */

#ifndef SOLDBOOK_H_
#define SOLDBOOK_H_


#include <iostream>
#include <string>
#include "BookData.h"
#include "inventoryBook.h"

using namespace std;

class soldBook: public inventoryBook
{
private:
	double taxRate;
	int qtySold;
	double tax;
	double subTotal;
	double total;
public:

	soldBook(){
		setTaxRate(0);
		setQtySold(0);
		setTax(0);
		subTotal = 0;
		total = 0;
	}

	soldBook(int qtyS,double ta,double subT,double tot, string t, string i, string a, string p, string d, int q, double w, double r):inventoryBook(t, i, a, p, d, q, w, r)
	{
		//setTaxRate(taxR);
		setQtySold(qtyS);
		setTax(ta);
		subTotal = subT;
		total = tot;
	}

	void setTaxRate(double x)
	{
		taxRate = x;
	}

	void setQtySold(int x)
	{
		qtySold = x;
	}

	void setTax(double x)
	{
		tax = x;
	}

	void setSubTotal(double x)
	{
		subTotal = x;
	}

	void setTotal(double x)
	{
		total = x;
	}

	double getTaxRate()
	{
		return taxRate;
	}

	int getQtySold()
	{
		return qtySold;
	}

	double getTax()
	{
		return tax;
	}

	double getSubTotal()
	{
		return subTotal;
	}

	double getTotal()
	{
		return total;
	}

};



#endif /* SOLDBOOK_H_ */
