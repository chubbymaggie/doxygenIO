# IO Present: a modified version of Doxygen

## Inside folder *Project*:

a modified copy of doxygen from https://github.com/doxygen/doxygen.git

version: 1.8.12

## To build the project local (tested in: Debian 8, jessie):

  in the directory of *Project*
  
  apt-get build-dep doxygen
  
  delete CMakeCache.txt if it exists
  
  mkdir build if it does not exist
  
  inside the build folder: cmake -G "Unix Makefiles" ..
  
  inside the build folder: make
  
  get the runnable file: bin/doxygen
  
  sudo make install

