#include "MyForm.h"  
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);  
	Application::Run(gcnew Octavo::MyForm()); //Project 1 es el nombre del proyecto
}


