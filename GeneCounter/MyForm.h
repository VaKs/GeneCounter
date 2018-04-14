#pragma once

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
			this->lName = (gcnew System::Windows::Forms::Label());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->btnSiembralo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Location = System::Drawing::Point(121, 117);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(35, 13);
			this->lName->TabIndex = 0;
			this->lName->Text = L"label1";
			// 
			// txtBoxName
			// 
			this->txtBoxName->Location = System::Drawing::Point(91, 63);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(100, 20);
			this->txtBoxName->TabIndex = 1;
			// 
			// btnSiembralo
			// 
			this->btnSiembralo->Location = System::Drawing::Point(101, 165);
			this->btnSiembralo->Name = L"btnSiembralo";
			this->btnSiembralo->Size = System::Drawing::Size(75, 23);
			this->btnSiembralo->TabIndex = 2;
			this->btnSiembralo->Text = L"button1";
			this->btnSiembralo->UseVisualStyleBackColor = true;
			this->btnSiembralo->Click += gcnew System::EventHandler(this, &MyForm::btnSiembralo_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnSiembralo);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->lName);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btnSiembralo_Click(System::Object^  sender, System::EventArgs^  e) {
		lName->Text = txtBoxName->Text;
	}
	};
}
