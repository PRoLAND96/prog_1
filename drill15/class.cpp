#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class Person{
	public:
		Person(){}
		Person(string n, int a) : n{n}, a{a}{
			if(a < 0 || a >=150){
				throw runtime_error ("Invalid age");
			}	
		};
		string name() const {return n;}
		int age()const{return a;}
	private:
		string n;
		int a;
};

ostream& operator<< (ostream& os, const Person& p) {
	return os << p.name() << " " << p.age();
}

istream& operator>> (istream& is, Person& p){
	string n;
	int a;
	is >> n >> a;
	
	p = Person(n, a);
	return is;
}
/* 	ostream ki (ostream os, Person& p)
	ostream& oper(ostream os, Person p)
	cout << p -->ez az egész egy ostream
	
	is(input stream) >> Person >> Person >> person
*/

int main(){

	//Person p;
	Person p = Person("Goofy", 63);
	//p.n = "Goofy";
	//p.a = 63;
	cout << p << endl;
	
	Person p2;
	cin >> p2;
	cout << p2 << endl;
}
