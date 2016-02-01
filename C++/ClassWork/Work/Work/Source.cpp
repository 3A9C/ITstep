// regex_search example
#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string s("dsada@a.b.c.d.fb.org.o2rg dsada@a.b.c.d.fb.o2rg.org dsada@a.b.c.d.fb.org.org ");
	std::smatch result;
	
	std::string di = s;
	std::string ips = s;
	std::string emails = s;


	std::regex d("\\d+[.]\\d{1}");   // поиск десятичных
	std::regex ip("\\d{1,3}[.]\\d{1,3}[.]\\d{1,3}[.]\\d{1,3}");   // поиск IP
	std::regex email("\\w*@[a-z]{1,}(?:[.][a-z]+){1,6}");   // поиск Email

	std::cout << "Text: " << s << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "found: " << std::endl;
	std::cout << "Decimal: ";

	// десятичные
	/*while (std::regex_search(di, result, d)) {
		for (auto x : result) std::cout << x << " ";
		di = result.suffix().str();
	}*/
	// десятичные
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "IP: ";


	// IP
	/*while (std::regex_search(ips, result, ip)) {
		for (auto x : result) std::cout << x << " ";
		ips = result.suffix().str();
	}*/
	// IP

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Email: ";

	// email
	while (std::regex_search(emails, result, email)) {
		for (auto x : result) 
			std::cout << x << ' ';
		emails = result.suffix().str();
	}
	// email
	




	std::cout << std::endl;
	system("pause");
	return 0;
}