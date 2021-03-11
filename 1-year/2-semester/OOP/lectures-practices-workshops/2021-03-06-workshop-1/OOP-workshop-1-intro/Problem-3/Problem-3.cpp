#include <iostream>

using namespace std;

enum StockType {
	perishable,
	packed,
	heat_resistant,
	stagnated
};

class Stock {
private:
	int count = 0;
	double buy_price = 0;
	double sell_price = 0;
	StockType stock_type;

	StockType get_stock_type_from_user_input() {
		int option;
		cin >> option;
		StockType stock_type_from_user;

		switch (option) {
			case 1: stock_type_from_user = perishable; break;
			case 2: stock_type_from_user = packed; break;
			case 3: stock_type_from_user = heat_resistant; break;
			case 4: stock_type_from_user = stagnated; break;
		}

		return stock_type_from_user;
	}

public:
	Stock create_stock_from_user_input() {
		int count;
		double buy_price, sell_price;
		cin >> count;
		cin >> buy_price >> sell_price;

		Stock stock;

		stock.set_count(count);
		stock.set_buy_price(buy_price);
		stock.set_sell_price(sell_price);
		stock.set_stock_type(get_stock_type_from_user_input());

		return stock;
	}

	void set_count(int new_count) {
		this->count = new_count;
	}

	int get_count() const {
		return this->count;
	}

	void set_buy_price(double new_buy_price) {
		this->buy_price = new_buy_price;
	}

	int get_buy_price() const {
		return this->buy_price;
	}

	void set_sell_price(double new_sell_price) {
		this->sell_price = new_sell_price;
	}

	int get_sell_price() const {
		return this->sell_price;
	}

	void set_stock_type(StockType new_stock_type) {
		this->stock_type = new_stock_type;
	}

	StockType get_stock_type() const {
		return this->stock_type;
	}

	Stock* create_stocks(int stocks_count) {
		Stock* stocks = new Stock[stocks_count];

		for (int i = 0; i < stocks_count; i++) {
			Stock stock = this -> create_stock_from_user_input();
			stocks[i] = stock;
		}

		return stocks;
	}

	double calculate_profit() const {
		return this->count * (this->sell_price - this->buy_price);
	}

	void print_stock_info() const {
		cout << this->count << " "
			<< this->buy_price << " "
			<< this->sell_price << " ";

		switch (this -> stock_type) {
			case perishable: cout << "Perishable"; break;
			case packed: cout << "Packed"; break;
			case heat_resistant: cout << "Heat resistant"; break;
			case stagnated: cout << "Stagnated"; break;
		}
	}
};

int main() {
	return 0;
}