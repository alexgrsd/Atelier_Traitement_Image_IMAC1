#include "exercices.hpp"

// sert de template pour les autres fonctions ou juste pour faire une copie si besoin
sil::Image copyImage(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            output.pixel(i, j).r = inputImage.pixel(i, j).r;
            output.pixel(i, j).g = inputImage.pixel(i, j).g;
            output.pixel(i, j).b = inputImage.pixel(i, j).b;
        }
    }
    return output;
}

// clamp un double entre deux valeurs
double dClamp(const double &d, const double &min, const double &max)
{
    const double t = d < min ? min : d;
    return t > max ? max : t;
}

int iClamp(const int &d, const int &min, const int &max)
{
    const int t = d < min ? min : d;
    return t > max ? max : t;
}

int getLength(const int &x1, const int &y1, const int &x2, const int &y2)
{
    double sum = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return sum;
}

sil::Image onlyKeepGreen(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            output.pixel(i, j).g = inputImage.pixel(i, j).g;
        }
    }
    return output;
}

// r-> g g->b b->r
sil::Image exchangeCanals(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output = inputImage;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // output.pixel(i, j).r = inputImage.pixel(i, j).g;
            // output.pixel(i, j).g = inputImage.pixel(i, j).b;
            // output.pixel(i, j).b = inputImage.pixel(i, j).r;
            std::swap(output.pixel(i, j).r, output.pixel(i, j).b);
        }
    }
    return output;
}

sil::Image toGrayScale(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float r = inputImage.pixel(i, j).r;
            float g = inputImage.pixel(i, j).g;
            float b = inputImage.pixel(i, j).b;
            float luminance = (0.3 * r + 0.59 * g + 0.11 * b);
            output.pixel(i, j).r = luminance;
            output.pixel(i, j).b = luminance;
            output.pixel(i, j).g = luminance;
        }
    }
    return output;
}

sil::Image invertImage(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            output.pixel(i, j).r = 1 - inputImage.pixel(i, j).r;
            output.pixel(i, j).g = 1 - inputImage.pixel(i, j).g;
            output.pixel(i, j).b = 1 - inputImage.pixel(i, j).b;
        }
    }
    return output;
}

sil::Image degrade()
{
    int width = 300;
    int height = 200;
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float luminance = (static_cast<float>(i) / width);
            output.pixel(i, j).r = luminance;
            output.pixel(i, j).b = luminance;
            output.pixel(i, j).g = luminance;
        }
    }
    return output;
}

sil::Image mirrorImageHorizontal(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            output.pixel(width - i - 1, j) = inputImage.pixel(i, j);
        }
    }
    return output;
}

sil::Image mirrorImagVertical(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            output.pixel(i, height - j - 1) = inputImage.pixel(i, j);
        }
    }
    return output;
}

sil::Image addNoise(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // si prob = true, on ajoute un pixel aléatoire;
            bool prob = true_with_probability(0.2);
            if (prob)
            {

                output.pixel(i, j).r = random_float(0, 1);
                output.pixel(i, j).g = random_float(0, 1);
                output.pixel(i, j).b = random_float(0, 1);
            }
            // sinon on copie l'image de base
            else
            {
                output.pixel(i, j) = inputImage.pixel(i, j);
            }
        }
    }
    return output;
}

sil::Image rotateImage(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    // on inverse hauteur et largeur pour la rotation
    sil::Image output{height, width};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            output.pixel(height - 1 - j, i) = inputImage.pixel(i, j);
        }
    }
    return output;
}

sil::Image rgbShift(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // on va clamp pour éviter les out of bounds
            // shift rouge 25 px a gauche
            int new_i = i - 25;
            new_i = iClamp(new_i, 0, width - 1);
            // shift vert 25 px a droite
            output.pixel(i, j).r = inputImage.pixel(new_i, j).r;
            new_i = i + 25;
            new_i = iClamp(new_i, 0, width - 1);
            output.pixel(i, j).g = inputImage.pixel(new_i, j).g;
            output.pixel(i, j).b = inputImage.pixel(i, j).b;
        }
    }
    return output;
}

