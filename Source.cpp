#include <iostream>
#include <list>
using namespace std;
#define MAX_COUNT 3

double middle_filter(double new_val) {
	static list<double> data_list;		//��������������� ��������
	static list<std::list<double>::iterator>lru;	//c����� ����������
	if (data_list.empty()) {
		data_list.push_back(new_val);
		auto it = data_list.begin();
		lru.push_back(it);
	}
	else {
		for (auto it = data_list.begin(); it != data_list.end(); ++it) //������ ���� ����������
				if (*(it) > new_val) {
					auto it2 = data_list.insert(it, new_val);
					lru.push_back(it2);
					break;
				}
	}
	
	//if(��������� >= MAX_COUNT) else
	if (data_list.size() > MAX_COUNT) {
		data_list.erase(lru.front());	//������ �������� �� ������� "������"
		lru.pop_front();				//������ ����� ������ "�����" ��������

	//	����� ��������
		auto it = data_list.begin();
		if (MAX_COUNT % 2 == 1) {
			int i = 0;
			for (it = data_list.begin(); i <= MAX_COUNT / 2; ++i, ++it); //������ ���� ����������
			return *it;

		}
		else {
			double middle = 0;
			it = data_list.begin();
			int i = 0;
			for (it = data_list.begin(); i <= MAX_COUNT / 2; ++i, ++it) { //�������� ���� ����������
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