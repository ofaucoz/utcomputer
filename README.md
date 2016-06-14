# UTComputer

[![Build Status](https://travis-ci.org/tgalopin/utcomputer.svg?branch=master)](https://travis-ci.org/tgalopin/utcomputer)

The UTComputer project is an implmentation of a full-featured programmable calculator in C++.
This projet is a work done in the context of the LO21 course, at the University of Technology of Compiègne.

This project follow the Google C++ coding convention: https://google.github.io/styleguide/cppguide.html.

## Running the application

Install the compilation tools:

```
sudo apt-get install cmake build-essential libgtk-3-dev libgtkmm-3.0-dev
```

And run the following command in the project directory:

```
bin/run.sh
```

## Running the tests (Google Test)

Install the Google Test library using the following instructions:

```
sudo apt-get install cmake libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

See http://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/ for more informations.

And run the following command in the project directory:

```
bin/test.sh
```

## Building the API documentation (Doxygen)

```
sudo apt-get install doxygen graphviz
cd /path/to/the/project
doxygen Doxyfile
```

Doxygen documentation is generated in the `doc` directory.

## Internal architecture

This project aims to use and implement OOP principles in a pure way:

- every class should have a single responsibility
- encapsulation should be used everywhere to avoid hard-coded dependancies between services
- desgin patterns should be used to ensure maintenability

UTComputer has three main components:
- the **Lexer** takes a string as an input and split it in a list of literals ;
- the **Resolver** transform the Atom literals of this list into Numeric or Operator literals by evaluating them using variables/programs/operators lists ;
- the **Runner** executes the command using operators ;

Each of these components has dependencies on other services (the LiteralFactory, the repositories, etc.).
