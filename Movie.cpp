#include "Movie.hpp"

#include <string>
using std::string;

//const int Movie::CHECK_OUT_LENGTH = 7;

Movie::Movie(string idc, string t, string dir) : LibraryItem(idc, t)
{
  director = dir;
}

// Overriden getCheckOutLength function
int Movie::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}

string Movie::getDirector()
{
  return director;
}
