# UTComputer

The UTComputer project is an implmentation of a full-featured programmable calculator in C++.
This projet is a work done in the context of the LO21 course, at the University of Technology of Compiègne.

This project follow the Google C++ coding convention: https://google.github.io/styleguide/cppguide.html.

## Running the application

This application uses CMake. You should probably use an IDE handling this for you (we recommand CLion),
but if you don't want to, you can use the following instructions:

```
cd /path/to/the/project
cmake CMakeLists.txt
make
./LO21
```

## Running the tests

Install the GoogleTest library using the following instructions:

```
sudo apt-get install cmake libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

See http://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/ for more informations.

To run the tests, you should probably use your IDE (we recommand CLion) but you can also do it by hand:

```
cd /path/to/the/project
cmake CMakeLists.txt
make
./LO21tests
```

## Internal architecture

This project aims to use and implement OOP principles in a pure way:

- every class should have a single responsibility
- encapsulation should be used everywhere to avoid hard-coded dependancies between services
- desgin patterns should be used to ensure extandability and maintenability


UTComputer has three main components:
- the **Lexer** takes a string as an input and split it in a list of literals ;
- the **Resolver** transform the AtomLiterals in this list into numeric literals by evaluating them using variables/programs ;
- the **Runner** executes the code using operators

Each of these components has dependencies on other services (the LiteralFactory, the repositories, etc.).