#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <vector>

using namespace std;

struct Fruit{
	string name;
	int quantity;
	double unit_price;
	
	Fruit(const string& n, int q = 0, double p = 0.0): name{n}, quantity{q}, unit_price{p} {}
};

struct Fruit_ptr_cmp{
	bool operator()(const Fruit* a, const Fruit* b){
		return a->name < b->name;
		// return a-> quantity < b->quantity;
	}
};

int main()
try{
	vector<Fruit> vf {
		Fruit{"Plum", 3},
		Fruit{"Grape", 33},
		Fruit{"Banana", 21},
		Fruit{"Apple", 1},
		Fruit{"Orange", 19},
		Fruit{"Cherry", 98},
		Fruit{"Plum", 74},
		Fruit{"Kiwi", 54},
	
	};
	cout << "Vector values: " << endl;
	for (auto& f : vf){
		cout<< f.name << endl;
	}
	cout << endl;
	
	set<Fruit*, Fruit_ptr_cmp> sf;
	for (auto& f : vf){
		sf.insert(&f);
	}
	
	cout << "Set values: " << endl;
	for (auto& f : sf){
		cout<< f->name << endl;
	}
	cout << endl;
} catch (exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Unknown exception\n";
}
