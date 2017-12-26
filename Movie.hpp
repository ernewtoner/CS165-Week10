#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
using std::string;

#include "LibraryItem.hpp"

class Movie : public LibraryItem
{
private:
  string director;
public:
  Movie(string, string, string);
  static const int CHECK_OUT_LENGTH = 7;
  int getCheckOutLength() override;
  string getDirector();
};

#endif
