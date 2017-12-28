all: lib

CPPFLAGS= -std=c++11
OBJS=libMain.o Library.o LibraryItem.o Book.o Album.o Movie.o Patron.o
ALLHEADERS=Library.hpp LibraryItem.hpp Book.hpp Album.hpp Movie.hpp Patron.hpp

lib: $(OBJS)
	g++ -g $(OBJS) -o $@

libMain.o: libMain.cpp $(ALLHEADERS)
	g++ -c $(CPPFLAGS) libMain.cpp

Library.o: Library.cpp $(ALLHEADERS)
	g++ -c $(CPPFLAGS) Library.cpp

%.o : %.cpp %.hpp LibraryItem.hpp
	g++ -c $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o lib
