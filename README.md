# UTComputer

This project follow the Google C++ coding convention: https://google.github.io/styleguide/cppguide.html

## Running the application

This application uses CMake. You should probably use an IDE handling this for you (we recommand CLion),
but if you don't you can use the following instructions:

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
