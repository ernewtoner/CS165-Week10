/*********************************************************************
 ** Author: Eric Newton
 ** Date: 11/30/2017
 ** Description: LibraryItem class implementation file.
 *********************************************************************/
#include <string>
#include "LibraryItem.hpp"

using std::string;

// Takes an idCode, and title; checkedOutBy and requestedBy should be initialized to NULL; a new LibraryItem should be on the shelf
LibraryItem::LibraryItem(string idc, string t)
{
  checkedOutBy = NULL;
  requestedBy = NULL;
  location = ON_SHELF;
  
  idCode = idc;
  title = t;
}

// uniqueness assumed
string LibraryItem::getIdCode()
{
  return idCode;
}

// cannot be assumed to be unique
string LibraryItem::getTitle()
{
  return title;
}

// a LibraryItem can be either on the shelf, on the hold shelf, or checked out
Locale LibraryItem::getLocation()
{
  return location;
}

void LibraryItem::setLocation(Locale l)
{
  location = l;
}

//  pointer to the Patron who has it checked out (if any)
Patron* LibraryItem::getCheckedOutBy()
{
  return checkedOutBy;
}

void LibraryItem::setCheckedOutBy(Patron* p)
{
  checkedOutBy = p;
}

// pointer to the Patron who has requested it (if any); a LibraryItem can only be requested by one Patron at a time
Patron* LibraryItem::getRequestedBy()
{
  return requestedBy;
}

void LibraryItem::setRequestedBy(Patron* p)
{
  requestedBy = p;
}

//  when a LibraryItem is checked out, this will be set to the currentDate of the Library
int LibraryItem::getDateCheckedOut()
{
  return dateCheckedOut;
}

void LibraryItem::setDateCheckedOut(int date)
{
  dateCheckedOut = date;
}

