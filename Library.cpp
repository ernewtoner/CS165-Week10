/*********************************************************************
 ** Author: Eric Newton
 ** Date: 11/30/2017
 ** Description: Library class implementation file.
 *********************************************************************/
//#include <iostream>
#include <string>
#include "Library.hpp"

/*using std::cout;
using std::cin;
using std::endl;*/

using std::string;

Library::Library()
{
  currentDate = 0;
}

void Library::addLibraryItem(LibraryItem* b)
{
  holdings.push_back(b);
}

void Library::addPatron(Patron* p)
{
  members.push_back(p);
}

string Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
  Patron* desiredPatron = getPatron(patronID);
  LibraryItem* desiredLibraryItem = getLibraryItem(ItemID);
  
  // If the Patron is not found
  if (desiredPatron == NULL)
    return "patron not found";
  // Else if the LibraryItem is not found
  else if (desiredLibraryItem == NULL)
    return "item not found";

  // If the LibraryItem is already checked out or on hold by another patron
  if (desiredLibraryItem->getLocation() == CHECKED_OUT)
    return "item already checked out";
  // Else if the LibraryItem is on the hold shelf AND it is not requested by this Patron
  else if ((desiredLibraryItem->getLocation() == ON_HOLD_SHELF) &&
	   (desiredLibraryItem->getRequestedBy() != desiredPatron))
    return "item on hold by other patron";

  // otherwise update the LibraryItem's checkedOutBy, dateCheckedOut and Location;
  desiredLibraryItem->setCheckedOutBy(desiredPatron);
  desiredLibraryItem->setDateCheckedOut(currentDate);
  desiredLibraryItem->setLocation(CHECKED_OUT);

  // if the LibraryItem was on hold for this Patron, update requestedBy;
  if (desiredLibraryItem->getRequestedBy() == desiredPatron)
    desiredLibraryItem->setRequestedBy(NULL);

  // update the Patron's checkedOutItems
  desiredPatron->addLibraryItem(desiredLibraryItem);

  return "check out successful";
  
}

string Library::returnLibraryItem(std::string ItemID)
{
  LibraryItem* itemToReturn = getLibraryItem(ItemID);
  
  if (itemToReturn == NULL)
    return "item not found";

  // If the LibraryItem is not checked out
  if ((itemToReturn->getLocation() == ON_SHELF) || (itemToReturn->getLocation() == ON_HOLD_SHELF))
    return "item already in library";
  
  // update the Patron's checkedOutItems;
  Patron* PatronReturning = itemToReturn->getCheckedOutBy();
  PatronReturning->removeLibraryItem(itemToReturn);
  
  // Check if there is another Patron that has requested this item
  Patron* PatronRequesting = itemToReturn->getRequestedBy();
 
  // If there is a PatronRequesting
  if(PatronRequesting != NULL) {

    // Move the item to the hold shelf
    itemToReturn->setLocation(ON_HOLD_SHELF);
    
    return "return successful";  
  }
  else // Else no one is requesting this item, back to the library shelf
    itemToReturn->setLocation(ON_SHELF);
    
  // update the LibraryItem's checkedOutBy;
  itemToReturn->setCheckedOutBy(NULL);
  
  return "return successful";  
}

string Library::requestLibraryItem(std::string patronID, std::string ItemID)
{
   Patron* PatronRequesting = getPatron(patronID);
   LibraryItem* desiredLibraryItem = getLibraryItem(ItemID);

  // If the item is not in the library
  if (desiredLibraryItem == NULL)
    return "item not found";
  // Or the Patron is not in the library
  else if (PatronRequesting == NULL)
    return "patron not found";

  // If this item has already been requested
  if (desiredLibraryItem->getRequestedBy() != NULL)
    return "item already on hold";

  // Otherwise the item is available to be requested
  // Update its requestedBy
  desiredLibraryItem->setRequestedBy(PatronRequesting);

  // Update its location if it's on the library shelf (not checked out)
  if(desiredLibraryItem->getLocation() == ON_SHELF)
    desiredLibraryItem->setLocation(ON_HOLD_SHELF);

  return "request successful";
}

string Library::payFine(std::string patronID, double payment)
{
  Patron* PatronPaying = getPatron(patronID);

  // If the Patron is not in the library
  if (PatronPaying == NULL)
    return "patron not found";

  // Negate the payment for use with amendFine()
  double negativePayment = (payment * -1);
  
  PatronPaying->amendFine(negativePayment);

  return "payment successful";
}

// stores the current date represented as an integer number of "days" since the Library object was created
// increment current date; increase each Patron's fines by 10 cents for each overdue LibraryItem they have checked out (using amendFine)
void Library::incrementCurrentDate()
{
  // 3 // 11
  // Increment the current date
  currentDate++;
  
  // Search holdings for the LibraryItem's that are overdue
  for (LibraryItem* b : holdings) {    
    // If the item is checked out (can't be overdue if it isn't checked out)
    if (b->getLocation() == CHECKED_OUT) {
      // If the item is overdue
      if ((currentDate - b->getDateCheckedOut()) > b->getCheckOutLength()) {
	// Amend the fine of the Patron it was checked out by
	(b->getCheckedOutBy())->amendFine(.10);
      }
    }
  }
}

//  returns a pointer to the Patron corresponding to the ID parameter, or NULL if no such Patron is a member
Patron* Library::getPatron(std::string patronID)
{
  // Search members for the Patron and return if found
  for (Patron* p : members)
    if (p->getIdNum() == patronID)
      return p;

  // Else return NULL
  return NULL;
}

// returns a pointer to the LibraryItem corresponding to the ID parameter, or NULL if no such LibraryItem is in the holdings
LibraryItem* Library::getLibraryItem(std::string ItemID)
{
  // Search holdings for the LibraryItem and return it if found
  for (LibraryItem* b : holdings)
    if (b->getIdCode() == ItemID)
      return b;
  
  // Else return NULL
  return NULL;
}
