#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
using std::string;

#include "LibraryItem.hpp"

class Album : public LibraryItem
{
private:
  string artist;
public:
  Album(string, string, string);
  static const int CHECK_OUT_LENGTH = 14;
  int getCheckOutLength() override;
  string getArtist();
};

#endif
