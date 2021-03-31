#include <iostream>
#include "User.hpp"
#include "Database.hpp"

using namespace std;

int main() {
	string username = "Pesho";
	string password = "123";

	User u1(username, password, 1);
	Database db;
	db.add_user(u1);

	cout << db.find_by_id(1).get_name() << endl;
	cout << db.find_by_username(username).get_id() << endl;

	return 0;
}