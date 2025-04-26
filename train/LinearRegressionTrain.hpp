#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class LinearRegressionTrain
{
private:
    std::vector<std::pair<int, int>> data;
    double learningRate;
    int step;
    double bias;
    double weight;
    double maxMileage;
    double minMileage;

    double estimatePrice(double mileage);
    double getLossBias();
    double getLossWeight();

public:
	LinearRegressionTrain(double learningRate, double step);
	~LinearRegressionTrain();

    int loadDataSet();
    void normalize();
    void train();
    int saveModel();
};