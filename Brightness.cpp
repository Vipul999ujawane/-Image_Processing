#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat a = imread("imgres.jpg", 1);
	imshow("code", a);
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			if (a.at <Vec3b>(i, j)[2]>205)
			{
				a.at <Vec3b>(i, j)[2] = 205;
			}
			if (a.at <Vec3b>(i, j)[0]>205)
			{
				a.at <Vec3b>(i, j)[0] = 205;
			}
			if (a.at <Vec3b>(i, j)[1]>205)
			{
				a.at <Vec3b>(i, j)[1] = 205;
			}
			a.at <Vec3b>(i, j)[0] += 50;
			a.at <Vec3b>(i, j)[1] += 50;
			a.at <Vec3b>(i, j)[2] += 50;

		}
	}
	imshow("code_red", a);
	waitKey(0);
	return 0;
}
