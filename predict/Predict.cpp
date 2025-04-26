#include "Predict.hpp"

Predict::Predict()
{
}

Predict::~Predict()
{
}
int Predict::promptAndPredict()
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


double Predict::estimatePrice(double mileage) // mileage is normalized
{
	return (bias + weight * mileage);
}

double Predict::normalize(double x)
{
    return 2.0 * (x - minKey) / (maxKey - minKey) - 1.0;
}
int Predict::loadModel()
{
    std::ifstream file("model.mo");
    if (!file)
        return (std::cerr << "can't open model.mo" << std::endl, 1);

    file >> bias >> weight >> minKey >> maxKey;

    if (file.fail())
    {
        std::cerr << "Malformed model.mo" << std::endl;
        return (1);
    }

    return (0);
}
