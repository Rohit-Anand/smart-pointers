//
//  UniquePtr.h
//
//  Created by Rohit Anand on 06/June/2021.
//  Copyright © 2021 Rohit Anand. All rights reserved.
//

#ifndef _MYUNIQUE_PTR_H_
#define _MYUNIQUE_PTR_H_

#include <iostream>

template <class T>
class UniquePtr {
private:
	T* myObj;
	UniquePtr() = delete;

	T* operator=(T* obj)
	{
		std::cout << "Assignment operator is triggered" << std::endl;
		myObj = obj;
		return myObj;
	}

public:
	UniquePtr(T* obj)
	{
		myObj = obj;
		std::cout << "Unique_Ptr Ctor" << std::endl;
	}

	UniquePtr<T>(UniquePtr<T>&& obj) noexcept
		: myObj(obj.get())
	{
		std::cout << "Move Ctor triggered" << std::endl;
		obj = nullptr;
	}

	UniquePtr<T>& operator=(UniquePtr<T>&& uptr) noexcept
	{
		myObj = *(obj.get());
		obj = nullptr;
	}

	~UniquePtr()
	{
		delete myObj;
		myObj = nullptr;
	}

	UniquePtr<T>& operator=(UniquePtr<T>& obj) = delete;
	UniquePtr<T>(const UniquePtr<T>& obj) = delete;

	T* operator->() const noexcept
	{ // Arrow Operator
		return myObj; }

	T* get() const noexcept
	{
		return myObj;
	}
};

#endif // !_MYUNIQUE_PTR_H_