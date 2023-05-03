
#include <windows.h>
#include <locale.h>
#include "IntMyArr.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	try 
	{
	IntMyArr arr(3);
	arr.add_element(1);
	arr.add_element(2);
	arr.add_element(3);
	arr.add_element(4);
	arr.add_element(29);

	IntMyArr arr1;

	IntMyArr arr3;

	IntMyArr arr4(arr);
	
	arr3 = arr1 = arr;
	arr1.delete_element(2);
	std::cout << arr1.get_element(3);
	}

	// arr1.copy_arr(arr)
	catch (const std::length_error& ex)
	{
		std::cout << "Length_error: " << ex.what() << std::endl;
	}

	catch (const std::range_error& ex)
	{
		std::cout << "Range_error: " << ex.what() << std::endl;
	}

	catch (const std::exception&)
	{
		std::cout << "Прочие ошибки" << std::endl;
	}
	return 0;
}
