#include "MainWindow.h"
#include "UserData.h"
using namespace System;
using namespace System::Windows::Forms;

[System::STAThreadAttribute]
int main(array<String^> ^args)
{
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(0);
        Semestrovaya::MainWindow form;
        Application::Run(% form);
}


