/*#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\y.png", 1);
	Mat b(a.rows, a.cols, CV_8UC3, Scalar(0));
	int low = 0;
	int high = 255;
	namedWindow("Canny Edge Detection",WINDOW_AUTOSIZE);
	while (1){
		createTrackbar("Low", "Canny Edge Detection", &low, 255);
		createTrackbar("High", "Canny Edge Detection", &high, 255);
		Canny(a, b, low, high);
		imshow("Canny Edge Detection", b);
		if (waitKey(1) == 'e')
		{
			break;
		}
	}
	return 0;
}*/