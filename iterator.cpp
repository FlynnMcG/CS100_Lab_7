#include "iterator.h"

//--------------------------------------------------------------------------
// Operator Iterator Class
//--------------------------------------------------------------------------
void OperatorIterator :: first() { current_ptr = self_ptr->getleft(); };
void OperatorIterator :: next(){
	if (current_ptr == self_ptr->getleft())
	{
		current_ptr = self_ptr->getright();
	}
	else if (current_ptr == self_ptr->getright())
	{
		current_ptr = NULL;
	}
}
bool OperatorIterator :: is_done(){
	if (current_ptr == NULL)
	{
		return true;
	}
	return false;
}
Base* current() { return current_ptr; };

/*
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
		std :: stack<Iterator*> iterators;

	public:
		PreOrderIterator(Base* ptr);
		
		void first();
		void next();
		bool is_done();
		Base* current();
};
*/

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
