#pragma once
#include "define.h"
#define Stackmaxsize 100

namespace classstack {
	template<typename T>
	class SqStack
	{
	private:
		T* base;
		T* top;
		const int maxsize = Stackmaxsize;
	public:
		SqStack() {
			base = new T;
			top = base;
		}
		~SqStack() {
			while (top != base)
			{
				T* P = top;
				top--;
				//delete(P);
			}
		}
		bool Push(T e) {
			*(top++) = e;
			return TRUE;
		}
		T Pop() {
			T e = *(--top);
			return e;
		}
		bool IsEmpty() const {
			if (top == base)
				return TRUE;
			else
				return FALSE;
		}
		bool IsFull()const {
			if (top - base == maxsize)
				return TRUE;
			else
				return FALSE;
		}
		T GetTop() const {
			return *(top - 1);
		}
	};

	template<typename T>
	struct StackNode {
		T data;
		StackNode* next;
	};

	template<typename T>
	class LinkStack {
	public:
		LinkStack();
		~LinkStack();
		bool IsEmpty() const;
		void Push(const T& e);
		T Pop();
		T GetTop() const;

	private:
		StackNode<T>* top_;
	};

	template<typename T>
	LinkStack<T>::LinkStack()
	{
		top_ = nullptr;
	}

	template<typename T>
	LinkStack<T>::~LinkStack()
	{
		while (top_ != nullptr) {
			StackNode<T>* p = top_;
			top_ = top_->next;
			delete p;
		}
	}

	template<typename T>
	bool LinkStack<T>::IsEmpty() const
	{
		return top_ == nullptr;
	}

	template<typename T>
	void LinkStack<T>::Push(const T& e)
	{
		StackNode<T>* p = new StackNode<T>;
		p->data = e;
		p->next = top_;
		top_ = p;
	}

	template<typename T>
	T LinkStack<T>::Pop()
	{
		if (IsEmpty()) {
			return false;
		}
		StackNode<T>* p = top_;
		T e = p->data;
		top_ = top_->next;
		delete p;
		return e;
	}

}