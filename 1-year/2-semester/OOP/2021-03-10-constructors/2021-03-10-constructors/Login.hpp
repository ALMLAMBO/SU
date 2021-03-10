#pragma once
#ifndef __LOGIN_HPP__

class Login {
public:
	Login();
	Login(const char*);
	Login(const char*, const char*);
	Login(const char*, const char*, const int);
	Login(const Login&);

	void set_username(const char*);
	void set_password(const char*);
	void set_session(const int);

	void print() const;

	char* get_username() const;
	char* get_password() const;
	int get_session() const;
private:
	void copy_char_array(char* destination, const char* source);
	char* username;
	char* password;
	int session;
};

#endif // !__LOGIN_HPP__
