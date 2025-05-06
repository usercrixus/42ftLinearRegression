
# ft_linear_regression

This project implements a basic linear regression model in C++ with separate training and prediction modules. It is designed to be simple, educational, and self-contained.

## Project Structure

```
ft_linear_regression/
├── Makefile
├── train/
│   ├── main.cpp
│   ├── LinearRegressionTrain.cpp
│   └── LinearRegressionTrain.hpp
├── predict/
│   ├── main.cpp
│   ├── LinearRegressionPredict.cpp
│   └── LinearRegressionPredict.hpp
```

## Build Instructions

You can build both the training and prediction binaries using the provided Makefile:

```bash
make
```

This will generate two executables:
- `train` – for training a linear regression model
- `predict` – for making predictions using the trained model

To clean up compiled files:

```bash
make fclean
```

## Usage

### Train

```bash
./train.out  <data.csv path> <output model path> <learning rate> <steps>
```

This will train the model based on the data in the given CSV file and save the resulting model parameters.

### Predict

```bash
./predict.out <model path>
