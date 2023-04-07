all:
	g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror Account.cpp main.cpp Transaction.cpp -o Bank.exe
	./Bank.exe
