#include "LinearRegressionPredict.hpp"

LinearRegressionPredict::LinearRegressionPredict():
weight(0),
bias(0),
minX(0),
maxX(0)
{
}

LinearRegressionPredict::~LinearRegressionPredict()
{
}
bool LinearRegressionPredict::promptAndPredict()
{
    if ((maxX - minX) == 0)
        return (std::cerr <<"Normalisation: Division by 0", false);
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    if (std::cin.fail())
        return (std::cerr << "Invalid input!" << std::endl, false);
    double y = estimateY(normalize(x));
    std::cout << "Estimated y: " << y << std::endl;
	return (true);
}


double LinearRegressionPredict::estimateY(double x)
{
	return (bias + weight * x);
}

double LinearRegressionPredict::normalize(double x)
{
    return 2.0 * (x - minX) / (maxX - minX) - 1.0;
}
bool LinearRegressionPredict::loadModel(std::string modelPath)
{
    std::ifstream file(modelPath);
    if (!file)
        return (std::cerr << "can't open " <<  modelPath << std::endl, false);
    file >> bias >> weight >> minX >> maxX;
    if (file.fail())
    {
        std::cerr << "Malformed " << modelPath << std::endl;
        return (false);
    }
    return (true);
}
