#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using std::string;

#include "LibraryItem.hpp"

class Book : public LibraryItem
{
private:
  string author;
public:
  Book(string, string, string);
  static const int CHECK_OUT_LENGTH = 21;
  int getCheckOutLength() override;
  string getAuthor();
};

#endif
