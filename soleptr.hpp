#ifndef SOLEPTR_HPP
#define SOLEPTR_HPP

namespace base
{
/*************************************************************************
SolePtr is a kind of smart pointer that holds the unique pointer.
During copying and assignment operations left-side object owns the pointer,
so right-side object's pointer becomes invalid(more accurate 0).
When object destroys the memory is freed.
**************************************************************************/
template<typename T>
class SolePtr
{
public:
	/// Constructors/Destructor
	SolePtr(T* ptr = 0);
	SolePtr(const SolePtr&);
	~SolePtr();

	/// Assignment operator
	SolePtr& operator=(const SolePtr&);

	/// Dereferecing operators
	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T* operator->() const;

	/// Cast operators
	operator T*();
	operator T* const () const;
	 
	// Method take() sets the internal pointer to NULL and returns previous pointer
	//inline T* take();
	inline T* take() const;
	// Method get() returns the internal pointer
	//inline T* get();
	inline T* get() const;
	// Method reset() deletes the pointer(if not 0) and sets to 0
	inline void reset() const;
private:
	/// The internal pointer to actual data
	/// It is mutable in order to be able to take() pointer from const solpointer object
	mutable T* m_ptr;
}; //class SolePtr

/// Constructor
template<typename T>
SolePtr<T>::SolePtr(T* ptr)
	:m_ptr(ptr)
{
}

/// Copy constuctor
template<typename T>
SolePtr<T>::SolePtr(const SolePtr<T>& other)
{
	// reset this then take the other's pointer
	m_ptr = other.take();
}

// Destuctor
template<typename T>
SolePtr<T>::~SolePtr()
{
	// This method frees memory and sets the internal pointer to 0
	reset();
}

/// Assignment operator
template<typename T>
SolePtr<T>& SolePtr<T>::operator=(const SolePtr<T>& other)
{
	reset();
	m_ptr = other.take();
}

/// Dereferecing operators
template<typename T>
T* SolePtr<T>::operator->()
{
	return m_ptr;
}

template<typename T>
const T* SolePtr<T>::operator->() const
{
	return m_ptr;
}

template<typename T>
T& SolePtr<T>::operator*()
{
	return *m_ptr;
}

template<typename T>
const T& SolePtr<T>::operator*() const
{
	return *m_ptr;
}

// Cast operators
template<typename T>
SolePtr<T>::operator T*()
{
	return  m_ptr;
}

template<typename T>
SolePtr<T>::operator T* const () const 
{
	return m_ptr;
}

// Method take()
template<typename T>
inline T* SolePtr<T>::take() const
{
	T* tmp = m_ptr;
	m_ptr = 0;
	return tmp;
}

// Method get()
template<typename T>
inline T* SolePtr<T>::get() const
{
	return m_ptr;
}

// Method reset()
template<typename T>
inline void SolePtr<T>::reset() const
{
	if (m_ptr != 0)
		delete m_ptr;
	m_ptr = 0;
}

} // namespace base

#endif // SOLEPTR_HPP
