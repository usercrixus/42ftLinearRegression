OBJ1 = \
	train/main.o \
	train/LinearRegressionTrain.o 

OBJ2 = \
	predict/main.o \
	predict/LinearRegressionPredict.o

FLAG = -Werror -Wextra -Wall

train.out: $(OBJ1)
	c++ $(OBJ1) -o $@

predict.out: $(OBJ2)
	c++ $(OBJ2) -o $@

%.o: %.c 
	c++ $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f train.out predict.out model.mo

.PHONY: clean fclean