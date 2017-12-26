all: lib

lib: libMain.o Library.o LibraryItem.o Book.o Album.o Movie.o Patron.o
	g++ -g libMain.o Library.o LibraryItem.o Book.o Album.o Movie.o Patron.o -o lib

libMain.o: libMain.cpp Library.hpp LibraryItem.hpp Book.hpp Album.hpp Movie.hpp Patron.hpp
	g++ -c libMain.cpp

Library.o: Library.cpp Library.hpp LibraryItem.hpp Book.hpp Album.hpp Movie.hpp Patron.hpp
	g++ -c Library.cpp

LibraryItem.o: LibraryItem.cpp LibraryItem.hpp
	g++ -c LibraryItem.cpp

Book.o: Book.cpp Book.hpp LibraryItem.hpp
	g++ -c Book.cpp

Album.o: Album.cpp Album.hpp LibraryItem.hpp
	g++ -c Album.cpp

Movie.o: Movie.cpp Movie.hpp LibraryItem.hpp
	g++ -c Movie.cpp

Patron.o: Patron.cpp Patron.hpp LibraryItem.hpp
	g++ -c Patron.cpp

clean:
	rm -f *.o
