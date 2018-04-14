#pragma once
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
namespace GeneCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lName;
	private: System::Windows::Forms::TextBox^  txtBoxName;
	private: System::Windows::Forms::Button^  btnSiembralo;
	private: System::Windows::Forms::PictureBox^  imgBox;
	private: System::Windows::Forms::TrackBar^  trackBarPercentil;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->lName = (gcnew System::Windows::Forms::Label());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->btnSiembralo = (gcnew System::Windows::Forms::Button());
			this->imgBox = (gcnew System::Windows::Forms::PictureBox());
			this->trackBarPercentil = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarPercentil))->BeginInit();
			this->SuspendLayout();
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Location = System::Drawing::Point(858, 67);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(35, 13);
			this->lName->TabIndex = 0;
			this->lName->Text = L"label1";
			// 
			// txtBoxName
			// 
			this->txtBoxName->Location = System::Drawing::Point(861, 27);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(100, 20);
			this->txtBoxName->TabIndex = 1;
			// 
			// btnSiembralo
			// 
			this->btnSiembralo->Location = System::Drawing::Point(886, 480);
			this->btnSiembralo->Name = L"btnSiembralo";
			this->btnSiembralo->Size = System::Drawing::Size(75, 23);
			this->btnSiembralo->TabIndex = 2;
			this->btnSiembralo->Text = L"button1";
			this->btnSiembralo->UseVisualStyleBackColor = true;
			this->btnSiembralo->Click += gcnew System::EventHandler(this, &MyForm::btnSiembralo_Click);
			// 
			// imgBox
			// 
			this->imgBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgBox.Image")));
			this->imgBox->Location = System::Drawing::Point(12, 12);
			this->imgBox->Name = L"imgBox";
			this->imgBox->Size = System::Drawing::Size(693, 414);
			this->imgBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgBox->TabIndex = 3;
			this->imgBox->TabStop = false;
			// 
			// trackBarPercentil
			// 
			this->trackBarPercentil->Location = System::Drawing::Point(824, 353);
			this->trackBarPercentil->Name = L"trackBarPercentil";
			this->trackBarPercentil->Size = System::Drawing::Size(104, 45);
			this->trackBarPercentil->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(973, 515);
			this->Controls->Add(this->trackBarPercentil);
			this->Controls->Add(this->imgBox);
			this->Controls->Add(this->btnSiembralo);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->lName);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarPercentil))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btnSiembralo_Click(System::Object^  sender, System::EventArgs^  e) {
		lName->Text = txtBoxName->Text;
		Mat img = imread("./img/4.bmp", CV_LOAD_IMAGE_COLOR);
		showImage(img);
		
	}
	void showImage(Mat img) {
		imwrite("./img/temp/temp.bmp", img);
		imgBox->Image = System::Drawing::Image::FromFile("./img/temp/temp.bmp");
		/*
		imgBox->Image = gcnew Bitmap(img.size().width,
									 img.size().height,
									 img.step,
									 Imaging::PixelFormat::Format24bppRgb,
									 (IntPtr)img.data);
		*/
	}
	void saveImage(string name,Mat img) {
		imwrite("./img/temp/"+name+".bmp", img);
	}
	};
	
}