// si dit = true -> on augmente la luminosité, on la baisse sinon
sil::Image changeLuminosity(sil::Image const &inputImage, bool dir)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (dir)
            {
                output.pixel(i, j).r = pow(inputImage.pixel(i, j).r, 0.8);
                output.pixel(i, j).g = pow(inputImage.pixel(i, j).g, 0.8);
                output.pixel(i, j).b = pow(inputImage.pixel(i, j).b, 0.8);
            }
            else
            {
                output.pixel(i, j).r = pow(inputImage.pixel(i, j).r, 1.2);
                output.pixel(i, j).g = pow(inputImage.pixel(i, j).g, 1.2);
                output.pixel(i, j).b = pow(inputImage.pixel(i, j).b, 1.2);
            }
        }
    }
    return output;
}

sil::Image makeCircle(int thickness)
{
    int width = 500;
    int height = 500;
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // si la distance par rapport au centre est inférieure a 125, on met le pixel en blanc
            // on base la taille du cercle par rapport a la largeur du cercle, on part du principe que width = height mais c'pas opti en vrai
            int size = getLength(i, j, width / 2, height / 2);
            if (size > width / 4 - thickness && size < width / 4 + thickness)
            {
                output.pixel(i, j).r = 1;
                output.pixel(i, j).b = 1;
                output.pixel(i, j).g = 1;
            }
        }
    }
    return output;
}

std::vector<sil::Image> makeCircleGif()
{
    std::vector<sil::Image> output;
    int width = 500;
    int height = 500;
    // on fait une image et on décale le centre de 50 px a chaque step
    for (int step = -width; step < width; step += 50)
    {
        sil::Image stepImage{width, height};
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                // on décale le centre du cercle de step sur l'axe x
                int pos = i + step;
                int size = getLength(pos, j, width / 2 + step, height / 2);
                if (size < 125)
                {
                    if (pos > 0 && pos < width)
                    {
                        stepImage.pixel(pos, j).r = 1;
                        stepImage.pixel(pos, j).b = 1;
                        stepImage.pixel(pos, j).g = 1;
                    }
                }
            }
        }
        output.push_back(stepImage);
    }

    return output;
}

sil::Image pixelize(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width, height};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            output.pixel(i, j) = inputImage.pixel((i / 10) * 10, (j / 10) * 10);
        }
    }
    return output;
}

sil::Image makeMosaic(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output{width * 5, height * 5};

    for (int i = 0; i < width * 5; i++)
    {
        for (int j = 0; j < height * 5; j++)
        {
            output.pixel(i, j) = inputImage.pixel(i % width, j % height);
        }
    }
    return output;
}

sil::Image glitchEffect(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output = inputImage;

    int nb_steps = 150;
    for (int i = 0; i < nb_steps; i++)
    {

        // on choisit les coordonées du blob de début et de fin
        int x_start = random_int(0, width - 26); // pour éviter les out of bound
        int y_start = random_int(0, height - 11);
        int x_end = random_int(0, width - 26);
        int y_end = random_int(0, height - 11);
        int x_size = random_int(5, 25);
        int y_size = random_int(5, 10);

        // on swap les pixels
        for (int x = 0; x < x_size; x++)
        {
            for (int y = 0; y < y_size; y++)
            {
                std::swap(output.pixel(x_start + x, y_start + y), output.pixel(x_end + x, y_end + y));
            }
        }
    }

    return output;
}

#include <algorithm>

static float luminance(const glm::vec3& p)
{
    return 0.3f * p.r + 0.59f * p.g + 0.11f * p.b;
}

void sortPixelArray(glm::vec3* pixelArray, int length)
{
    std::sort(pixelArray, pixelArray + length,
              [](const glm::vec3& a, const glm::vec3& b) {
                  return luminance(a) < luminance(b);
              });
}

