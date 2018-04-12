#pragma once
#include "mainForm.h"
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

namespace GeneCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
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
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnSiembralo;
	protected:
	private: System::Windows::Forms::TextBox^  txtBoxName;
	private: System::Windows::Forms::Label^  lName;

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
			this->btnSiembralo = (gcnew System::Windows::Forms::Button());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSiembralo
			// 
			this->btnSiembralo->Location = System::Drawing::Point(97, 194);
			this->btnSiembralo->Name = L"btnSiembralo";
			this->btnSiembralo->Size = System::Drawing::Size(75, 23);
			this->btnSiembralo->TabIndex = 0;
			this->btnSiembralo->Text = L"Siembralo";
			this->btnSiembralo->UseVisualStyleBackColor = true;
			this->btnSiembralo->Click += gcnew EventHandler(this, &mainForm::Button_Click);
			// 
			// txtBoxName
			// 
			this->txtBoxName->Location = System::Drawing::Point(97, 95);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(100, 20);
			this->txtBoxName->TabIndex = 1;
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Location = System::Drawing::Point(97, 144);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(35, 13);
			this->lName->TabIndex = 2;
			this->lName->Text = L"label1";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->btnSiembralo);
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		[STAThread]
		static void main()
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			GeneCounter::mainForm form;
			Application::Run(%form);
		}
	private:
		void Button_Click(Object^ sender, EventArgs^ e)
		{
			lName->Text = txtBoxName->Text;
		}
	};
	void main(array<String^>^ args)
	{
		mainForm::main();
	}

}
