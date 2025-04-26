#include "LinearRegressionPredict.hpp"

LinearRegressionPredict::LinearRegressionPredict(std::string model):
model(model)
{
}

LinearRegressionPredict::~LinearRegressionPredict()
{
}
int LinearRegressionPredict::promptAndPredict()
{
    double mileageInput;
    std::cout << "Enter the mileage: ";
    std::cin >> mileageInput;
    if (std::cin.fail())
    {
        std::cerr << "Invalid input!" << std::endl;
        return (1);
    }
    double price = estimatePrice(normalize(mileageInput));
    std::cout << "Estimated price: " << price << std::endl;
	return (0);
}


double LinearRegressionPredict::estimatePrice(double mileage) // mileage is normalized
{
	return (bias + weight * mileage);
}

double LinearRegressionPredict::normalize(double x)
{
    return 2.0 * (x - minKey) / (maxKey - minKey) - 1.0;
}
int LinearRegressionPredict::loadModel()
{
    std::ifstream file(model);
    if (!file)
        return (std::cerr << "can't open " <<  model << std::endl, 1);
    file >> bias >> weight >> minKey >> maxKey;
    if (file.fail())
    {
        std::cerr << "Malformed " << model << std::endl;
        return (1);
    }
    return (0);
}
