#include "Library.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  Book b1("123", "War and Peace", "Tolstoy");
  Book b2("234", "Moby Dick", "Melville");
  Book b3("345", "Phantom Tollbooth", "Juster");
  Patron p1("abc", "Felicity");
  Patron p2("bcd", "Waldo");
  Library lib;
  lib.addLibraryItem(&b1);
  lib.addLibraryItem(&b2);
  lib.addLibraryItem(&b3);
  lib.addPatron(&p1);
  lib.addPatron(&p2);

  lib.checkOutLibraryItem("bcd", "234"); // 0 days
  for (int i=0; i<7; i++) // 7 days
    lib.incrementCurrentDate();
  lib.checkOutLibraryItem("bcd", "123"); // 0 days
  lib.checkOutLibraryItem("abc", "345"); // 0 days
  for (int i=0; i<24; i++) // 24 days
    lib.incrementCurrentDate();

  // bcd 31 days on 234 (1.00) and 24 days on 123 (.30)
  // abc 24 days (.30)
  
  // lib.payFine("bcd", 0.4); // bcd goes down to .90
  
  double p1Fine = p1.getFineAmount();
  double p2Fine = p2.getFineAmount();

  cout << p1Fine << endl;
  cout << p2Fine << endl;

  Album a1("222", "War and Peace Album", "Tolstoy");
  Album a2("333", "Moby Dick Album", "Melville");
  Movie m1("444", "Phantom Tollbooth Movie", "Juster");

  lib.addLibraryItem(&a1);
  lib.addLibraryItem(&a2);
  lib.addLibraryItem(&m1);
  
  lib.checkOutLibraryItem("bcd", "222");
  //  lib.checkOutLibraryItem("abc", "444");

  Patron p3("xyz", "John");
  lib.addPatron(&p3);

  lib.checkOutLibraryItem("xyz", "222");
  lib.checkOutLibraryItem("xyz", "222");

  lib.requestLibraryItem("xyz", "444");
  lib.requestLibraryItem("xyz", "444");
  lib.requestLibraryItem("xyz", "444");
  lib.returnLibraryItem("444");
  lib.returnLibraryItem("444");
  lib.returnLibraryItem("444");
  lib.checkOutLibraryItem("xyz", "444");

   lib.returnLibraryItem("222");
   lib.returnLibraryItem("123");
  lib.requestLibraryItem("xyz", "222");
  lib.requestLibraryItem("xyz", "123");
      lib.requestLibraryItem("xyz", "234");
     lib.returnLibraryItem("222");
      lib.requestLibraryItem("xyz", "7777");
	    lib.requestLibraryItem("pxyz", "444");
  
  for (int i=0; i<20; i++) // 20 days
    lib.incrementCurrentDate();

  lib.payFine("xyz", -5000); 
  
  p1Fine = p1.getFineAmount();
  p2Fine = p2.getFineAmount();
  double p3Fine = p3.getFineAmount();
  
  cout << p1Fine << endl;
  cout << p2Fine << endl;
  cout << p3Fine << endl;
}
