# DZIzer
C++ image to dzi converter using libvips
DZIzer takes a single image, and creates DeepZoom (.dzi) file.

DZizer requires [libvips](https://www.libvips.org/API/current/libvips-from-C++.md.html)

After installing vips run Makefile to compile, after it you can use it.

Since dzizer just use libvips function it is supposed to convert any image formats libvips can use. The formats list you 
can check in [libvips documentation](https://www.libvips.org/).
For June 2022 it is:  JPEG, TIFF, PNG, WebP, FITS, Matlab, OpenEXR, PDF, SVG, HDR, PPM, CSV, GIF, Analyze, NIfTI and OpenSlide.

# Usage
To convert run dzizer executing file with arguments in this format:

./dzizer.o input output saveDirectory \[container]

input — image to convert to dzi

output — name(without path) of output file. DZI extension is xml dzi file and folder with tiles, the files will have this name

saveDirectory — directory to save the dzi to. not necessary to exist

container — directory with all files, therefore the dzi files will be saved in "saveDirectory/container/". Isn't necessary, 
without it the dzi files will be saved in just "saveDirectory/"
