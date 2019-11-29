#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_3.h"

#include "cl_2.h"

#include "cl_4.h"

#include "cl_1.h"

//using namespace std;

class cl_application: public cl_base
{
public: cl_application();
	//   ~cl_application ( );
	
	void bild_tree_objects();
	int exec_app();
private: cl_base * p_ob;
	cl_3 * p_ob_3;
	cl_4 * p_ob_4;
	cl_2 * p_ob_2;
	cl_1 * p_ob_1;
	int k;
};

#endif // CL_APPLICATION_H
