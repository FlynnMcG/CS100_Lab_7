#include <iostream>
#include <stack>
//#include "composite.h"

class  Iterator
{
	protected :
		Base* self_ptr;
		Base* current_ptr;
	public :
		Iterator  (Base* ptr)
		{
			this->self_ptr  = ptr;
			this->current_ptr = self_ptr;
		}

		/*Sets up the iterator to start at the beginning of traversal*/
		virtual  void first()  =  0;
		/*Move on to the next element*/
		virtual  void  next()  =  0;
		/*Returns if you have finished iterating through all elements*/
		virtual  bool is_done() = 0;
 		/*Return the element the iterator is currently at*/
		virtual  Base * current() = 0;
 };

 class  OperatorIterator  :  public  Iterator
 {
 	public:
		OperatorIterator (Base * ptr);
		
		void first()
		{
			current_ptr = self_ptr->getleft();
		};
		void  next()
		{
			if (current_ptr == self_ptr->getleft())
			{
				current_ptr = self_ptr->getright();
			}
			else if (current_ptr == self_ptr->getright())
			{
				current_ptr = NULL;
			}
		};
		bool is_done()
		{
			if (current_ptr == NULL)
			{
				return true;
			}
			return false;
		};
		Base * current()
		{
			return current_ptr;
		};
};

class UnaryIterator : public Iterator
{
	public:
		UnaryIterator(Base* ptr);
		
		void first();
		void next();
		bool is_done();
		Base* current();
};

class NullIterator : public Iterator
{
	public:
		NullIterator(Base* ptr);
		
		void first();
		void next();
		bool is_done();
		Base* current();
};

class PreOrderIterator : public Iterator
{
	protected:
		stack<Iterator*> iterators;

	public:
		PreOrderIterator(Base* ptr);
		
		void first();
		void next();
		bool is_done();
		Base* current();
};

/*
void PreOrderIterator::first()
{

}

void PreOrderIterator::next()
{
	
}

bool PreOrderIterator::is_done()
{
	
}

Base* PreOrderIterator::current()
{
	
}
*/
