/**
 * Writes a PPM image file.
 * 
 * Author: Erel Segal-Halevi.
 * Based on C code in RosettaCode: 
 * http://rosettacode.org/wiki/Category:C
 * 
 * Since: 2018-04
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  const int dimx = 800, dimy = 800;
  ofstream imageFile("cpp.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  for (int j = 0; j < dimy; ++j)  {
    for (int i = 0; i < dimx; ++i) {
      char color[3];
      color[0] = i % 256;  /* red */
      color[1] = j % 256;  /* green */
      color[2] = (i + j) % 256;  /* blue */
	  imageFile << color[0] << color[1] << color[2];
    }
  }
  imageFile.close();
  return 0;
}
