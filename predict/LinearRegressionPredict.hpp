#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class LinearRegressionPredict
{
private:
	std::string model;
	double weight;
	double bias;
	double minKey;
	double maxKey;

public:
	LinearRegressionPredict(std::string model);
	~LinearRegressionPredict();

    int promptAndPredict();

    double estimatePrice(double mileage);
    double normalize(double x);
    int loadModel();
};