#ifndef MY_SHARED_PTR_HPP
#define MY_SHARED_PTR_HPP

#include <iostream>
#include <stdint.h>

template <typename T>
class my_shared_ptr
{
	public:
	my_shared_ptr():m_pRawPtr(NULL),m_refCount(NULL)
	{
	}

	my_shared_ptr(T* ptr)
	{
		m_pRawPtr = ptr;
		m_refCount = new size_t(1);
	}

	my_shared_ptr(const my_shared_ptr<T>& pPtr)
	{
		m_pRawPtr = pPtr.get();
		m_refCount = pPtr.getRef();
		(*m_refCount)++;
	}

	~my_shared_ptr()
	{
		(*m_refCount)--;

		if(*m_refCount == 0)
			delete m_pRawPtr;
	}
	
	T* 			get() const
	{
		return m_pRawPtr;
	}

	size_t*		getRef() const
	{
			return m_refCount;
	}

	size_t use_count() const
	{
		return *m_refCount;
	}

	T* operator->() const
	{
		return m_pRawPtr;
	}

	T& operator*()
	{
		return *m_pRawPtr;
	}
	
	private:
	T* 					m_pRawPtr;
	size_t*				m_refCount;
};

#endif
