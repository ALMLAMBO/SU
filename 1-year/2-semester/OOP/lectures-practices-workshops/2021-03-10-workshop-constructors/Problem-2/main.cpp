#include <iostream>
#include "BrowserTab.hpp"

using namespace std;

int main() {
	BrowserTab tab1;
	tab1.set_url("https:://google.com");
	tab1.set_html_content("some content");

	return 0;
}