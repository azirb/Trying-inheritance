#pragma once
#include <cmath>
#include <limits.h>
#include <string>
#include <iostream>

using namespace std;
class city
{
protected:
	
	
public:
	int neighbours[10];
	int numlock;
	int posx, posy;
	string name;
	city() { name = ""; posx = 10000; posy = 10000; }
	city(int a, int b, string example, int nei[10], int n) 
	{
		numlock = n;
		for (int i = 0; i < n; i++)
		{
			neighbours[i] = nei[i];
		}
		posx = a;
		posy = b;
		name = example;

	}
	bool ishere(int a,int b)
	{
		if (posx == a && posy == b) 
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	~city() { delete[]neighbours; }
};

class map : public city
{
private:
	int current_positionx;
	int current_positiony;

public:
	map() {};
	map(int currpossx,int currpossy)
	{ 
		current_positionx = currpossx;
		current_positiony = currpossy;
	}
	void mapopen()
	{
		int x1 = 15; int y1 = 20; string s1 = "el paso"; int nei1[10]; int n1 = 1;
		nei1[0] = 1;
		city city1(x1, y1, s1,nei1,n1);
		//1
		int x2 = 45; int y2 = 25; string s2 = "fort stockton"; int nei2[10]; int n2 = 2; nei2[0] = 0;nei2[1]=2;
		city city2(x2, y2, s2,nei2,n2);
		//2
		int x3 = 65; int y3 = 25; string s3 = "el dorado"; int nei3 [10]; int n3 = 2; nei3[0] = 1;nei3[1]=3;
		city city3(x3, y3, s3,nei3,n3);
		//3
		int x4 = 85; int y4 = 20; string s4 = "brady"; int nei4[10]; int n4 = 2; nei4[0] = 2;nei4[1]=4;
		city city4(x4, y4, s4,nei4,n4);
		//4
		int x5 = 95; int y5 = 20; string s5 = "san saba"; int nei5[10]; int n5 = 3; nei5[0] = 3; nei5[1] = 5;nei5[2]=9;
		city city5(x5, y5, s5,nei5,n5);
		//5
		int x6 = 105; int y6 = 17; string s6 = "lampasas"; int *nei6 = new int[20]; int n6 = 2; nei6[0] = 4; nei6[1] = 6;
		city city6(x6, y6, s6,nei6,n6);
		//6
		int x7 = 110; int y7 = 13; string s7 = "meridian"; int nei7[10]; int n7 = 2; nei7[0] = 5; nei7[1] = 7;
		city city7(x7, y7, s7,nei7,n7);
		//7
		int x8 = 120; int y8 = 10; string s8 = "dallas"; int nei8[10]; int n8 = 2; nei8[0] = 6; nei8[1] = 8;
		city city8(x8, y8, s8,nei8,n8);
		//8
		int x9 = 135; int y9 = 5; string s9 = "boston"; int nei9[10]; int n9 = 1; nei9[0] = 7;
		city city9(x9, y9, s9,nei9,n9);
		//9
		int x10 = 100; int y10 = 30; string s10 = "llana"; int nei10[10]; int n10 = 2; nei10[0] = 4; nei10[1] = 10;
		city city10(x10, y10, s10,nei10,n10);
		//10
		int x11 = 110; int y11 = 37; string s11 = "san antonio"; int nei11[10]; int n11 = 2; nei11[0] = 9; nei11[1] = 11;
		city city11(x11, y11, s11,nei11,n11);
		//11
		int x12 = 125; int y12 = 42; string s12 = "beevillee"; int nei12[10]; int n12 = 2; nei12[0] =10; nei12[1] = 12;
		city city12(x12, y12, s12,nei12,n12);
		//12
		int x13 = 125; int y13 =47 ; string s13 = "brownsville"; int nei13[10]; int n13 = 1; nei13[0] = 11;
		city city13(x13, y13, s13,nei13,n13);
		//13
		
		city cities[13];
		cities[0] = city1;
		cities[1] = city2;
		cities[2] = city3;
		cities[3] = city4;
		cities[4] = city5;
		cities[5] = city6;
		cities[6] = city7;
		cities[7] = city8;
		cities[8] = city9;
		cities[9] = city10;
		cities[10] = city11;
		cities[11] = city12;
		cities[12] = city13;
		char *a;
		int n, m;
		m = 50;
		n = 150;
		int flag=1;
		a = (char*)malloc(m*n * sizeof(char));
		while (flag != 0)
		{
			switch (flag)
			{
			case 1:
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{

						*(a + i * n + j) = ' ';
						if (j == 0 || j == 149)
						{
							*(a + i * n + j) = '|';
						}
						if (i == 0 || i == 49)
						{
							*(a + i * n + j) = '-';
						}
						if (j == 0 && i == 0)
						{
							*(a + i * n + j) = '+';
						}
						if (j == 0 && i == 49)
						{
							*(a + i * n + j) = '+';
						}
						if (j == 149 && i == 0)
						{
							*(a + i * n + j) = '+';
						}
						if (j == 149 && i == 49)
						{
							*(a + i * n + j) = '+';
						}
					}
				}
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{

						for (int k = 0; k < 12; k++)
						{
							if (cities[k].ishere(j, i))
							{
								int r = 0;
								*(a + i * n + j) = 'o';
								while (cities[k].name[r] != 0)
								{
									*(a + i * (n)+j + r - 150) = cities[k].name[r];
									r++;
								}
								r = 0;
								if (j == current_positionx && i == current_positiony)
								{
									*(a + i * n + j) = '*';
								}

							}

						}

					}
				}
				/*for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (*(a + i * n + j) == min)
						{
							N++;
							c[N] = j;
						}
					}
				}*/
				/*for (int i = 1; i <= N; i++)
				{
					cout << "J=" << c[i] << endl;
				}
				for (int z = 1; z <= N; z++)
				{
					for (int i = 0; i < m; i++)
					{
						for (int j = c[z] - z + 1; j < n - 1; j++)
						{
							*(a + i * n + j) = *(a + i * n + j + 1);
						}
					}
				}*/
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						cout << *(a + i * n + j);
					}
					cout << endl;
				}
				for (int i = 0; i < 12; i++)
				{
					if (cities[i].ishere(current_positionx, current_positiony))
					{
						int num = 0;
						int j = 0;
						cout << "where do u wanna travel?" << endl;
						for (int j = 0; j < cities[i].numlock; j++)
						{
							cout << cities[cities[i].neighbours[j]].name << " press" << j << endl;
						}
						cout << "if u wanna exit - press 9" << endl;
						cin >> num;
						cout << endl;
						if (num == 9)
						{
							flag = 0;
						}
						else
						{
							current_positionx = cities[cities[i].neighbours[num]].posx;
							current_positiony = cities[cities[i].neighbours[num]].posy;
							num = 0;
							flag = 1;
							break;
						}
					}
				}
				break;
			}
			default:
				flag = 0;
				break;
			}
		}
			free(a);
			delete[]nei1;
			delete[]nei2;
			delete[]nei3;
			delete[]nei4;
			delete[]nei5;
			delete[]nei6;
			delete[]nei7;
			delete[]nei8;
			delete[]nei9;
			delete[]nei10;
			delete[]nei11;
			delete[]nei12;
			delete[]nei13;
	}
	~map() { 
	
	}

};

