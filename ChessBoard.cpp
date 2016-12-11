#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat b(400, 400, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 400; i += 40)
	{
		for (int j = 0; j < 400; j += 40)
		{
			for (int k = 0; k < 20; k++)
			{
				for (int l = 0; l < 20; l++)
				{
					b.at<Vec3b>(i + k, j + l)[0] = 255;
					b.at<Vec3b>(i + k, j + l)[1] = 255;
					b.at<Vec3b>(i + k, j + l)[2] = 255;
				}
			}
		}
	}
	for (int i = 20; i < 400; i += 40)
	{
		for (int j = 20; j < 400; j += 40)
		{
			for (int k = 0; k < 20; k++)
			{
				for (int l = 0; l < 20; l++)
				{
					b.at<Vec3b>(i + k, j + l)[0] = 255;
					b.at<Vec3b>(i + k, j + l)[1] = 255;
					b.at<Vec3b>(i + k, j + l)[2] = 255;
				}
			}
		}
	}

	imshow("Chess Board", b);
	waitKey(0);
	return 0;

}
