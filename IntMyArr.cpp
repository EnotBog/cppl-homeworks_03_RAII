#include "IntMyArr.h"


IntMyArr::IntMyArr() :m_size(0), m_count(0)
	{
		p_arr = nullptr;
	}
IntMyArr::IntMyArr(int size) :m_size(size), m_count(0)
	{
		p_arr = new int[m_size];
	}

	IntMyArr::~IntMyArr() { delete p_arr; };

	void IntMyArr::copy_arr(IntMyArr& arr_in)
	{
		this->m_count = arr_in.m_count;
		this->m_size = arr_in.m_size;
		this->p_arr = new int[m_size];
		for (int i = 0; i < m_count; i++)
		{
			p_arr[i] = arr_in.p_arr[i];
		}
	}

	void IntMyArr::delete_element(int x)
	{
		if (p_arr == nullptr) { throw std::length_error("Отсутсвует массив"); }
		if (x >= m_count || x < 0) { throw std::range_error("Выход за пределы массива!"); }
		if (x == m_count) { p_arr[x] = 0; m_count -= 1; }
		//int ind = 1 + x; // индекс следующего значения за удаляемым
		int count_move = m_count - x;// колличество элементов к движению
		m_count -= 1;
		//скольтко элементов передвинуть 5[4] ужалить третий [2] 4-2 2 
		//индекс куда двигать

		for (int i = x; count_move > 0; i++, count_move--)
			p_arr[i] = p_arr[i + 1];
	}

	void IntMyArr::add_element(int x)
	{
		if (m_count + 1 > m_size)
		{
			increase_arr(m_count, m_size + m_size / 2);
			p_arr[m_count] = x; ++m_count;
			//for (int i = 0; i < m_size; ++i) { std::cout << p_arr[i]; std::cout << "\n"; }
		}
		else
		{
			p_arr[m_count] = x; ++m_count;
		}
	}

	int IntMyArr::get_element(int x) const
	{
		if (p_arr == nullptr) { throw std::length_error("Отсутсвует массив"); }
		if (x >= m_count || x < 0) { throw std::range_error("Выход за пределы массива!"); }
		return p_arr[x];
	}

	void IntMyArr::increase_arr(int count, int new_size)
	{
		int* p_arr_buf = new int[new_size] {0};
		for (int i = 0; i < count; ++i)
		{
			p_arr_buf[i] = p_arr[i];
		}
		m_size = new_size;

		delete[] p_arr;

		p_arr = p_arr_buf;
		p_arr_buf = nullptr;

	}


