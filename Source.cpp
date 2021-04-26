#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <Vector>

using namespace std;

void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("pythonfile");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	Py_Initialize();
	pName = PyUnicode_FromString((char*)"pythonfile");
	pModule = PyImport_Import(pName);
	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}

	Py_DECREF(pValue);
	Py_DECREF(pModule);
	Py_DECREF(pName);
	Py_Finalize();

	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	
	Py_Initialize();
	pName = PyUnicode_FromString((char*)"pythonfile");
	
	pModule = PyImport_Import(pName);
	
	pDict = PyModule_GetDict(pModule);
	
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}

	Py_DECREF(pValue);
	Py_DECREF(pModule);
	Py_DECREF(pName);
	Py_Finalize();
	delete[] procname;

	return _PyLong_AsInt(presult);
}



string makeString(vector<string> groceryVector) {

	string foodieString = "";
	int i;
	for (i = 0; i < groceryVector.size(); i++) {

		foodieString = foodieString + " " + groceryVector[i];


	}

	return foodieString;
}
void displayMenu() {

	cout << "1: Printing Items " << endl;
	cout << "2: Search for quantity " << endl;
	cout << "3: Print Histogram" << endl;
	cout << "4: Quit" << endl;
	cout << "Please enter | 1 | 2 | 3 | 4 |: ";
}


void main()
{
	vector<string> groceryVector;
	int userNum = 0;
	fstream newfile;
	newfile.open("input.txt", ios::in); 
	if (newfile.is_open()) {   
		string tp;
		while (getline(newfile, tp)) { 
			groceryVector.push_back(tp);
		}
		newfile.close(); 
	}
	
	while (userNum != 4) {

		displayMenu();
		cin >> userNum;
		if (userNum == 1) {
			int x = callIntFunc("oneCount", makeString(groceryVector));

		}
		if (userNum == 2) {
			int x = callIntFunc("srchCount", makeString(groceryVector));
		}
		if (userNum == 3) {
			int x = callIntFunc("hGram", makeString(groceryVector));

		}
		if (userNum == 4) {
			break;
		}
	}
}