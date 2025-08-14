OBJ1 = \
	srcs/train/main.o \
	srcs/train/LinearRegressionTrain.o 

OBJ2 = \
	srcs/predict/main.o \
	srcs/predict/LinearRegressionPredict.o

FLAG = -Werror -Wextra -Wall

train.out: $(OBJ1)
	c++ $(OBJ1) -o $@

predict.out: $(OBJ2)
	c++ $(OBJ2) -o $@

train: train.out
	./train.out data.csv model.mo 0.1 1000

predict: predict.out
	./predict.out model.mo 

%.o: %.c 
	c++ $(FLAG) -c $< -o $@

init:
	python3 -m venv venv && . venv/bin/activate && pip install --upgrade pip pandas matplotlib

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f train.out predict.out model.mo 

.PHONY: clean fclean
