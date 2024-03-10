#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/ml.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;
using namespace cv::ml;

int main()
{
	Mat img;
	img = imread("d:/digits.png", IMREAD_GRAYSCALE);
	namedWindow("original", WINDOW_AUTOSIZE);
	imshow("original", img);
	waitKey(0);

	Mat train_features(5000, 400, CV_32F); 	// 400��1 ���� 5000��
	Mat labels = cv::Mat::zeros(5000, 10, CV_32F);

	// 20��20 ������ 400��1 �������� ��ȯ�Ͽ� �����Ѵ�. 
	for (int r = 0; r < 50; r++) {
		for (int c = 0; c < 100; c++) {
			int i = 0;
			for (int y = 0; y < 20; y++) {
				for (int x = 0; x < 20; x++) {
					train_features.at<float>(r * 100 + c, i++) = img.at<uchar>(r * 20 + y, c * 20 + x);
				}
			}
		}
	}

	// �н� �����Ϳ� ���� ���̺� ����
	for (int i = 0; i < 5000; i++) {
		if (i < 500) labels.at<float>(i, 0) = 1.0;
		else if (i < 1000) labels.at<float>(i, 1) = 1.0;
		else if (i < 1500) labels.at<float>(i, 2) = 1.0;
		else if (i < 2000) labels.at<float>(i, 3) = 1.0;
		else if (i < 2500) labels.at<float>(i, 4) = 1.0;
		else if (i < 3000) labels.at<float>(i, 5) = 1.0;
		else if (i < 3500) labels.at<float>(i, 6) = 1.0;
		else if (i < 4000) labels.at<float>(i, 7) = 1.0;
		else if (i < 4500) labels.at<float>(i, 8) = 1.0;
		else if (i < 5000) labels.at<float>(i, 9) = 1.0;
	}
	Ptr<ANN_MLP> mlp = ANN_MLP::create();

	Mat layersSize = Mat(3, 1, CV_16U);
	layersSize.row(0) = Scalar(400);	// �Է����� ���� ����
	layersSize.row(1) = Scalar(100);	// �������� ���� ����
	layersSize.row(2) = Scalar(10);	// ������� ���� ����

	mlp->setLayerSizes(layersSize);
	mlp->setActivationFunction(ANN_MLP::ActivationFunctions::SIGMOID_SYM);

	// 10000���� �ݺ�, ������ 0.0001�����̸� ����
	TermCriteria term = TermCriteria(
		TermCriteria::Type::COUNT + TermCriteria::Type::EPS,
		10000,
		0.0001
	);
	mlp->setTermCriteria(term);
	mlp->setTrainMethod(ANN_MLP::TrainingMethods::BACKPROP);

	Ptr<TrainData> trainingData = TrainData::create(
		train_features,
		SampleTypes::ROW_SAMPLE,
		labels
	);

	mlp->train(trainingData);

	Mat predictedLabels;

	// �н� �����͸� ������ �׽�Ʈ�غ���. 
	for (int i = 0; i < 5000; i++) {
		Mat test = train_features.row(i);
		Mat result;
		mlp->predict(test, result);
		cout << result << endl;
	}
}