sil::Image pixelSort(const sil::Image& inputImage)
{
    int height = inputImage.height();
    int width  = inputImage.width();
    sil::Image output = inputImage;

    int nb_lines = 250;
    int length_line = 50;

    if (width <= 0 || height <= 0) return output;
    length_line = std::min(length_line, width);

    for (int k = 0; k < nb_lines; ++k)
    {
        int y = random_int(0, height - 1);
        int x0 = random_int(0, width - 1);

        if (x0 + length_line > width)
            x0 = width - length_line;

        std::vector<glm::vec3> pixelArray;
        pixelArray.reserve(length_line);

        for (int x = 0; x < length_line; ++x)
            pixelArray.push_back(output.pixel(x0 + x, y));

        // ici on passe un VRAI buffer contigu + sa taille
        sortPixelArray(pixelArray.data(), (int)pixelArray.size());

        for (int x = 0; x < length_line; ++x)
            output.pixel(x0 + x, y) = pixelArray[x];
    }

    return output;
}


sil::Image fractale()
{
    int height = 800;
    int length = 800;
    sil::Image output{height, length};

    int max_iteration = 50;
    float incr = 4 / static_cast<float>(height - 1);

    for (float i = 0; i < length; i++)
    {
        for (float j = 0; j < height; j++)
        {
            float a = -2 + i * incr;
            float b = 2 - j * incr;
            std::complex c(a, b);
            std::complex z(0, 0);
            for (int iter = 0; iter < max_iteration; iter++)
            {
                // z = (z*z) + c ;
                if (std::norm(z) > 4)
                    break;
            }
        }
    }

    return output;
}

sil::Image makeMosaicMirrored(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    int size = 5;
    sil::Image output{width * size, height * size};

    for (int i = 0; i < width * size; i++)
    {
        for (int j = 0; j < height * size; j++)
        {
            if (i / width % 2 == 0 && j / height % 2 == 0)
            {
                output.pixel(i, j) = inputImage.pixel(i % width, j % height);
            }
            if (i / width % 2 == 1 && j / height % 2 == 0)
            {
                output.pixel(i, j) = inputImage.pixel(width - 1 - (i % width), j % height);
            }
            if (j / height % 2 == 1 && i / width % 2 == 0)
            {
                output.pixel(i, j) = inputImage.pixel(i % width, height - 1 - (j % height));
            }
            if (j / height % 2 == 1 && i / width % 2 == 1)
            {
                output.pixel(i, j) = inputImage.pixel(width - 1 - (i % width), height - 1 - (j % height));
            }
        }
    }

    return output;
}

// just a basic box blur for now
glm::vec3 meanOfPixels(std::vector<glm::vec3> const &vec)
{
    int length = vec.size() ;
    float r_mean{0};
    float g_mean{0};
    float b_mean{0}; 

    for (int i = 0; i<length; i++){
        r_mean += vec[i].r;
        g_mean += vec[i].g;
        b_mean += vec[i].b;
    }
    r_mean /= length;
    g_mean /= length; 
    b_mean /= length;
    glm::vec3 out {r_mean,g_mean,b_mean};
    return out;
}

sil::Image convolution(const sil::Image& inputImage)
{
    int blurSize = 9;                
    int r = blurSize / 2;             
    int height = inputImage.height();
    int width  = inputImage.width();

    sil::Image output{width, height};

    for (int i = r; i < width - r; ++i)
    {
        for (int j = r; j < height - r; ++j)
        {
            std::vector<glm::vec3> vecPix;
            vecPix.reserve(blurSize * blurSize);

            for (int x = -r; x <= r; ++x)
            {
                for (int y = -r; y <= r; ++y)
                {
                    vecPix.push_back(inputImage.pixel(i + x, j + y));
                }
            }

            output.pixel(i, j) = meanOfPixels(vecPix);
        }
    }
    return output;
}
