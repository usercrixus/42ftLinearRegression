OBJ1 = \
	train/main.o \
	train/Train.o 
OBJ2 = \
	predict/main.o \
	predict/Predict.o
FLAG = -Werror -Wextra -Wall

train.out: $(OBJ1)
	c++ $(OBJ1) -o $@

predict.out: $(OBJ2)
	c++ $(OBJ2) -o $@

%.o: %.c 
	c++ $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) train.out predict.out

.PHONY: clean