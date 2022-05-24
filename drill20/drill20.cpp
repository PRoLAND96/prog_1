#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

template<typename C>
void print_contents(const C& c){
	for(auto& a : c)
		cout << a << ' ';
	cout << endl;
}

template<typename C>
void inc(C& c, int n){
	for(auto& a : c)
		a+=n;
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p!= e1; ++p){
		*f2++ = *p;
	}
	return f2;
}

int main()
try {
	constexpr int size = 10;
	
	int arr[size];
	for (int i = 0; i < size; ++i) arr [i] = i;
	cout << "arr: ";
	print_contents(arr);
	
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());
	cout << "array: ";
	print_contents(ai);
	
	vector<int> vi(size);
	copy(arr, arr + size, vi.begin());
	cout << "vector: ";
	print_contents(vi);
	
	list<int> li(size);
	copy(arr, arr + size, li.begin());
	cout << "list: ";
	print_contents(li);
	
	array<int, size> ai2=ai;
	vector<int> vi2=vi;
	list<int> li2=li;
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	inc(ai2,2);
	inc(vi2,3);
	inc(li2,5);
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	vector<int>::iterator vit;
	vit = find(vi2.begin(),vi2.end(), 15);
	if(vit != vi2.end()){
		cout << "Found at: " << distance(vi2.begin(), vit) << endl;
	} else {
		cout << "Not found" << endl;
	}
	
}

catch(exception& e){
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Unkown exception\n";
	return 2;
}
