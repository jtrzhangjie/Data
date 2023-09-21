//
// Created by Joyce on 9/21/2023.
//

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

namespace DTLib
{
template <typename T>
class SmartPointer
{
protected:
	T* m_pointer;

public:
	SmartPointer(T* p = NULL)
	{
		m_pointer = p;
	}

	SmartPointer(const SmartPointer<T>& obj)
	{
		m_pointer = obj.m_pointer;
		const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
	}

	SmartPointer<T>& operator= (const SmartPointer<T>& obj)
	{
		if(this != &obj)
		{
			delete m_pointer;
			m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
		}

		return *this; // 支持连续的赋值
	}

	T* operator->()
	{
		return m_pointer;
	}

	T& operator*()
	{
		return *m_pointer;
	}

	bool isNull()
	{
		return (m_pointer == NULL);
	}

	T* get()
	{
		return m_pointer;
	}

	~SmartPointer()
	{
		delete m_pointer;
	};
};
}  // namespace DTLib

#endif	// L09_SMARTPOINTER_H
