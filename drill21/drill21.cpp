#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>

using namespace std;

void read_map(map<string, int>& m){
	string s;
	int i = 0;
	
	while(m.size()<10){
		cin >> s >> i;
		m[s] = i;
		//m.insert(make_pair(s, i));
	}
}

template<typename K, typename V>
void print(const map<K,V>& m){
	for(pair<K,V> a:m){
	//for(auto& a : m){
		cout << a.first << '\t' << a.second << endl;
	}
}

template<typename K, typename V>
	void msisum(const map<K,V>& m ){
		int sum = 0;
		for(auto& a: m){
			sum+=a.second;
		}
		cout << sum << endl;
	}
int main()
try{
	map<string, int> msi;
	msi["a"] = 1;
	msi["b"] = 2;
	msi["abc"] = 45;
	msi["x"] = 23;
	msi["g"] = 41;
	msi["wert"] = 92;
	msi["j"] = 30;
	msi["po"] = 11;
	msi["px"] = 67;
	msi["ac"] = 4;
	
	print(msi);
	
	msi.erase("a");
	cout << "a elem törlése után:" << endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	cout << "Teljes törlése után:" << endl;
	print(msi);
	
	cout<<"10 név érték pár megadása: "<< endl;
	read_map(msi);
	cout << "msi: " << endl;
	print(msi);
	
	cout<<"Összeg: "<< endl;
	msisum(msi);
	
	map<int, string> mis;
	for(pair<string, int> a : msi){
		mis[a.second] = a.first;
		//mis.insert(make_pair(a.second,a.first));
	}
	cout<< "mis map: "<< endl;
	print(mis);
	
	
} catch (exception& e) {
	cerr<< "Exception: "<<e.what() << '\n';
	return 1;
	
} catch (...) {
	cerr<<"Exception" << '\n';
	return 2;
}
