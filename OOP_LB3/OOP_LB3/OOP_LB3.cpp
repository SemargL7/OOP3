/*
������������� �������� > (��������� ���� �� �� ������), � (������ ���� �� � ��������� ������ �� ������),
����������� ����� ���������� ����� �� �� ��������� ���� � ������������� ��������� ���������� ������,
��������� ������ ���� �� � ��������� �� ��������� ������ � �����.
*/

#include <iostream>
#include <cmath>
#include <string>
#define PI 3.14

using namespace std;

class Cirle {
private:
	int x;
	int y;
	int radius;

public:
	Cirle(int x, int y, int radius) {
		this->x = x; this->y = y; this->radius = radius;
	}
	Cirle() {}
	~Cirle() {}													

	int GetX() { return x; }
	int GetY() { return y; }
	int GetRadius() { return radius; }

	void SetX(int a) { x = a; }
	void SetY(int b) { y = b; }
	void SetRadius(int c) { radius = c; }

	double square();
};


double Cirle::square() {											
	return (PI * pow(radius, 2));
}

bool operator > (Cirle a, Cirle b) {
	return a.square() > b.square();
}

Cirle operator - (Cirle c1, Cirle c2)
{
	return Cirle(c1.GetX() - c2.GetX(), c1.GetY() - c2.GetY(), c1.GetRadius() - c2.GetRadius());
}

void sorting(Cirle a[], int b) {
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			bool wtbigger = a[i] > a[j];
			if (wtbigger == true) {
				Cirle a_sort(a[j].GetX(), a[j].GetY(), a[j].GetRadius());

				a[j].SetX(a[i].GetX());
				a[j].SetY(a[i].GetY());
				a[j].SetRadius(a[i].GetRadius());

				a[i].SetX(a_sort.GetX());
				a[i].SetY(a_sort.GetY());
				a[i].SetRadius(a_sort.GetRadius());
			}
		}
	}
}



int main() {
	cout << "How much Circles you wanna insert? :"<<endl;
	int C;
	cin >> C;
	Cirle* arrays;
	arrays = new Cirle[C];
	int a;
	for (int i = 0; i < C; i++) {
		cout << "SetX:";
		cin >> a;
		arrays[i].SetX(a);
		cout << "SetY:";
		cin >> a;
		arrays[i].SetY(a);
		cout << "SetRadius:";
		cin >> a;
		arrays[i].SetRadius(a);
	}
	cout << "\tList of array:" << endl;
	for (int i = 0; i < C; i++) {
		cout << arrays[i].GetX() << " " << arrays[i].GetY() << " " << arrays[i].GetRadius() << endl;
	}
	sorting(arrays, C);
	cout << "\tSorted list of array:" << endl;
	for (int i = 0; i < C; i++) {
		cout << arrays[i].GetX() << " " << arrays[i].GetY() << " " << arrays[i].GetRadius() << endl;
	}
	cout << "\n\tThe difference between  the biggest and the smallest:\n";
	Cirle dif_of_max_and_min = arrays[0] - arrays[C - 1];
	cout << dif_of_max_and_min.GetX() << " " << dif_of_max_and_min.GetY() << " " << dif_of_max_and_min.GetRadius() << endl;
}