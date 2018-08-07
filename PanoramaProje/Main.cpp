
#include <iostream>
#include <fstream>

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
 
using namespace std;
using namespace cv;
 
Stitcher::Mode mode = Stitcher::PANORAMA;
 
// Array for pictures
vector<Mat> imgs;
 
int main(int argc, char* argv[])
{
	imgs.push_back(imread("1.jpg"));
	imgs.push_back(imread("2.jpg"));
	imgs.push_back(imread("3.jpg"));
	imgs.push_back(imread("4.jpg"));
    // Define object to store the stitched image
    Mat pano;
     
    //Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode, false);
     
    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);
 
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images\n";
        return -1;
    }
    imwrite("result.jpg", pano);
    imshow("Result", pano);
     
    waitKey(0);
    return 0;
}
