#include "IntMyArr.h"

IntMyArr::IntMyArr(const IntMyArr& other)
{
	this->m_count = other.m_count;
	this->m_size = other.m_size;
	
	if (this->p_arr != nullptr) { delete[]this->p_arr; }
	this->p_arr = new int[m_size];

	for (int i = 0; i < m_count; i++)
	{
		p_arr[i] = other.p_arr[i];
	}
}

IntMyArr::IntMyArr() :m_size(0), m_count(0)
	{
		p_arr = nullptr;
	}
IntMyArr::IntMyArr(int size) :m_size(size), m_count(0)
	{
		p_arr = new int[m_size];
	}

	IntMyArr::~IntMyArr() { delete[] p_arr; };

	IntMyArr& IntMyArr::operator=(const IntMyArr& other)
	{
		if (this == &other) { return *this; }

		this->m_count = other.m_count;
		this->m_size = other.m_size;

		if (this->p_arr != nullptr) { delete[]this->p_arr; }
		this->p_arr = new int[m_size];

		for (int i = 0; i < m_count; i++)
		{
			p_arr[i] = other.p_arr[i];
		}

		return *this;
	};

	void IntMyArr::delete_element(int x)
	{
		if (p_arr == nullptr) { throw std::length_error("Отсутсвует массив"); }
		if (x >= m_count || x < 0) { throw std::range_error("Выход за пределы массива!"); }
		if (x == m_count) { p_arr[x] = 0; m_count -= 1; }
	
		int count_move = m_count - x;// колличество элементов к движению
		m_count -= 1;	//скольтко элементов передвинуть 5[4] ужалить третий [2] 4-2 2 
		

		for (int i = x; count_move > 0; i++, count_move--)
			p_arr[i] = p_arr[i + 1];
	}

	void IntMyArr::add_element(int x)
	{
		if (m_count + 1 > m_size)
		{
			increase_arr(m_count, m_size + m_size / 2);
			p_arr[m_count] = x; ++m_count;
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


