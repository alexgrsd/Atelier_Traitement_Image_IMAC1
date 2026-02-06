#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>
#include <vector>
#include <complex>

sil::Image onlyKeepGreen(sil::Image const& inputImage);
sil::Image exchangeCanals(sil::Image const& inputImage);
sil::Image toGrayScale(sil::Image const& inputImage);
sil::Image invertImage(sil::Image const& inputImage);
sil::Image degrade();
sil::Image mirrorImageHorizontal(sil::Image const& inputImage);
sil::Image mirrorImagVertical(sil::Image const& inputImage);
sil::Image addNoise(sil::Image const& inputImage);
sil::Image rotateImage(sil::Image const &inputImage);
sil::Image rgbShift(sil::Image const &inputImage);
sil::Image changeLuminosity(sil::Image const &inputImage, bool dir);
sil::Image makeCircle(int thickness);
std::vector<sil::Image> makeCircleGif();
sil::Image makeMosaic(sil::Image const &inputImage);
sil::Image pixelize (sil::Image const &inputImage);
sil::Image glitchEffect (sil::Image const &inputImage);
sil::Image pixelSort(sil::Image const &inputImage);
sil::Image makeMosaicMirrored(sil::Image const &inputImage);
sil::Image convolution(sil::Image const &inputImage);
sil::Image fractale(); // not working
sil::Image pixelize(sil::Image const &inputImage);