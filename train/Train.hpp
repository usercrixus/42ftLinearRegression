#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Train
{
private:
    std::vector<std::pair<int, int>> data;
    double learningRate;
    double bias;
    double weight;
    double maxMileage;
    double minMileage;
    int step;


public:
	Train(/* args */);
	~Train();

    void saveResult();

    double estimatePrice(double mileage);
    void linearRegression();
    void normalize();
    double getLossBias();
    double getLossWeight();
    int loadDataSet();
};