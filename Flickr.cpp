#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat a = imread("Test.png", 1);
	Mat avg(a.rows, a.cols, CV_8UC1, Scalar(0));
	Mat frm(a.rows, a.cols, CV_8UC1, Scalar(0));
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			avg.at<uchar>(i, j) = (a.at<Vec3b>(i, j)[0] + a.at<Vec3b>(i, j)[1] + a.at<Vec3b>(i, j)[2]) / 3;
			frm.at<uchar>(i, j) = (0.114*(a.at<Vec3b>(i, j)[0]) + 0.587*(a.at<Vec3b>(i, j)[1]) + 0.299*(a.at<Vec3b>(i, j)[2]));
		}
	}
	namedWindow("Original", WINDOW_AUTOSIZE);
	for (int i = 0; i < 1000; i++)
	{
		imshow("Original", frm);
		waitKey(1000);
		imshow("Original2", avg);
		waitKey(1000);
	}

	waitKey(0);
	return 0;

}
