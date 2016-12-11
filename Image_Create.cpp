#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat a(400, 400, CV_8UC3, Scalar(0, 0, 255));
	namedWindow("code_red", WINDOW_AUTOSIZE);
	imshow("code_red", a);
	waitKey(0);
	return 0;
}
