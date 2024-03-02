#ifndef FILTER_H
#define FILTER_H


#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include"image.h"


class Filter
{
public:

    // Initiallize Filter object
    Filter();
    void gaussionFilter(Image* img);
    void medianFilter(Image* img);
    void avgFilter(Image* img);

};

#endif // FILTER_H
