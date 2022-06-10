/*AISHA IRFAN
20I - 1851
CY - T */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void display(char** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << endl;
	}
	std::cout << endl << endl;
}
void initialization(char** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rand() % 10 <= 6)
			{
				arr[i][j] = '*';
			}
			else
			{
				arr[i][j] = ' ';
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int const n = 30;
	//dynamic memory allocation
	char** arr = new char* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[n];
	}
	initialization(arr, n);
	display(arr, n);
	//updating each cell
	while(true)
	{
		char temp[n][n];//temporary array to store updated cell
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = arr[i][j];
			}
		}
		for (int row = 0; row < n ; row++)
		{
			for (int col = 1;col < n; col++)
			{
				int count = 0;
				//update checks for the 4 corners of the array
				if (row == 0 && col == 0)
				{
					if (arr[row][col + 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col] == '*')
					{
						count++;
					}
					if (arr[row + 1][col + 1] == '*')
					{
						count++;
					}

				}
				else if (row == 0 && col == n - 1)
				{
					if (arr[row][col - 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col] == '*')
					{
						count++;
					}
				}

				else if (row == n - 1 && col == 0)
				{
					if (arr[row - 1][col] == '*')
					{
						count++;
					}
					if (arr[row - 1][col + 1] == '*')
					{
						count++;
					}
					if (arr[row][col + 1] == '*')
					{
						count++;
					}
				}
				else if (row == n - 1 && col == n - 1)
				{
					if (arr[row - 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row - 1][col] == '*')
					{
						count++;
					}
					if (arr[row][col - 1] == '*')
					{
						count++;
					}
				}
				//update checks for the edges of the array
				else if (row == 0)
				{
					if (arr[row][col - 1] == '*')
					{
						count++;
					}
					if (arr[row][col + 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col] == '*')
					{
						count++;
					}
					if (arr[row + 1][col + 1] == '*')
					{
						count++;
					}
				}
				else if (row == n - 1)
				{
					if (arr[row - 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row - 1][col] == '*')
					{
						count++;
					}
					if (arr[row - 1][col + 1] == '*')
					{
						count++;
					}
					if (arr[row][col - 1] == '*')
					{
						count++;
					}
					if (arr[row][col + 1] == '*')
					{
						count++;
					}
				}
				else if (col == 0)
				{
					if (arr[row - 1][col] == '*')
					{
						count++;
					}
					if (arr[row - 1][col + 1] == '*')
					{
						count++;
					}
					if (arr[row][col + 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col] == '*')
					{
						count++;
					}
					if (arr[row + 1][col + 1] == '*')
					{
						count++;
					}
				}
				else if (col == n - 1)
				{
					if (arr[row - 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row - 1][col] == '*')
					{
						count++;
					}
					if (arr[row][col - 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col] == '*')
					{
						count++;
					}
				}
				//updating cells other than those present on the border
				else
				{
					if (arr[row - 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row - 1][col] == '*')
					{
						count++;
					}
					if (arr[row - 1][col + 1] == '*')
					{
						count++;
					}
					if (arr[row][col - 1] == '*')
					{
						count++;
					}
					if (arr[row][col + 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col - 1] == '*')
					{
						count++;
					}
					if (arr[row + 1][col] == '*')
					{
						count++;
					}
					if (arr[row + 1][col + 1] == '*')
					{
						count++;
					}
				}
				//updating alive and dead status of cell
				if (count <= 1)
				{
					temp[row][col] = ' ';
				}
				if ((arr[row][col] == '*') && (count == 2 || count == 3))
				{
					temp[row][col] = '*';
				}
				if ((arr[row][col] == ' ') && count == 3)
				{
					temp[row][col] = '*';
				}
				else if (count > 3)
				{
					temp[row][col] = ' ';
				}
			}
		}
		//copying temp array back to original array
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = temp[i][j];
			}
		}
		display(arr, n);
		std::cout << endl << endl << endl;
		Sleep(2*1000);//pause
	}
	return 0;
}