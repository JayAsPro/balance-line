INCLUDE_DIR := include
SRC_DIR := src

CC := gcc
CCFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -pedantic -O3

main:
	$(CC) $(SRC_DIR)/*.c $(CCFLAGS) -o balance-line
