#include <iostream>
#include <fstream>
#include "polygon.h"
#include "regular_polygon.h"
#include <fstream>
#include "treangl.h"
//#include "crtdynmem.h"

using namespace std;

int main()
{

	
	int n;
	
	char D;


	cout << "Skol'ko figur ?";
	cin >> n;
	double max_P=0;
	double max_S=0;
	double min_R=9999;
	double min_r=999;
	circled **B= new circled * [n];
	regular_polygon C;
	cout << "P pravel'nyj mnogougol'nik, T treugol'nik, R pryamougol'nik" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> D;
		switch (D)
		{
		case 'P':
		{
			B[i] = new regular_polygon;//пользоваться конструктором;
			regular_polygon K;
			cout << "Vvedite kol storon, dlinnu, koordinaty centra" << endl;
			cin >>K;
			//cin >> C;
			*B[i] = K;
			break;
		}
		case 'T':
		{
			B[i] = new treangl;
			cout << "Vvedite koordinaty 3h vershin" << endl;
			treangl A;
			//cin >> B;
			B[i] = &A;

			break;
		}
		case 'R':
		{	B[i] = new quad;
			cout << "Vvedite koordinaty levoj i pravoj vershiny" << endl;
			quad A;
			cin >> A;
			B[i] = &A;
			break;
		}
		default:
			break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (B[i][0].P() > max_P) max_P = B[i][0].P();
		if (B[i][0].S() > max_S) max_S = B[i][0].S();
		if (B[i][0].R() < min_R) min_R = B[i][0].R();
		if (B[i][0].r() < min_r) min_r = B[i][0].r();
	}
	cout << max_P << " " << max_S << " " << " " << min_R << " " << min_r<<endl;

	system("pause");
	return 0;
}
