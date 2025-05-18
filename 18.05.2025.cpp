#include<iostream>
using namespace std;

template <typename T>
T find_max(T arr[], int size)
{
	T max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

// рекурсия, честно пока что ничего не понятно
int sum_elemets(int arr[], int size)
{
	if (size == 1) 
		return arr[0];
	return arr[size - 1] + sum_elemets(arr, size - 1);
}

// Вибоначи 
void fib(int first, int second, int count)
{
	//static int* arr = new int[count];
	if (count == 0) return;
	cout << first << " ";
	fib(second, first + second, count - 1);
}

// быстрая сортировка

int hoar(int arr[], int left, int right)
{
    //int piv = (arr[left] + arr[right] + arr[(right - left) / 2]) / 2;
    int piv = arr[(right - left) / 2];
    int l = left - 1;
    int r = right + 1;
    while (true)
    {
        do
        {
            l++;
        } while (arr[l] < piv);
        do
        {
            r--;
        } while (arr[r] > piv);

        if (l >= r)
        {
            return r;
        }
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = hoar(arr, left, right);
        quickSort(arr, left, pivot);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
	setlocale(LC_ALL, "ru");
	
	//const int SIZE = 5;
	//int test_arr[SIZE] = {};

	//cout << find_max(test_arr, SIZE);
	//fib(1, 1, 9);
	int arr[10] = { 5,2,1,18,3,46,4,0,-2, 12 };
	quickSort(arr, 0, 9);  
	return 0;
}