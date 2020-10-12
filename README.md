# learn-cpp-by-making-games-vol-1
Space Invaders C++ implementation using NCurses library

Special thanks to Serge Lansiquot for this awesome game dev C++ course

Course: https://www.udemy.com/course/learn-programming-by-making-games

### Pre-compiling instructions
#### Linux (Debian-based)
```
apt install cmake ncurses-dev
```

#### MacOS (using `brew` package manager)
```
brew install cmake ncurses
```

### Compiling instructions
```
$ mkdir build 
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release .. 
$ cmake --build .
$ ./SpaceInvaders
```
