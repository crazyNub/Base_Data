#include "cl_base.h"

#include <iomanip>

cl_base::cl_base(cl_base * p_parent)
{
	//-------------------------------------------------------------------------
	// Констрктор
	//-------------------------------------------------------------------------
	
	set_object_name("cl_base");
	
	if(p_parent)
	{
		this->p_parent = p_parent;
		p_parent->add_child(this);
	}
	else
	{
		this->p_parent = 0;
	}
}

void cl_base::set_object_name(string s_object_name)
{
	//-------------------------------------------------------------------------
	// Присвоить имя объекта
	//-------------------------------------------------------------------------
	
	object_name = s_object_name;
}

string cl_base::get_object_name()
{
	//-------------------------------------------------------------------------
	// получить имя объекта
	//-------------------------------------------------------------------------
	
	return object_name;
}

void cl_base::set_parent(cl_base * p_parent)
{
	//-------------------------------------------------------------------------
	// Определение ссылки на объект
	//-------------------------------------------------------------------------
	
	if(p_parent)
	{
		this->p_parent = p_parent;
		p_parent->children.push_back(this);
	}
}

void cl_base::add_child(cl_base * p_child)
{
	//-------------------------------------------------------------------------
	// добавление нового объекта в перечне объектов-потомков
	//-------------------------------------------------------------------------
	
	this->children.push_back(p_child);
}

void cl_base::delete_child(string s_object_name)
{
	//-------------------------------------------------------------------------
	// удаление объекта из перечня объектов-потомков
	//-------------------------------------------------------------------------
	
	if(children.size() == 0) return;
	
	it_child = children.begin();
	
	while(it_child != children.end())
	{
		
		if((*it_child)->get_object_name() == s_object_name)
		{
			
			children.erase(it_child);
			return;
		}
		it_child++;
	}
}

cl_base * cl_base::take_child(string s_object_name)
{
	//-------------------------------------------------------------------------
	// удалить подчиненый объект и вернуть ссылку
	//-------------------------------------------------------------------------
	cl_base * ob_child;
	//-------------------------------------------------------------------------
	
	ob_child = get_child(s_object_name);
	
	if(ob_child == 0) return 0;
	
	delete_child(s_object_name);
	
	return ob_child;
}

cl_base * cl_base::get_child(string s_object_name)
{
	//-------------------------------------------------------------------------
	// получить ссылку на объект потомок по имени объекта
	//-------------------------------------------------------------------------
	
	if(children.size() == 0) return 0;
	
	it_child = children.begin();
	
	while(it_child != children.end())
	{
		
		if((*it_child)->get_object_name() == s_object_name)
		{
			
			return (*it_child);
		}
		it_child++;
	}
	
	return 0;
}

void cl_base::set_state(int i_state)
{
	//-------------------------------------------------------------------------
	// определить состояние объекта
	//-------------------------------------------------------------------------
	
	this->i_state = i_state;
}

int cl_base::get_state()
{
	//-------------------------------------------------------------------------
	// получить состояние объекта
	//-------------------------------------------------------------------------
	
	return i_state;
}


void cl_base::show_object_state()
{
	show_state_next((cl_base*)this);
}

void cl_base::show_object_name()
{
	show_name_next((cl_base*)this);
}

int cl_base::get_object_level()
{
	//-------------------------------------------------------------------------
	// получить уровень , на котором находится объект
	//-------------------------------------------------------------------------

	if(p_parent == 0)
		return 0;
	int level = 1;
	cl_base * p_parent_previous = p_parent; //ссылка на очередой головной элемент
	while(p_parent_previous->p_parent)
	{
		level++;
		p_parent_previous = p_parent_previous->p_parent;
	}
	
	return level;
}


//     =====     private:     =====
cl_base * cl_base::get_object_root()
{
	//--------------------------------------------------------------------------
	//  ссылка на корневой объект
	//--------------------------------------------------------------------------
	cl_base * p_parent_previous; // ссылка на очередной объект
	//--------------------------------------------------------------------------
	
	if(p_parent == 0) return this;
	
	p_parent_previous = p_parent;
	
	while(p_parent_previous->p_parent)
	{
		
		p_parent_previous = p_parent_previous->p_parent;
	}
	
	return p_parent_previous;
}
	
	
void cl_base::show_state_next(cl_base * ob_parent)
{
	//-------------------------------------------------------------------------
	// вывод готовности очередного объекта в цикле
	//-------------------------------------------------------------------------
	
	if(ob_parent->get_state() == 1)
	{
		
		cout << "The object " << ob_parent->get_object_name() << " is ready" << endl;
	}
	else
	{
		
		cout << "The object " << ob_parent->get_object_name() << " is not ready" << endl;
	}
	
	if(ob_parent->children.size() == 0) return;
	
	ob_parent->it_child = ob_parent->children.begin();
	
	while(ob_parent->it_child != ob_parent->children.end())
	{
		
		show_state_next((*(ob_parent->it_child)));
		
		ob_parent->it_child++;
	}
}

void cl_base::show_name_next(cl_base * ob_parent)
{
	//---------------------------------------------------------------------------
	// вывод очередного объекта в цикле обхода дерева
	//---------------------------------------------------------------------------
	int level = ob_parent->get_object_level();
	
	if(level == 0)
	{
		cout << ob_parent->get_object_name();
	}
	else
	{
		cout << endl << setfill(' ') << setw(level * 4) << " " << ob_parent->get_object_name();
	}
	
	if(ob_parent->children.size() == 0)
		return;
		
	ob_parent->it_child = ob_parent->children.begin();
	
	while(ob_parent->it_child != ob_parent->children.end())
	{
		
		show_name_next((*(ob_parent->it_child)));
		
		ob_parent->it_child++;
	}
}
