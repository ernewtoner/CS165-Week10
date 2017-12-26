/*********************************************************************
 ** Author: Eric Newton
 ** Date: 11/30/2017
 ** Description: Patron class implementation file.
 *********************************************************************/
//#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For find()
#include "Patron.hpp"

/*using std::cout;
using std::cin;
using std::endl;*/

using std::string;
using std::vector;
using std::find;


Patron::Patron(string idn, string n)
{
  idNum = idn;
  name = n;

  fineAmount = 0;
}

// uniqueness assumed
string Patron::getIdNum()
{
  return idNum;
}

// cannot be assumed to be unique
string Patron::getName()
{
  return name;
}

// a vector of pointers to LibraryItems that a Patron currently has checked out
vector<LibraryItem*> Patron::getCheckedOutItems()
{
  return checkedOutItems;
}

// adds the specified LibraryItem to checkedOutItems
void Patron::addLibraryItem(LibraryItem* b)
{
  checkedOutItems.push_back(b);
}

//  removes the specified LibraryItem from checkedOutItems
void Patron::removeLibraryItem(LibraryItem* b)
{
  // Erase the element by first finding its index in the vector with std::find then
  // using the vector.erase() function
  checkedOutItems.erase(find(checkedOutItems.begin(), checkedOutItems.end(), b));
}

// how much the Patron owes the Library in late fines (measured in dollars); this is allowed to go negative
double Patron::getFineAmount()
{
  return fineAmount;
}

//  positive argument increases the fineAmount, a negative one decreases it; this is allowed to go negative
void Patron::amendFine(double amount)
{
  fineAmount += amount;
}
