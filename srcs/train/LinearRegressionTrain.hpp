#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class LinearRegressionTrain
{
private:
    std::vector<std::pair<double, double>> data;
    double learningRate;
    int step;
    double bias;
    double weight;
    double maxX;
    double minX;

    double estimateY(double x);
    double getLossBias();
    double getLossWeight();

public:
	LinearRegressionTrain(double learningRate, int step);
	~LinearRegressionTrain();

    bool loadDataSet(char *path);
    bool normalize();
    bool train();
    bool saveModel(char *path);
};