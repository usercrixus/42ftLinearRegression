
# ft_linear_regression

This project implements a basic linear regression model in C++ with separate training and prediction modules. It is designed to be simple, educational, and self-contained.

## Project Structure

```
data.csv  Makefile  README.md  srcs  venv

srcs:
plot_model.py  predict  train

srcs/predict:
LinearRegressionPredict.cpp  LinearRegressionPredict.hpp  main.cpp

srcs/train:
LinearRegressionTrain.cpp  LinearRegressionTrain.hpp  main.cpp
```

## Build Instructions

You can build both the training and prediction binaries using the provided Makefile:

```bash
make train.out
make predict.out
```

This will generate two executables:
- `train.out` – for training a linear regression model
- `predict.out` – for making predictions using the trained model

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
```

### Helper

Directly build and execute.

```bash
make train
make predict
```

### DATA

Work and any csv on the form:

```
key,value
x,y
```

where x and y are valid numbers. For more informations, see data.csv file.