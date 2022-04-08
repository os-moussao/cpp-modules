#include <iostream>

class C
{
	private:
		std::string name;
	public:
		C(): name("N/A"){}
		C(const std::string &s): name(s) {}

		const std::string &setName(std::string const &s) {
			return name = s;
		}

		const std::string &getName() const {
			return name;
		}
};

int main() {
	C s;
	
	std::cout << s.getName() << std::endl;
	s = C("foobar");
	std::cout << s.getName() << std::endl;

	C *p;
	{
		C *ss = new C("New Class on te heap");
		p = ss;
		std::cout << p->getName() << std::endl;
	}

	p->setName("hello world");
	std::cout << p->getName() << std::endl;
	delete p;
}