#include <iostream>
#include <string>
#include <typeinfo>

// e.g. Animals

class Animal
{
public:
	Animal(std::string n, std::string c, int a)
		: name(n), call(c), age(a) {}

	// virtual destructor
	virtual ~Animal() {}

	virtual void intro() const {
		std::cout << "Hi, my name is " << name << ". " << call << "!";
	}
private:
	std::string name;
	std::string call;
	int age;
};

class Cow : public Animal
{
public:
	Cow(std::string n, std::string c, int a)
		: Animal(n, c, a) {}

	virtual void intro() const {
		Animal::intro();
		std::cout << "\nI am a cow" << std::endl;
	}
};

class Pig : public Animal
{
public:
	Pig(std::string n, std::string c, int a)
		: Animal(n, c, a) {}

	virtual void intro() const {
		Animal::intro();
		std::cout << "\nI am a pig" << std::endl;
	}
};

int main() 
{
	Cow cow("Muriel", "moo", 37);
	Pig pig("Roster", "oink", 12);

	Animal *myAnimals[] = {&cow, &pig};
	for (size_t i = 0; i < 2; ++i) {
		myAnimals[i]->intro();
		std::cout << std::endl << std::endl;
	}

	for (size_t j = 0; j < 2; ++j)
		std::cout << typeid(*myAnimals[j]).name() << std::endl;
}

// Note on virtual
//	virtual functions run depending on the type of object calling them, as opposed to the type of the handle
//	programme determines dynamically (at runtime) which function to use
//	No need to specify 'virtual' at function definition (in .cpp)