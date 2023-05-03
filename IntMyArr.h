#pragma once
#include <iostream>

class IntMyArr
{
public:
	IntMyArr();
	IntMyArr(int size);
	~IntMyArr();

	void copy_arr(IntMyArr& arr_in);

	void delete_element(int x);

	void add_element(int x);

	int get_element(int x) const;

	void increase_arr(int count, int new_size);

private:
	int m_size;
	int m_count;
	int* p_arr;

};