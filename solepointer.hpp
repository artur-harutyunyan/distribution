#ifndef SOLEPOINTER_HPP
#define SOLEPOINTER_HPP

namespace base
{
/******************
solepointer is a kind of smart pointer that holds the unique pointer.
During copying and assignment operations left-side object owns the pointer,
so right-side object's pointer becomes invalid(more accurate 0).
When object destroys the memory is freed.
*****************/
template<typename T>
class solepointer
{
public:
	/// Constructors/Destructor
	solepointer(T* ptr = 0);
	solepointer(const solepointer&);
	~solepointer();

	/// Assignment operator
	solepointer& operator=(const solepointer&);

	/// Dereferecing operators
	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T* operator->() const;

	/// Cast operators
	operator T*();
	operator T* const () const;
	 
	// Method take() sets the internal pointer to NULL and returns previous pointer
	inline T* take();
	// Method get() returns the internal pointer
	inline T* get();
private:
	/// The internal pointer to actual data
	/// It is mutable in order to be able to take() pointer from const solpointer object
	mutable T* m_ptr;
}; //class solepointer

/// Constructor
template<typename T>
solepointer<T>::solepointer(T* ptr)
	:m_ptr(ptr)
{
}

/// Copy constuctor
template<typename T>
solepointer<T>::solepointer(const solepointer<T>& other)
{
	m_ptr = const_cast<solepointer<T>& >(other).take();
}

// Destuctor
template<typename T>
solepointer<T>::~solepointer()
{
	if(m_ptr != 0)
		delete m_ptr;
}

/// Assignment operator
template<typename T>
solepointer<T>& solepointer<T>::operator=(const solepointer<T>& other)
{
	m_ptr = const_cast<solepointer<T>& >(other).take();
}

/// Dereferecing operators
template<typename T>
T* solepointer<T>::operator->()
{
	return m_ptr;
}

template<typename T>
const T* solepointer<T>::operator->() const
{
	return m_ptr;
}

// Cast operators
template<typename T>
solepointer<T>::operator T*()
{
	return  m_ptr;
}

template<typename T>
solepointer<T>::operator T* const () const 
{
	return m_ptr;
}

// Method take()
template<typename T>
inline T* solepointer<T>::take()
{
	T* tmp = m_ptr;
	m_ptr = 0;
	return tmp;
}

// Method get()
template<typename T>
inline T* solepointer<T>::get()
{
	return m_ptr;
}

template<typename T>
T& solepointer<T>::operator*()
{
	return *m_ptr;
}

template<typename T>
const T& solepointer<T>::operator*() const
{
	return *m_ptr;
}

} // namespace base

#endif // SOLEPOINTER_HPP
