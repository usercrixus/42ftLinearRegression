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

    bool promptAndPredict();
    double estimateY(double x);
    double normalize(double x);
    bool loadModel(std::string modelPath);
};