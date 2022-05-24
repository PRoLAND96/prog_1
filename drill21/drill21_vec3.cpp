#include <iostream>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Less_than {
	double v;
	public:
		Less_than(double vv) : v{vv}{}
		bool operator()(const double val) {return val < v;}
};

template<typename C>
void print(const C& c, char sep = '\n'){
	cout << "Container elements:\n";
	
	for(const auto elem: c){
		cout << elem << sep;
	}
	cout << endl;
}

int main()
try{
	const string iname {"input_floats.txt"};
	ifstream ifs {iname};
	if( !ifs ) throw runtime_error("Could not read from file: "+iname);
	
	vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	print(vd);
	
	vector<int> vi(vd.size());
	copy(vd.begin(),vd.end(),vi.begin());
	print(vi);
	
	for(int i=0 ; i<vd.size(); i++){
		cout << vd[i] << '\t' << vi[i] << endl;
	}
	
	double vd_sum = accumulate(vd.begin(), vd.end(), 0.0);
	cout << "Sum of vd: " << vd_sum << endl;
	
	double vi_sum = accumulate(vi.begin(), vi.end(), 0.0);
	cout << "Sum of vi: " << vi_sum << endl;
	
	double diff_sum = inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, plus<double>(), minus<double>());
	cout << "Cumulative difference: " << diff_sum << " " << vd_sum-vi_sum << endl;
	
	reverse(vd.begin(), vd.end());
	
	print(vd);
	
	double vd_mean = vd_sum / vd.size();
	
	cout << vd_mean << endl;
	
	vector<double> vd2(vd.size());
	
	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
	vd2.resize(distance(vd2.begin(), it));
	
	print(vd2);
	
	sort(vd.begin(), vd.end());
	print(vd);
	
} catch (exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Unknown exception\n";
}
