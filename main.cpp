#include "vec3.h"
#include "color.h"

#include <iostream>

int main() {

   // Image

   int image_width = 256;
   int image_height = 256;

   // Render

   std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

   for (int j = 0; j < image_height; ++j)
   {
      std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
      for (int i = 0; i < image_width; ++i)
      {
         auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
         write_color(std::cout, pixel_color);

         /*auto red = double(i) / (image_width - 1);
         auto green = double(j) / (image_height - 1);
         auto blue = 0;

         int ir = static_cast<int>(255.999 * red);
         int ig = static_cast<int>(255.999 * green);
         int ib = static_cast<int>(255.999 * blue);

         std::cout << ir << ' ' << ig << ' ' << ib << '\n';*/

      }
   }
   std::clog << "\rDone.                 \n";
}
