#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class LinearRegressionPredict
{
private:
	double weight;
	double bias;
	double minX;
	double maxX;

public:
	LinearRegressionPredict();
	~LinearRegressionPredict();

    int promptAndPredict();

    double estimateY(double x);
    double normalize(double x);
    int loadModel(std::string modelPath);
};