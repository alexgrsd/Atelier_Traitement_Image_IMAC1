#include "exercices.hpp"

int main()
{
    
    sil::Image logo{"images/logo.png"};
    sil::Image photo{"images/photo.jpg"};
    sil::Image photoFaibleContraste{"images/photo_faible_contraste.jpg"};

    /*
    sil::Image onlyGreen = onlyKeepGreen(logo);
    onlyGreen.save("output/onlyGreen.png");


    sil::Image changeCan = exchangeCanals(logo);
    changeCan.save("output/exchangeChannels.png");


    sil::Image grayScale = toGrayScale(logo);
    grayScale.save("output/grayScale.png");


    sil::Image inverted = invertImage(logo);
    inverted.save("output/inverted.png");


    
    sil::Image degradeImage = degrade();
    degradeImage.save("output/degrade.png");
    


    sil::Image mirrored = mirrorImage(logo);
    mirrored.save("output/mirror.png");


    sil::Image noised = addNoise(logo);
    noised.save("output/noised.png");


    sil::Image rotated = rotateImage(logo);
    rotated.save("output/rotated.png");


    sil::Image shifted = rgbShift(logo);
    shifted.save("output/shifted.png");

   

    sil::Image lighter = changeLuminosity(photo,true);
    sil::Image darker = changeLuminosity(photo,false);
    lighter.save("output/lighter.png");
    darker.save("output/darker.png");



    sil::Image circle = makeCircle(5);
    circle.save("output/circle.png");

         

    std::vector<sil::Image> gifVector = makeCircleGif();
    for (int i=0; i< gifVector.size(); i++){
        std::string name = "circleGif"+std::to_string(i);
        gifVector[i].save("output/gifCircle/"+name+".png");
    }

    sil::Image mosaic = makeMosaic(logo);
    mosaic.save("output/mosaic.png");
   

    sil::Image glitched = glitchEffect(logo);
    glitched.save("output/glitched.png");


     */

    sil::Image pixelSorted = pixelSort(logo);
    pixelSorted.save("output/pixelSorted.png");

}