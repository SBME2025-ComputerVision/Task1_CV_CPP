#ifndef NOISE_H
#define NOISE_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include "image.h"

using namespace std;

class Noise
{
public:
    Noise();
    // Add Uniform Noise to an Image object
    void uniformNoise(Image* img);

    // Add Gaussian Noise to an Image object
    void gasussianNoise(Image* img);

    // Add salt and pepper noise Noise to an Image object
    void saltAndPepperNoise(Image* img);

};

#endif // NOISE_H
