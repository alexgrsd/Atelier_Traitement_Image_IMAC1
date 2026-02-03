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

sil::Image mirrorImage(sil::Image const &inputImage)
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

// trie les pixels de chaque ligne dans un tableau 2D (bon ici ca servira a rien)
glm::vec3 *sortPixelArray(glm::vec3 *pixelArray, int width, int height)
{
    for (int j = 0; j < height; j++)
    {
        // tri a bulle
        for (int pass = 0; pass < width - 1; pass++)
        {
            for (int i = 0; i < width - 1 - pass; i++)
            {
                float lum1 = 0.3 * pixelArray[j * width + i].r + 0.59 * pixelArray[j * width + i].g + 0.11 * pixelArray[j * width + i].b;
                float lum2 = 0.3 * pixelArray[j * width + i + 1].r + 0.59 * pixelArray[j * width + i + 1].g + 0.11 * pixelArray[j * width + i + 1].b;
                if (lum1 > lum2)
                {
                    std::swap(pixelArray[j * width + i], pixelArray[j * width + i + 1]);
                }
            }
        }
    }
    return pixelArray;
}

// pixel sort effect
sil::Image pixelSort(sil::Image const &inputImage)
{
    int height = inputImage.height();
    int width = inputImage.width();
    sil::Image output = inputImage;

    int nb_lines = 250;
    for (int i = 0; i < nb_lines; i++)
    {

        // on pick une ligne aléatoire
        int line_x = random_int(0, height - 1);
        int line_y = random_int(0, width - 1);

        int length_line = 50;
        if (line_x + length_line > width)
        {
            length_line = width - line_x;
        } // pour éviter les out of bound

        std::vector<glm::vec3> pixelArray;
        // on remplit le tableau avec les pixels de la ligne
        for (int x = 0; x < length_line; x++)
        {
            pixelArray.push_back(output.pixel(line_x + x, line_y));
        }

        for (glm::vec3 &pixel : pixelArray)
        {
            sortPixelArray(&pixel, length_line, 1);
        }

        // on remet les pixels triés dans l'image
        for (int x = 0; x < length_line; x++)
        {
            output.pixel(line_x + x, line_y) = pixelArray[x];
        }
    }
    return output;
}

sil::Image fractale()
{
    sil::Image output{800, 800};
    return output;
}