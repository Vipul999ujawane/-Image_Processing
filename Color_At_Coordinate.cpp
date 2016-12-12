#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat img = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\Test.png", 1);
void callback(int Event, int y, int x, int flags, void *userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	{
		printf("B=%d\n", img.at<Vec3b>(x, y)[0]);
		printf("G=%d\n", img.at<Vec3b>(x, y)[1]);
		printf("R=%d\n", img.at<Vec3b>(x, y)[2]);
		printf("\n");
	}
}
int main()
{

	//namedWindow("Double", WINDOW_AUTOSIZE);
	//createTrackbar("Cols", "Double", &cols, 100);

	imshow("Win", img);
	setMouseCallback("Win", callback, NULL);
	waitKey(0);
	return 0;
}
