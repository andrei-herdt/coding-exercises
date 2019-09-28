I developed this solution by following the TDD approach.
Accordingly, the unit and integration tests in spec.cpp reflect
entirely my interpretation of the assignment.

After the usual:
mkdir build
cd build
cmake ..
make
the test executable can be found in build/specs/

For the design, I layed emphasis on decoupling the platform from the sensors.
To this end, I made use of the observer pattern.
