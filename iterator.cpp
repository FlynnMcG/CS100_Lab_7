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
};
bool OperatorIterator :: is_done(){
	if (current_ptr == NULL)
	{
		return true;
	}
	return false;
};
Base* OperatorIterator :: current() { return current_ptr; };

//--------------------------------------------------------------------------
// Unary Iterator Class
//--------------------------------------------------------------------------
void UnaryIterator :: first() { current_ptr = self_ptr->getleft(); };
void UnaryIterator :: next() { current_ptr = NULL; };
bool UnaryIterator :: is_done(){
	if (current_ptr == NULL)
	{
		return true;
	}
	return false;
};
Base* UnaryIterator :: current() { return current_ptr; };

//--------------------------------------------------------------------------
// Null Iterator Class
//--------------------------------------------------------------------------
void NullIterator :: first() {};
void NullIterator :: next() {};
bool NullIterator :: is_done() { return true };
Base* NullIterator :: current() { return NULL; };

//--------------------------------------------------------------------------
// Pre Order Iterator Class
//--------------------------------------------------------------------------
void PreOrderIterator :: first() {
	while (!iterators.empty())
		iterators.pop();
	Iterator ite = self_ptr->create_iterator();
	ite->first();
	iterators.push(ite);
};
void PreOrderIterator :: next() {
	Iterator ite = iterators.top()->current()->create_iterator();
	ite->first();
	iterators.push(ite);
	while (!iterators.empty() && iterators.top()->is_done()) {
		iterators.pop();
		if (!iterators.empty())
			iterators.top()->next();
	}
};
bool PreOrderIterator :: is_done() {
	return true
};
Base* PreOrderIterator :: current() {
	return iterators.top()->current();
};








