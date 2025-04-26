#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Predict
{
private:
	double weight;
	double bias;
	double minKey;
	double maxKey;

public:
	Predict();
	~Predict();

    int promptAndPredict();

    double estimatePrice(double mileage);
    double normalize(double x);
    int loadModel();
};