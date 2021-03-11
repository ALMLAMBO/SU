#include "BrowserTab.hpp"

BrowserTab::BrowserTab() {
	this->url = new char[1]{ '\0' };
	this->html_content = new char[1]{ '\0' };
}

BrowserTab::BrowserTab(const char* url, const char* html_content) {
	this->copy_char_array(this->url, url);
	this->copy_char_array(this->html_content, html_content);
}

BrowserTab::BrowserTab(const BrowserTab& from) : 
	BrowserTab(from.url, from.html_content) { }

void BrowserTab::set_url(const char* new_url) {
	delete[] url;
	this->copy_char_array(this->url, new_url);
}

void BrowserTab::set_html_content(const char* new_html_content) {
	delete[] html_content;
	this->copy_char_array(this->html_content, new_html_content);
}

char* BrowserTab::get_url() const {
	return url;
}

char* BrowserTab::get_html_content() const {
	return html_content;
}

void BrowserTab::copy_char_array(char* destination, const char* source) {
	int len = strlen(source);
	destination = new char[len + 1];
	strcpy(destination, source);
	destination[len] = '\0';
}

void BrowserTab::print_char_array(const char* array) {
	int len = strlen(array);
	for (int i = 0; i < len; i++) {
		std::cout << array[i];
	}
}