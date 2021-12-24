#pragma once
#include <iostream>
#include <string>
#include <fstream>

std::string a;
bool isfull = false;

int **read_to_text(const char *fileName, int &rowsCount, int & colomnsCount)
{
	std::fstream f;
	f.open(fileName, std::ios::in);
	f >> rowsCount;
	f >> colomnsCount;

	int **mas = new int*[rowsCount];
	for (int i = 0; i < rowsCount; ++i)
	{
		mas[i] = new int[colomnsCount] {};
	}
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < colomnsCount; j++)
		{
			f >> mas[i][j];
		}
	}
	f.close();
	return mas;
}

void TruePullArray(bool** array, int i, int j)
{
	for (int q = 0; q < i; ++q)
	{
		for (int qq = 0; qq < j; ++qq)
		{
			array[q][qq] = true;
		}
	}
}

bool WayToString(int i, int j, int _i, int _j)
{
	if (_i == i + 1)
	{
		if (a[a.size() - 1] == 'u')
			a.erase(a.size() - 1);
		else
			a.push_back('d');
	}
	if (_i == i - 1)
	{
		if (a[a.size() - 1] == 'd')
			a.erase(a.size() - 1);
		else
			a.push_back('u');
	}
	if (_j == j + 1)
	{
		if (a[a.size() - 1] == 'l')
			a.erase(a.size() - 1);
		else
			a.push_back('r');
	}
	if (_j == j - 1)
	{
		if (a[a.size() - 1] == 'r')
			a.erase(a.size() - 1);
		else
			a.push_back('l');
	}
	return true;
}
bool Way(int i, int j, int **maze, int rowsCount, int columnsCount, bool** attend)
{
	attend[i][j] = true;
	int leftright[4]{ 1, 0 , -1, 0 };
	int UpDown[4]{ 0, 1, 0 , -1 };
	for (int k = 0; k < 4; ++k)
	{
		int _i = i + UpDown[k];
		int _j = j + leftright[k];
		if (maze[_i][_j] != 1 && !attend[_i][_j])
		{
			WayToString(i, j, _i, _j);
			Way(_i, _j, maze, rowsCount, columnsCount, attend);
		}
		if (i == rowsCount - 2 && j == columnsCount - 2)
		{
			TruePullArray(attend, rowsCount, columnsCount);
			isfull = true;
			break;
		}
	}
	if (isfull == false)
	{
		a.erase(a.size() - 1);
	}
	return true;
}

std::string Maze(const char *fileName)
{
	isfull = false;
	a = "The way is: ";

	int rowsCount, columnsCount;
	int** maze = read_to_text(fileName, rowsCount, columnsCount);

	bool **attend = new bool*[rowsCount];
	for (int i = 0; i < rowsCount; ++i)
	{
		attend[i] = new bool[columnsCount] {};
	}

	Way(1, 1, maze, rowsCount, columnsCount, attend);
	if (isfull == false)
	{
		a = "Bad Way";
	}
	return a;
}
