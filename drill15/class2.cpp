#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class Person{
	public:
		Person(){}
		//Person(string n, int a) : n{n}, a{a}{
		Person(string f, string l, int a) : f{f}, l(l), a{a}{
			if(a < 0 || a >=150){
				throw runtime_error ("Invalid age");
			}
			
			string n = f + l;
			
			for (char c : n){
				switch(c) {
					case ':' :
					case '$' :
					case '%' :
					case '[' :
					case ']' :
					case '^' :
					case '"' :
					case '&' :
					case '!' :
					case '@' :
					case ';' :
					case '*' :
					case '#' :
					/*case ''' :*/
						throw runtime_error ("Invalid character");
						break;
					default:
						break;
				}
				
			}	
		};
		//string name() const {return n;}
		string first() const {return f;}
		string last() const {return l;}
		int age()const{return a;}
	private:
		//string n;
		string f;
		string l;
		int a;
};

ostream& operator<< (ostream& os, const Person& p) {
	return os << p.first() << " " << p.last() << " " << p.age();
}

istream& operator>> (istream& is, Person& p){
	string f;
	string l;
	int a;
	is >> f >> l >> a;
	
	p = Person(f, l, a);
	return is;
}
/* 	ostream ki (ostream os, Person& p)
	ostream& oper(ostream os, Person p)
	cout << p -->ez az egész egy ostream
	
	is(input stream) >> Person >> Person >> person
*/

int main(){

	//Person p;
	Person p = Person("Goofy", "a", 63);
	//p.n = "Goofy";
	//p.a = 63;
	//cout << p << endl;
	
	cout << p.first()<<" " << p.last() << " " << p.age() << endl;
	
	Person p2;
	cin >> p2;
	cout << p2 << endl;
	
	vector<Person> vec;
	for(Person p; cin>>p;){ //while(cin>>p)
		if(p.first() == "end") break;
		vec.push_back(p);
	}
	
	for(Person p: vec){
		cout << p << endl;
	}
}
