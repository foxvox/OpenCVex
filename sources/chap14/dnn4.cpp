#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utils/trace.hpp>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace cv;
using namespace cv::dnn;
using namespace std;

/* ���� ���Ͽ� ������ Ŭ������ ã�´�. */
static void getMaxClass(const Mat &probBlob, int *classId, double *classProb)
{
	Mat probMat = probBlob.reshape(1, 1); // ������ 1x1000 ��ķ� �ٲ۴�.
	Point classNumber;
	minMaxLoc(probMat, NULL, classProb, NULL, &classNumber);
	*classId = classNumber.x;
}

static std::vector<String> readClassNames(const char *filename = "synset_words.txt")
{
	std::vector<String> classNames;
	std::ifstream fp(filename);
	if (!fp.is_open()) {
		std::cerr << "Ŭ���� ���̺��� ��� �ִ� ������ ����" << filename << std::endl;
		exit(-1);
	}
	std::string name;
	while (!fp.eof()) {
		std::getline(fp, name);
		if (name.length())
			classNames.push_back(name.substr(name.find(' ') + 1));
	}
	fp.close();
	return classNames;
}

int main()
{
	CV_TRACE_FUNCTION();
	String modelTxt = "bvlc_googlenet.prototxt";
	String modelBin = "bvlc_googlenet.caffemodel";
	String imageFile = "space_shuttle.jpg";
	Net net = dnn::readNetFromCaffe(modelTxt, modelBin);
	if (net.empty()) { exit(-1); }

	Mat img = imread(imageFile);
	if (img.empty()) {
		std::cerr << "�Է� ������ ���� �� ����" << imageFile << std::endl;
		exit(-1);
	}
	// GoogLeNet�� 224x224 ũ���� RGB-������ �ν��� �� ����
	Mat inputBlob = blobFromImage(img, 1, Size(224, 224),
		Scalar(104, 117, 123));   // ���󿡼� �Ϻθ� �����Ѵ�. 
	Mat prob;
	cv::TickMeter t;
	for (int i = 0; i < 10; i++)
	{
		CV_TRACE_REGION("forward");
		net.setInput(inputBlob, "data");        // �Ű�ȸ�θ��� �Է� ����
		t.start();
		prob = net.forward("prob");            // ����� ����Ѵ�.
		t.stop();
	}
	int classId;
	double classProb;
	getMaxClass(prob, &classId, &classProb);	//������ Ŭ������ ã�´�.
	std::vector<String> classNames = readClassNames();
	std::cout << "������ Ŭ����: #" << classId << " '" << classNames.at(classId) << "'" << std::endl;
	std::cout << "Ȯ��: " << classProb * 100 << "%" << std::endl;
	std::cout << "�ҿ�ð�: " << (double)t.getTimeMilli() / t.getCounter() << " ms (average from " << t.getCounter() << " iterations)" << std::endl;
	return 0;
} 