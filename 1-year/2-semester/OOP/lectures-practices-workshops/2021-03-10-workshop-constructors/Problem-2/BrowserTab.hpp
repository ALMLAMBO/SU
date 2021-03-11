#pragma once
#ifndef __BROWSER_TAB_HPP__
#define __BROWSER_TAB_HPP__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class BrowserTab {
public:
	BrowserTab();
	BrowserTab(const char* url, const char* html_content);
	BrowserTab(const BrowserTab& from);

	void set_url(const char* new_url);
	void set_html_content(const char* new_html_content);

	char* get_url() const;
	char* get_html_content() const;

private:
	char* url;
	char* html_content;

	void copy_char_array(char* destination, const char* source);
	void print_char_array(const char* array);
};

#endif // !__BROWSER_TAB_HPP__