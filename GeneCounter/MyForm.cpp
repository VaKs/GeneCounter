#include "MyForm.h"

#include "opencv2\opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

using namespace cv;
using namespace std;

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThread]
int main(cli::array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GeneCounter::MyForm form;
	Application::Run(%form);
	return 0;
}
