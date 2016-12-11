#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat a(800, 800, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 800; i++)
	{
		for (int j = i; j < 800; j++)
		{
			a.at <Vec3b>(i, j)[0] = 255;
		}
	}
	for (int j = 0; j < 800; j++)
	{
		for (int i = j; i < 800; i++)
		{
			a.at <Vec3b>(i, j)[1] = 255;
		}
	}
	namedWindow("code_red", WINDOW_AUTOSIZE);
	imshow("code_red", a);
	waitKey(0);
	return 0;
}
