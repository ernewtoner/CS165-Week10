#include "Book.hpp"

#include <string>
using std::string;

//const int Book::CHECK_OUT_LENGTH = 21;

Book::Book(string idc, string t, string auth) : LibraryItem(idc, t)
{
  author = auth;
}

// Overriden getCheckOutLength function
int Book::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}

string Book::getAuthor()
{
  return author;
}
