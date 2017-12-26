#include "Album.hpp"

#include <string>
using std::string;

//const int Album::CHECK_OUT_LENGTH = 14;

Album::Album(string idc, string t, string art) : LibraryItem(idc, t)
{
  artist = art;
}

// Overriden getCheckOutLength function
int Album::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}

string Album::getArtist()
{
  return artist;
}
