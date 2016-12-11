#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat a(400, 400, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 100; i < 300; i++)
	{
		for (int j = 100; j < 300; j++)
		{
			a.at <Vec3b>(i, j)[2] = 255;
		}
	}
	namedWindow("code_red", WINDOW_AUTOSIZE);
	imshow("code_red", a);
	waitKey(0);
	return 0;
}
