#include <iostream>
#include <list>
using namespace std;
#define MAX_COUNT 3

double middle_filter(double new_val) {
	static list<double> data_list;		//отсортированные значени€
	static list<std::list<double>::iterator>lru;	//cписок указателей
	if (data_list.empty()) {
		data_list.push_back(new_val);
		auto it = data_list.begin();
		lru.push_back(it);
	}
	else {
		for (auto it = data_list.begin(); it != data_list.end(); ++it) //чЄтное макс количество
				if (*(it) > new_val) {
					auto it2 = data_list.insert(it, new_val);
					lru.push_back(it2);
					break;
				}
	}
	
	//if(элементов >= MAX_COUNT) else
	if (data_list.size() > MAX_COUNT) {
		data_list.erase(lru.front());	//стираю значение по старому "адресу"
		lru.pop_front();				//удал€ю самый старый "адрес" элемента

	//	вывод элемента
		auto it = data_list.begin();
		if (MAX_COUNT % 2 == 1) {
			int i = 0;
			for (it = data_list.begin(); i <= MAX_COUNT / 2; ++i, ++it); //чЄтное макс количество
			return *it;

		}
		else {
			double middle = 0;
			it = data_list.begin();
			int i = 0;
			for (it = data_list.begin(); i <= MAX_COUNT / 2; ++i, ++it) { //нечЄтное макс количество
				if (i == MAX_COUNT - 1) {
					middle = (*it + *(++it) / 2);
					break;
				}
			
			}
			return middle;
		}
	}
}

int main() {
	for (double i = 8; i != 0; --i)
		cout << middle_filter(i) << endl;
	return 0;
}