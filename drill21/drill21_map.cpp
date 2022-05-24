#include <iostream> 
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>



template<typename K, typename V>
void print(const std::map<K, V>& m){
	for(const std::pair<K,V>& a: m){
		std::cout << a.first << '\t' << a.second << std::endl;
	}


}




int main()
try{

	std::map<std::string, int> msi;
	
	
	msi["a"] = 42;
	msi["e"] = 21;
	msi["ughjk"] = 2;
	msi["key"] = 3;
	msi["ab"] = 17;
	msi["cd"] = 93;
	msi["po"] = 62;
	msi["tt"] = 37;
	msi["x"] = 11;
	msi["k"] = 1;
	
	print(msi);



} catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << "\n";
	return 1;
}catch (...) {
	std::cerr << "Unknown exception\n";
	return 2;
}
