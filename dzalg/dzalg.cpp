// dzalg.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "header.h"
#include <fstream>


int main(int argc, char *argv[])
{
	std::ifstream F1(argv[1]);
	std::ofstream F2(argv[2]);
	//std::ifstream F3(argv[3]);
	std::vector<int> tasks;
	std::vector<metod> metods;
	std::vector<int> vesa;
	int num_t;
	F1 >> num_t;
	for (int i = 0; i < num_t; i++)
	{
		int k;
		F1 >> k;
		tasks.push_back(k);
	}
	F1 >> num_t;
	for (int i = 0; i < num_t; i++)
	{
		int k;
		F1 >> k;
		vesa.push_back(k);
	}
	for (int i = 0; i < num_t; i++)
	{
		int k;
		F1 >> k;
		std::vector<int> ss;
		int l;
		for (int j = 0; j < k; j++)
		{
			F1 >> l;
			ss.push_back(l);
		}
		metod test(ss, i+1, vesa[i]);
		metods.push_back(test);
	}
	cover sol(metods, tasks);
	metods = sol.vivod();
	F2 << metods.size()<< " ";
	for (auto &i : metods)
		F2 << i.rename() << " ";
	F1.close();
	F2.close();
	std::ifstream f2(argv[2]);
	std::ifstream f3(argv[3]);
	int q, w;
	f2 >> q;
	f3 >> w;
	if (w == q)
	{
		for (int i = 0; i < w; i++)
		{
			int z, x;
			f2 >> z;
			f3 >> x;
			if (z != x)
			{
				std::cout << "fail";
				return 0;
			}
		}
	}
	else
	{
		std::cout << "fail";
	}
	std::cout << "succes";
	/*cover a({ 0,1,2,3,4,5,6,7 });
	metod d({ 0,1,2,3,4,5 }, 1, 5);
	metod b({ 0,1,2 }, 2, 2);
	metod c({ 3,4,5 }, 3, 2);
	
	std::vector<metod> asd = { d,b,c };
	a.add_met(d);
	a.add_met(c);
	a.add_met(b);
	//std::cout << a.sum_mets(asd).size();
	a.solList();
	a.optimize();
	//a.vivod();
	a.print_sol();
	system("pause");*/
    return 0;
}

