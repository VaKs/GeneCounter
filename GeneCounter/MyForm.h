#pragma once
#include "opencv2\opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <atlstr.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>  
#include <msclr\marshal.h>

using namespace cv;
using namespace std;
namespace GeneCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	int indexImgActual = -1;
	vector<string> rutas;
	vector<string> nombreArchivos;
	string archivoTemporalActual = "";
	string rutaConImagen = "";
	string ruta="";
	string rutaTemp = "";
	string rutaContadas = "";
	string nombreArchivoActual = "";
	vector<Rect> bounding_rects;
	int numeroGenes = 0;
	int percentilSelecionado = 0;
	boolean imgBounded = false;
	vector<int> indiceASeparar;
	vector<int> numPartesASeparar;

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


	private: System::Windows::Forms::Label^  Lpercentil;

	protected:


	private: System::Windows::Forms::Button^  btnContar;

	private: System::Windows::Forms::PictureBox^  imgBox;
	private: System::Windows::Forms::TrackBar^  trackBarPercentil;
	private: System::Windows::Forms::Label^  Ltotal;
	private: System::Windows::Forms::Label^  LNuemroTotal;
	private: System::Windows::Forms::Button^  btnGuardar;


	private: System::Windows::Forms::TextBox^  textBoxUnion1;
	private: System::Windows::Forms::TextBox^  textBoxUnion2;
	private: System::Windows::Forms::Label^  LUnir;
	private: System::Windows::Forms::Label^  LCon;
	private: System::Windows::Forms::CheckBox^  ckBoxUnir;
	private: System::Windows::Forms::CheckBox^  ckBoxBorrar;
	private: System::Windows::Forms::TextBox^  txtBoxBorrar;
	private: System::Windows::Forms::TextBox^  txtBoxSepararIndice;
	private: System::Windows::Forms::TextBox^  txtBoxSepararPartes;
	private: System::Windows::Forms::Label^  LSeparar;
	private: System::Windows::Forms::Label^  LSepararEn;
	private: System::Windows::Forms::CheckBox^  ckBoxSeparar;
	private: System::Windows::Forms::CheckBox^  ckBoxCuadros;
	private: System::Windows::Forms::Label^  LejemUnir;
	private: System::Windows::Forms::Label^  LejemBorrar;
	private: System::Windows::Forms::Label^  LEjmSeparar;
	private: System::Windows::Forms::Label^  Limportante;
	private: System::Windows::Forms::Button^  btnSeleccionar;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  indiceImagen;
	private: System::Windows::Forms::Button^  btnSiguiente;
	private: System::Windows::Forms::Button^  btnAnterior;
	private: System::Windows::Forms::GroupBox^  groupBoxPercentil;
	private: System::Windows::Forms::GroupBox^  groupBoxBorrar;
	private: System::Windows::Forms::GroupBox^  groupBoxSeparar;
	private: System::Windows::Forms::Button^  btnReiniciar;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  programaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  añadirImágenesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  reiniciarImagenActualToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorDeLosNúmerosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  guiaDeUsoToolStripMenuItem;




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
			this->Lpercentil = (gcnew System::Windows::Forms::Label());
			this->btnContar = (gcnew System::Windows::Forms::Button());
			this->imgBox = (gcnew System::Windows::Forms::PictureBox());
			this->trackBarPercentil = (gcnew System::Windows::Forms::TrackBar());
			this->Ltotal = (gcnew System::Windows::Forms::Label());
			this->LNuemroTotal = (gcnew System::Windows::Forms::Label());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->textBoxUnion1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUnion2 = (gcnew System::Windows::Forms::TextBox());
			this->LUnir = (gcnew System::Windows::Forms::Label());
			this->LCon = (gcnew System::Windows::Forms::Label());
			this->ckBoxUnir = (gcnew System::Windows::Forms::CheckBox());
			this->ckBoxBorrar = (gcnew System::Windows::Forms::CheckBox());
			this->txtBoxBorrar = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxSepararIndice = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxSepararPartes = (gcnew System::Windows::Forms::TextBox());
			this->LSeparar = (gcnew System::Windows::Forms::Label());
			this->LSepararEn = (gcnew System::Windows::Forms::Label());
			this->ckBoxSeparar = (gcnew System::Windows::Forms::CheckBox());
			this->ckBoxCuadros = (gcnew System::Windows::Forms::CheckBox());
			this->LejemUnir = (gcnew System::Windows::Forms::Label());
			this->LejemBorrar = (gcnew System::Windows::Forms::Label());
			this->LEjmSeparar = (gcnew System::Windows::Forms::Label());
			this->Limportante = (gcnew System::Windows::Forms::Label());
			this->btnSeleccionar = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->indiceImagen = (gcnew System::Windows::Forms::Label());
			this->btnSiguiente = (gcnew System::Windows::Forms::Button());
			this->btnAnterior = (gcnew System::Windows::Forms::Button());
			this->groupBoxPercentil = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxBorrar = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxSeparar = (gcnew System::Windows::Forms::GroupBox());
			this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->programaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->añadirImágenesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reiniciarImagenActualToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDeLosNúmerosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guiaDeUsoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarPercentil))->BeginInit();
			this->groupBoxPercentil->SuspendLayout();
			this->groupBoxBorrar->SuspendLayout();
			this->groupBoxSeparar->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Lpercentil
			// 
			this->Lpercentil->AutoSize = true;
			this->Lpercentil->Location = System::Drawing::Point(143, 13);
			this->Lpercentil->Name = L"Lpercentil";
			this->Lpercentil->Size = System::Drawing::Size(109, 13);
			this->Lpercentil->TabIndex = 0;
			this->Lpercentil->Text = L"Percentil empleado: 0";
			// 
			// btnContar
			// 
			this->btnContar->Enabled = false;
			this->btnContar->Location = System::Drawing::Point(717, 451);
			this->btnContar->Name = L"btnContar";
			this->btnContar->Size = System::Drawing::Size(267, 23);
			this->btnContar->TabIndex = 2;
			this->btnContar->Text = L"Contar / Actualizar";
			this->btnContar->UseVisualStyleBackColor = true;
			this->btnContar->Click += gcnew System::EventHandler(this, &MyForm::btnContar_Click);
			// 
			// imgBox
			// 
			this->imgBox->Location = System::Drawing::Point(12, 79);
			this->imgBox->Name = L"imgBox";
			this->imgBox->Size = System::Drawing::Size(693, 414);
			this->imgBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgBox->TabIndex = 3;
			this->imgBox->TabStop = false;
			// 
			// trackBarPercentil
			// 
			this->trackBarPercentil->Enabled = false;
			this->trackBarPercentil->LargeChange = 10;
			this->trackBarPercentil->Location = System::Drawing::Point(6, 29);
			this->trackBarPercentil->Maximum = 100;
			this->trackBarPercentil->Name = L"trackBarPercentil";
			this->trackBarPercentil->Size = System::Drawing::Size(250, 45);
			this->trackBarPercentil->SmallChange = 10;
			this->trackBarPercentil->TabIndex = 10;
			this->trackBarPercentil->TickFrequency = 10;
			this->trackBarPercentil->Scroll += gcnew System::EventHandler(this, &MyForm::OntrackBarPercentil_Scroll);
			// 
			// Ltotal
			// 
			this->Ltotal->AutoSize = true;
			this->Ltotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ltotal->Location = System::Drawing::Point(13, 500);
			this->Ltotal->Name = L"Ltotal";
			this->Ltotal->Size = System::Drawing::Size(55, 17);
			this->Ltotal->TabIndex = 11;
			this->Ltotal->Text = L"Total: ";
			// 
			// LNuemroTotal
			// 
			this->LNuemroTotal->AutoSize = true;
			this->LNuemroTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LNuemroTotal->Location = System::Drawing::Point(64, 500);
			this->LNuemroTotal->Name = L"LNuemroTotal";
			this->LNuemroTotal->Size = System::Drawing::Size(17, 17);
			this->LNuemroTotal->TabIndex = 12;
			this->LNuemroTotal->Text = L"0";
			// 
			// btnGuardar
			// 
			this->btnGuardar->Enabled = false;
			this->btnGuardar->Location = System::Drawing::Point(842, 495);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(134, 23);
			this->btnGuardar->TabIndex = 13;
			this->btnGuardar->Text = L"Guardar y siguiente >";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &MyForm::btnGuardar_Click);
			// 
			// textBoxUnion1
			// 
			this->textBoxUnion1->Enabled = false;
			this->textBoxUnion1->Location = System::Drawing::Point(141, 27);
			this->textBoxUnion1->Name = L"textBoxUnion1";
			this->textBoxUnion1->Size = System::Drawing::Size(42, 20);
			this->textBoxUnion1->TabIndex = 16;
			// 
			// textBoxUnion2
			// 
			this->textBoxUnion2->Enabled = false;
			this->textBoxUnion2->Location = System::Drawing::Point(203, 27);
			this->textBoxUnion2->Name = L"textBoxUnion2";
			this->textBoxUnion2->Size = System::Drawing::Size(42, 20);
			this->textBoxUnion2->TabIndex = 17;
			// 
			// LUnir
			// 
			this->LUnir->AutoSize = true;
			this->LUnir->Location = System::Drawing::Point(138, 11);
			this->LUnir->Name = L"LUnir";
			this->LUnir->Size = System::Drawing::Size(29, 13);
			this->LUnir->TabIndex = 18;
			this->LUnir->Text = L"Unir:";
			// 
			// LCon
			// 
			this->LCon->AutoSize = true;
			this->LCon->Location = System::Drawing::Point(200, 11);
			this->LCon->Name = L"LCon";
			this->LCon->Size = System::Drawing::Size(28, 13);
			this->LCon->TabIndex = 19;
			this->LCon->Text = L"con:";
			// 
			// ckBoxUnir
			// 
			this->ckBoxUnir->AutoSize = true;
			this->ckBoxUnir->Enabled = false;
			this->ckBoxUnir->Location = System::Drawing::Point(34, 29);
			this->ckBoxUnir->Name = L"ckBoxUnir";
			this->ckBoxUnir->Size = System::Drawing::Size(83, 17);
			this->ckBoxUnir->TabIndex = 20;
			this->ckBoxUnir->Text = L"Unir índices";
			this->ckBoxUnir->UseVisualStyleBackColor = true;
			this->ckBoxUnir->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckBoxUnir_CheckedChanged);
			// 
			// ckBoxBorrar
			// 
			this->ckBoxBorrar->AutoSize = true;
			this->ckBoxBorrar->Enabled = false;
			this->ckBoxBorrar->Location = System::Drawing::Point(34, 96);
			this->ckBoxBorrar->Name = L"ckBoxBorrar";
			this->ckBoxBorrar->Size = System::Drawing::Size(90, 17);
			this->ckBoxBorrar->TabIndex = 21;
			this->ckBoxBorrar->Text = L"Borrar índice:";
			this->ckBoxBorrar->UseVisualStyleBackColor = true;
			this->ckBoxBorrar->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckBoxBorrar_CheckedChanged);
			// 
			// txtBoxBorrar
			// 
			this->txtBoxBorrar->Enabled = false;
			this->txtBoxBorrar->Location = System::Drawing::Point(141, 94);
			this->txtBoxBorrar->Name = L"txtBoxBorrar";
			this->txtBoxBorrar->Size = System::Drawing::Size(42, 20);
			this->txtBoxBorrar->TabIndex = 22;
			// 
			// txtBoxSepararIndice
			// 
			this->txtBoxSepararIndice->Enabled = false;
			this->txtBoxSepararIndice->Location = System::Drawing::Point(144, 39);
			this->txtBoxSepararIndice->Name = L"txtBoxSepararIndice";
			this->txtBoxSepararIndice->Size = System::Drawing::Size(41, 20);
			this->txtBoxSepararIndice->TabIndex = 23;
			// 
			// txtBoxSepararPartes
			// 
			this->txtBoxSepararPartes->Enabled = false;
			this->txtBoxSepararPartes->Location = System::Drawing::Point(203, 39);
			this->txtBoxSepararPartes->Name = L"txtBoxSepararPartes";
			this->txtBoxSepararPartes->Size = System::Drawing::Size(42, 20);
			this->txtBoxSepararPartes->TabIndex = 24;
			// 
			// LSeparar
			// 
			this->LSeparar->AutoSize = true;
			this->LSeparar->Location = System::Drawing::Point(141, 20);
			this->LSeparar->Name = L"LSeparar";
			this->LSeparar->Size = System::Drawing::Size(47, 13);
			this->LSeparar->TabIndex = 25;
			this->LSeparar->Text = L"Separar:";
			// 
			// LSepararEn
			// 
			this->LSepararEn->AutoSize = true;
			this->LSepararEn->Location = System::Drawing::Point(203, 19);
			this->LSepararEn->Name = L"LSepararEn";
			this->LSepararEn->Size = System::Drawing::Size(23, 13);
			this->LSepararEn->TabIndex = 26;
			this->LSepararEn->Text = L"En:";
			// 
			// ckBoxSeparar
			// 
			this->ckBoxSeparar->AutoSize = true;
			this->ckBoxSeparar->Enabled = false;
			this->ckBoxSeparar->Location = System::Drawing::Point(34, 41);
			this->ckBoxSeparar->Name = L"ckBoxSeparar";
			this->ckBoxSeparar->Size = System::Drawing::Size(96, 17);
			this->ckBoxSeparar->TabIndex = 27;
			this->ckBoxSeparar->Text = L"Separar índice";
			this->ckBoxSeparar->UseVisualStyleBackColor = true;
			this->ckBoxSeparar->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckBoxSeparar_CheckedChanged);
			// 
			// ckBoxCuadros
			// 
			this->ckBoxCuadros->AutoSize = true;
			this->ckBoxCuadros->Enabled = false;
			this->ckBoxCuadros->Location = System::Drawing::Point(522, 499);
			this->ckBoxCuadros->Name = L"ckBoxCuadros";
			this->ckBoxCuadros->Size = System::Drawing::Size(183, 17);
			this->ckBoxCuadros->TabIndex = 28;
			this->ckBoxCuadros->Text = L"Recuadrar resultados detectados";
			this->ckBoxCuadros->UseVisualStyleBackColor = true;
			// 
			// LejemUnir
			// 
			this->LejemUnir->AutoSize = true;
			this->LejemUnir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LejemUnir->ForeColor = System::Drawing::Color::Crimson;
			this->LejemUnir->Location = System::Drawing::Point(55, 53);
			this->LejemUnir->Name = L"LejemUnir";
			this->LejemUnir->Size = System::Drawing::Size(134, 13);
			this->LejemUnir->TabIndex = 29;
			this->LejemUnir->Text = L"Ej:  Unir [ 1; ]  Con [ 2;3;4; ]";
			// 
			// LejemBorrar
			// 
			this->LejemBorrar->AutoSize = true;
			this->LejemBorrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LejemBorrar->ForeColor = System::Drawing::Color::Crimson;
			this->LejemBorrar->Location = System::Drawing::Point(55, 117);
			this->LejemBorrar->Name = L"LejemBorrar";
			this->LejemBorrar->Size = System::Drawing::Size(100, 13);
			this->LejemBorrar->TabIndex = 30;
			this->LejemBorrar->Text = L"Ej: [ 1; ]  ó  [ 2;3;4; ]";
			this->LejemBorrar->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// LEjmSeparar
			// 
			this->LEjmSeparar->AutoSize = true;
			this->LEjmSeparar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LEjmSeparar->ForeColor = System::Drawing::Color::Crimson;
			this->LEjmSeparar->Location = System::Drawing::Point(58, 65);
			this->LEjmSeparar->Name = L"LEjmSeparar";
			this->LEjmSeparar->Size = System::Drawing::Size(144, 13);
			this->LEjmSeparar->TabIndex = 31;
			this->LEjmSeparar->Text = L"Ej: Separar [ 1;2; ]  En [ 2;3; ]";
			// 
			// Limportante
			// 
			this->Limportante->AutoSize = true;
			this->Limportante->ForeColor = System::Drawing::Color::Crimson;
			this->Limportante->Location = System::Drawing::Point(714, 164);
			this->Limportante->Name = L"Limportante";
			this->Limportante->Size = System::Drawing::Size(270, 13);
			this->Limportante->TabIndex = 32;
			this->Limportante->Text = L"* IMPORTANTE : escribir los números con un \' ; \' detrás";
			// 
			// btnSeleccionar
			// 
			this->btnSeleccionar->Location = System::Drawing::Point(265, 274);
			this->btnSeleccionar->Name = L"btnSeleccionar";
			this->btnSeleccionar->Size = System::Drawing::Size(143, 23);
			this->btnSeleccionar->TabIndex = 33;
			this->btnSeleccionar->Text = L"Selecionar imagenes";
			this->btnSeleccionar->UseVisualStyleBackColor = true;
			this->btnSeleccionar->Click += gcnew System::EventHandler(this, &MyForm::btnSeleccionar_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"(*.bmp)|*.bmp";
			this->openFileDialog->Multiselect = true;
			// 
			// indiceImagen
			// 
			this->indiceImagen->AutoSize = true;
			this->indiceImagen->Location = System::Drawing::Point(327, 40);
			this->indiceImagen->Name = L"indiceImagen";
			this->indiceImagen->Size = System::Drawing::Size(0, 13);
			this->indiceImagen->TabIndex = 34;
			// 
			// btnSiguiente
			// 
			this->btnSiguiente->Enabled = false;
			this->btnSiguiente->Location = System::Drawing::Point(404, 40);
			this->btnSiguiente->Name = L"btnSiguiente";
			this->btnSiguiente->Size = System::Drawing::Size(75, 23);
			this->btnSiguiente->TabIndex = 35;
			this->btnSiguiente->Text = L"Siguiente >";
			this->btnSiguiente->UseVisualStyleBackColor = true;
			this->btnSiguiente->Click += gcnew System::EventHandler(this, &MyForm::btnSiguiente_Click);
			// 
			// btnAnterior
			// 
			this->btnAnterior->Enabled = false;
			this->btnAnterior->Location = System::Drawing::Point(201, 40);
			this->btnAnterior->Name = L"btnAnterior";
			this->btnAnterior->Size = System::Drawing::Size(75, 23);
			this->btnAnterior->TabIndex = 36;
			this->btnAnterior->Text = L"< Anterior ";
			this->btnAnterior->UseVisualStyleBackColor = true;
			this->btnAnterior->Click += gcnew System::EventHandler(this, &MyForm::btnAnterior_Click);
			// 
			// groupBoxPercentil
			// 
			this->groupBoxPercentil->Controls->Add(this->trackBarPercentil);
			this->groupBoxPercentil->Controls->Add(this->Lpercentil);
			this->groupBoxPercentil->Location = System::Drawing::Point(717, 50);
			this->groupBoxPercentil->Name = L"groupBoxPercentil";
			this->groupBoxPercentil->Size = System::Drawing::Size(267, 100);
			this->groupBoxPercentil->TabIndex = 37;
			this->groupBoxPercentil->TabStop = false;
			this->groupBoxPercentil->Text = L" Paso 1: ";
			// 
			// groupBoxBorrar
			// 
			this->groupBoxBorrar->Controls->Add(this->ckBoxUnir);
			this->groupBoxBorrar->Controls->Add(this->textBoxUnion1);
			this->groupBoxBorrar->Controls->Add(this->textBoxUnion2);
			this->groupBoxBorrar->Controls->Add(this->LUnir);
			this->groupBoxBorrar->Controls->Add(this->LCon);
			this->groupBoxBorrar->Controls->Add(this->ckBoxBorrar);
			this->groupBoxBorrar->Controls->Add(this->txtBoxBorrar);
			this->groupBoxBorrar->Controls->Add(this->LejemUnir);
			this->groupBoxBorrar->Controls->Add(this->LejemBorrar);
			this->groupBoxBorrar->Location = System::Drawing::Point(717, 191);
			this->groupBoxBorrar->Name = L"groupBoxBorrar";
			this->groupBoxBorrar->Size = System::Drawing::Size(267, 144);
			this->groupBoxBorrar->TabIndex = 38;
			this->groupBoxBorrar->TabStop = false;
			this->groupBoxBorrar->Text = L" Parso 2: ";
			// 
			// groupBoxSeparar
			// 
			this->groupBoxSeparar->Controls->Add(this->ckBoxSeparar);
			this->groupBoxSeparar->Controls->Add(this->txtBoxSepararIndice);
			this->groupBoxSeparar->Controls->Add(this->txtBoxSepararPartes);
			this->groupBoxSeparar->Controls->Add(this->LSeparar);
			this->groupBoxSeparar->Controls->Add(this->LSepararEn);
			this->groupBoxSeparar->Controls->Add(this->LEjmSeparar);
			this->groupBoxSeparar->Location = System::Drawing::Point(717, 341);
			this->groupBoxSeparar->Name = L"groupBoxSeparar";
			this->groupBoxSeparar->Size = System::Drawing::Size(267, 104);
			this->groupBoxSeparar->TabIndex = 39;
			this->groupBoxSeparar->TabStop = false;
			this->groupBoxSeparar->Text = L" Paso 3: ";
			// 
			// btnReiniciar
			// 
			this->btnReiniciar->Location = System::Drawing::Point(738, 495);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(75, 23);
			this->btnReiniciar->TabIndex = 40;
			this->btnReiniciar->Text = L"Reiniciar";
			this->btnReiniciar->UseVisualStyleBackColor = true;
			this->btnReiniciar->Click += gcnew System::EventHandler(this, &MyForm::btnReiniciar_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->programaToolStripMenuItem,
					this->guiaDeUsoToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(990, 24);
			this->menuStrip1->TabIndex = 41;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// programaToolStripMenuItem
			// 
			this->programaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->añadirImágenesToolStripMenuItem,
					this->reiniciarImagenActualToolStripMenuItem, this->colorDeLosNúmerosToolStripMenuItem
			});
			this->programaToolStripMenuItem->Name = L"programaToolStripMenuItem";
			this->programaToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->programaToolStripMenuItem->Text = L"Programa";
			// 
			// añadirImágenesToolStripMenuItem
			// 
			this->añadirImágenesToolStripMenuItem->Name = L"añadirImágenesToolStripMenuItem";
			this->añadirImágenesToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->añadirImágenesToolStripMenuItem->Text = L"Añadir imágenes";
			this->añadirImágenesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::añadirImágenesToolStripMenuItem_Click);
			// 
			// reiniciarImagenActualToolStripMenuItem
			// 
			this->reiniciarImagenActualToolStripMenuItem->Name = L"reiniciarImagenActualToolStripMenuItem";
			this->reiniciarImagenActualToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->reiniciarImagenActualToolStripMenuItem->Text = L"Reiniciar imagen actual";
			this->reiniciarImagenActualToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::reiniciarImagenActualToolStripMenuItem_Click);
			// 
			// colorDeLosNúmerosToolStripMenuItem
			// 
			this->colorDeLosNúmerosToolStripMenuItem->Name = L"colorDeLosNúmerosToolStripMenuItem";
			this->colorDeLosNúmerosToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->colorDeLosNúmerosToolStripMenuItem->Text = L"Color de los números";
			// 
			// guiaDeUsoToolStripMenuItem
			// 
			this->guiaDeUsoToolStripMenuItem->Name = L"guiaDeUsoToolStripMenuItem";
			this->guiaDeUsoToolStripMenuItem->Size = System::Drawing::Size(82, 20);
			this->guiaDeUsoToolStripMenuItem->Text = L"Guia de Uso";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(990, 525);
			this->Controls->Add(this->btnReiniciar);
			this->Controls->Add(this->groupBoxSeparar);
			this->Controls->Add(this->groupBoxBorrar);
			this->Controls->Add(this->groupBoxPercentil);
			this->Controls->Add(this->btnAnterior);
			this->Controls->Add(this->btnSiguiente);
			this->Controls->Add(this->indiceImagen);
			this->Controls->Add(this->btnSeleccionar);
			this->Controls->Add(this->Limportante);
			this->Controls->Add(this->ckBoxCuadros);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->LNuemroTotal);
			this->Controls->Add(this->Ltotal);
			this->Controls->Add(this->imgBox);
			this->Controls->Add(this->btnContar);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Contador de genes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarPercentil))->EndInit();
			this->groupBoxPercentil->ResumeLayout(false);
			this->groupBoxPercentil->PerformLayout();
			this->groupBoxBorrar->ResumeLayout(false);
			this->groupBoxBorrar->PerformLayout();
			this->groupBoxSeparar->ResumeLayout(false);
			this->groupBoxSeparar->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		DirectoryInfo^ diTemp;

		int getRandomNumber(int min, int max) {
			int range = max - min + 1;
			int num = rand() % range + min;
			return num;
		}
		int getIndex(vector<int> vec, int value) {
			auto it = std::find(vec.begin(), vec.end(), value);
			if (it == vec.end())
			{
				return -1;
			}
			else
			{
				return std::distance(vec.begin(), it);
			}
		}
		bool Contains(vector<int> Vec, int Element)
		{
			if (std::find(Vec.begin(), Vec.end(), Element) != Vec.end())
				return true;

			return false;
		}
		double calcularPercentil(int percentil, vector<double> muestra) {
			sort(muestra.begin(), muestra.end());
			int tamañoMuestra = muestra.size();
			int posicionPercentil = (tamañoMuestra*percentil) / 100;
			return muestra.at(posicionPercentil);
		}
		Mat negativo(Mat m) {
			int colores = m.channels();
			if (colores == 3) {
				Vec3b pixel;
				for (int j = 0; j < m.rows; j++) {
					for (int i = 0; i < m.cols; i++) {
						pixel = m.at<Vec3b>(j, i);
						for (int k = 0; k < 3; k++) {
							int a = 255 - (int)pixel[k];
							m.at<Vec3b>(j, i)[k] = (uchar)a;
						}
					}
				}
			}
			else if (colores == 1) {
				vector<int>valores(256, 0);
				for (int j = 0; j < m.rows; j++) {
					waitKey(10);
					for (int i = 0; i < m.cols; i++) {
						uchar pixel = m.at<uchar>(j, i);
						int n = 255 - (int)pixel;
						m.at<uchar>(j, i) = n;
					}
				}
			}
			return m;
		}
		Mat contarGenes(Mat src) {
			Rect bounding_rect;
			numeroGenes = 1;
			for (int i = 0; i < bounding_rects.size(); i++) // recorrer la lista de contornos
			{
				bounding_rect = bounding_rects.at(i);
				if (ckBoxCuadros->Checked) { // si la opción  recuadrar está selecionada
					rectangle(src, bounding_rect, Scalar(0, 255, 0), 3, 8, 0); // Pintar rectangulo enlazado al contorno
				}

				if (Contains(indiceASeparar,numeroGenes)) // si el indice con el que estamos trabajando se ha seleccionado para ser separado en varios
				{
					int index = getIndex(indiceASeparar, numeroGenes);
					for (int j = 0; j < numPartesASeparar.at(index) ; j++)
					{
						putText(src, to_string(numeroGenes), Point2f(bounding_rect.x + j*20 , bounding_rect.y + j*30), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 255), 2);
						numeroGenes++;
					}
				}
				else { // si no, simplemente se escribe el número
					putText(src, to_string(numeroGenes), Point2f(bounding_rect.x, bounding_rect.y + bounding_rect.height), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 255), 2);
					numeroGenes++;
				}
			}
			numeroGenes--;
			return src;
		}

		vector<Rect> getBoundings(Mat src) {
			vector<vector<cv::Point>> contours;
			vector<Vec4i> hierarchy;
			vector<Rect> bounding_rects;
			Rect bounding_rect;
			Mat dst, bin, img_gray;

			cvtColor(src, img_gray, CV_BGR2GRAY);	// convierte la imagen de RGB (src) a niveles de gris (img_gray)
			dst = img_gray > 128;					// convierte la imagen de escala de gris a Blanco y negro
			dst = negativo(dst);					// obtiene el negtivo de la imagen

			threshold(dst, bin, 20, 255, THRESH_BINARY); // pasar la imagen a binaria con  Treshold
			findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); // encuentra los contornos de la imagen binaria

			vector<double> areas;
			int area;
			for (int i = 0; i < contours.size(); i++)
			{
				bounding_rect = boundingRect(contours[i]); // Almacena en una lista con los contornos detectados y les enlaza un rectangulo que la rodea
				area = bounding_rect.height*bounding_rect.width; // Calcula el area de cada contorno y las almacena en una lista
				areas.push_back(area); 
			}

			double percentil = calcularPercentil(percentilSelecionado, areas); // Con la lista de areas se obtiene el valor del percentil selecionado para cribar los resultados

			for (int i = 0; i < contours.size(); i++)
			{
				bounding_rect = boundingRect(contours[i]); 
				area = bounding_rect.height*bounding_rect.width;
				if (area > percentil) {		// Si el area de este contarno es mayor que el valor del percentil se almacena, si no se descarta
					bounding_rects.push_back(bounding_rect);
				}
			}
			return bounding_rects;
		}

	void MarshalString(System::String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	vector<int> getBorrarList() {
		vector<int> borrar;
		if (ckBoxBorrar->Checked) {
			std::string texto;
			std::string delimiter = ";";
			System::String^ rawBorrarText = txtBoxBorrar->Text;
			MarshalString(rawBorrarText, texto);
			size_t pos = 0;
			std::string token;
			while ((pos = texto.find(delimiter)) != std::string::npos) {
				token = texto.substr(0, pos);
				borrar.push_back(std::stoi(token));
				texto.erase(0, pos + delimiter.length());
			}
		}
		else {
			borrar.push_back(0);
		}
		return borrar;
	}
	vector<int> getUnirList() {
		vector<int> unir;
		if (ckBoxUnir->Checked) {
			std::string texto;
			std::string delimiter = ";";
			System::String^ rawBorrarText = textBoxUnion2->Text;
			MarshalString(rawBorrarText, texto);
			size_t pos = 0;
			std::string token;
			while ((pos = texto.find(delimiter)) != std::string::npos) {
				token = texto.substr(0, pos);
				unir.push_back(std::stoi(token));
				texto.erase(0, pos + delimiter.length());
			}
		}
		else {
			unir.push_back(0);
		}
		return unir;
	}
	void setSeparacion() {
		if (ckBoxSeparar->Checked) {
			std::string delimiter = ";";
			System::String^ numPartes = txtBoxSepararPartes->Text;
			std::string stdNumPartes, stdIndiceASeparar;
			System::String^ indiceSeparar = txtBoxSepararIndice->Text;
			MarshalString(numPartes, stdNumPartes);
			MarshalString(indiceSeparar, stdIndiceASeparar);
			size_t pos = 0;
			std::string token;

			while ((pos = stdNumPartes.find(delimiter)) != std::string::npos) {
				token = stdNumPartes.substr(0, pos);
				numPartesASeparar.push_back(std::stoi(token));
				stdNumPartes.erase(0, pos + delimiter.length());
			}
			pos = 0;
			while ((pos = stdIndiceASeparar.find(delimiter)) != std::string::npos) {
				token = stdIndiceASeparar.substr(0, pos);
				indiceASeparar.push_back(std::stoi(token));
				stdIndiceASeparar.erase(0, pos + delimiter.length());
			}
		}
		else {
			numPartesASeparar.push_back(0);
			indiceASeparar.push_back(0);
		}
	}
	vector<Rect> deleteBoundsChosed(vector<int> borrar) {
		vector<Rect> newBounding;
		for (int i = 0; i < bounding_rects.size(); i++) 
		{
			if (std::find(borrar.begin(), borrar.end(), i + 1) != borrar.end())
			{ }
			else {
				newBounding.push_back(bounding_rects.at(i));
			}
		}
		return newBounding;
	}
	private: System::Void btnContar_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat img = imread(rutaConImagen, CV_LOAD_IMAGE_COLOR);
		vector<int> borrar, uniones, borrarYUniones;

		if (!imgBounded)
		{
			bounding_rects = getBoundings(img);
			imgBounded = true;
			btnGuardar->Enabled = true;
			ckBoxBorrar->Enabled = true;
			ckBoxSeparar->Enabled = true;
			ckBoxUnir->Enabled = true;
		}
		if (ckBoxBorrar->Checked || ckBoxUnir->Checked)
		{
			if (ckBoxBorrar->Checked && ckBoxUnir->Checked) {
				borrar = getBorrarList();
				uniones = getUnirList();
				borrarYUniones.reserve(borrar.size() + uniones.size());
				borrarYUniones.insert(borrarYUniones.end(), borrar.begin(), borrar.end());
				borrarYUniones.insert(borrarYUniones.end(), uniones.begin(), uniones.end());

				bounding_rects = deleteBoundsChosed(borrarYUniones);

				ckBoxBorrar->Checked = false;
				txtBoxBorrar->Text = "";
				ckBoxUnir->Checked = false;
				textBoxUnion1->Text = "";
				textBoxUnion2->Text = "";

			} else if (ckBoxUnir->Checked)
			{
				uniones = getUnirList();
				bounding_rects = deleteBoundsChosed(uniones);
				ckBoxUnir->Checked = false;
				textBoxUnion1->Text = "";
				textBoxUnion2->Text = "";

			} else if (ckBoxBorrar->Checked)
			{
				borrar = getBorrarList();
				bounding_rects = deleteBoundsChosed(borrar);
				ckBoxBorrar->Checked = false;
				txtBoxBorrar->Text = "";
			}
			
		}
		
		if (ckBoxSeparar->Checked) 
		{
			setSeparacion();
			ckBoxSeparar->Checked = false;
			txtBoxSepararIndice->Text = "";
			txtBoxSepararPartes->Text = "";
		}

		img = contarGenes(img);
		showImage(img);

	}
	private: System::Void OntrackBarPercentil_Scroll(System::Object^  sender, System::EventArgs^  e) {
		Lpercentil->Text = System::String::Concat("Percentil empleado: ", trackBarPercentil->Value);
		imgBounded = false;
		percentilSelecionado = trackBarPercentil->Value;
		if (percentilSelecionado == 100) {
			percentilSelecionado = 99;
		}
	}
	void showImage(Mat img) {
		int num = getRandomNumber(0,1000);
		archivoTemporalActual = rutaTemp + "temp_" + to_string(numeroGenes) + "_" + to_string(num)+ "_" + nombreArchivoActual;
		imwrite(archivoTemporalActual, img);
		imgBox->Image = System::Drawing::Image::FromFile(gcnew System::String(archivoTemporalActual.c_str()));
		LNuemroTotal->Text = System::String::Concat("", numeroGenes);
	}
	void saveImage(Mat img) {
		imwrite(rutaContadas + nombreArchivoActual, img);
		imgBox->Image = System::Drawing::Image::FromFile(gcnew System::String(rutaConImagen.c_str()));
	}

	private: System::Void btnGuardar_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat img = imread(archivoTemporalActual, CV_LOAD_IMAGE_COLOR);
		saveImage(img);
		nextImage();
	}
	void EnablePannel() {
		btnAnterior->Enabled = true;
		btnSiguiente->Enabled = true;
		ckBoxBorrar->Enabled = true;
		ckBoxCuadros->Enabled = true;
		ckBoxSeparar->Enabled = true;
		ckBoxUnir->Enabled = true;
		trackBarPercentil->Enabled = true;
		btnContar->Enabled = true;
		btnSeleccionar->Visible = false;
		btnReiniciar->Enabled = true;

	}
	void DisablePannel() {
		btnAnterior->Enabled = false;
		btnReiniciar->Enabled = false;
		btnSiguiente->Enabled = false;
		ckBoxCuadros->Enabled = false;
		ckBoxBorrar->Enabled = false;
		ckBoxSeparar->Enabled = false;		
		ckBoxUnir->Enabled = false;
		txtBoxBorrar->Enabled = false;
		txtBoxSepararIndice->Enabled = false;
		txtBoxSepararPartes->Enabled = false;
		textBoxUnion1->Enabled = false;
		textBoxUnion2->Enabled = false;
		trackBarPercentil->Enabled = false;
		btnContar->Enabled = false;
		btnGuardar->Enabled = false;
		btnSeleccionar->Visible = true;


	}

	void nextImage() {

		if (indexImgActual+1 != nombreArchivos.size()) {
			vector<int> nullIntVector;
			vector<Rect> nullRectVector;

			indexImgActual++;

			archivoTemporalActual = "";
			ruta = rutas.at(indexImgActual);
			nombreArchivoActual = nombreArchivos.at(indexImgActual);
			rutaConImagen = ruta + nombreArchivoActual;

			System::String^ auxRuta = gcnew System::String(ruta.c_str());
			auxRuta = auxRuta + "temp";
			diTemp = Directory::CreateDirectory(gcnew System::String(auxRuta));
			auxRuta = gcnew System::String(ruta.c_str());
			auxRuta = auxRuta + "contadas";
			DirectoryInfo^ diContadas = Directory::CreateDirectory(gcnew System::String(auxRuta));

			rutaTemp = ruta + "temp\\";
			rutaContadas = ruta + "contadas\\";

			bounding_rects = nullRectVector;
			numeroGenes = 0;
			percentilSelecionado = 0;
			imgBounded = false;
			btnGuardar->Enabled = false;
			ckBoxBorrar->Enabled = false;
			ckBoxSeparar->Enabled = false;
			ckBoxUnir->Enabled = false;

			indiceASeparar = nullIntVector;
			numPartesASeparar = nullIntVector;

			imgBox->Image = System::Drawing::Image::FromFile(gcnew System::String(rutaConImagen.c_str()));

			indiceImagen->Text = System::String::Concat(indexImgActual+1, " de ", nombreArchivos.size());
		}
		if (indexImgActual + 1 == nombreArchivos.size()) {
			btnSiguiente->Enabled = false;
			btnAnterior->Enabled = true;
		}
		else
		{
			btnSiguiente->Enabled = true;
			btnAnterior->Enabled = true;
		}


	}
	private: System::Void ckBoxSeparar_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ckBoxSeparar->Checked == true) {
			ckBoxBorrar->Checked = false;
			ckBoxBorrar->Enabled = false;
			ckBoxUnir->Checked = false;
			ckBoxUnir->Enabled = false;
			txtBoxSepararIndice->Enabled = true;
			txtBoxSepararPartes->Enabled = true;
		}
		else 
		{
			ckBoxBorrar->Enabled = true;
			ckBoxUnir->Enabled = true;
			txtBoxSepararIndice->Enabled = false;
			txtBoxSepararPartes->Enabled = false;
		}
	}
	private: System::Void ckBoxBorrar_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ckBoxBorrar->Checked == true) {
			ckBoxSeparar->Checked = false;
			ckBoxSeparar->Enabled = false;
			txtBoxBorrar->Enabled = true;
		}
		else
		{
			ckBoxSeparar->Enabled = true;
			txtBoxBorrar->Enabled = false;
		}
	}
	private: System::Void ckBoxUnir_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ckBoxUnir->Checked == true) {
			ckBoxSeparar->Checked = false;
			ckBoxSeparar->Enabled = false;
			textBoxUnion1->Enabled = true;
			textBoxUnion2->Enabled = true;
		}
		else
		{
			ckBoxSeparar->Enabled = true;
			textBoxUnion1->Enabled = false;
			textBoxUnion2->Enabled = false;
		}
	}
private: System::Void btnSeleccionar_Click(System::Object^  sender, System::EventArgs^  e) {

	System::String^ rawRuta;
	System::String^ fileName;
	System::String^ path;
	string archivo;

	Stream^ stream;
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		stream = openFileDialog->OpenFile();
		if (stream != nullptr) {
			
			for each (System::String^ file in openFileDialog->FileNames)
			{
				rawRuta = file;
				fileName = Path::GetFileName(rawRuta);
				path = rawRuta->Substring(0, (rawRuta->Length) - (fileName->Length));
				MarshalString(path, ruta);
				MarshalString(fileName, archivo);

				rutas.push_back(ruta);
				nombreArchivos.push_back(archivo);
			}
		}
		stream->Close();

		EnablePannel();
		nextImage();
	}
}
private: System::Void btnSiguiente_Click(System::Object^  sender, System::EventArgs^  e) {
	nextImage();
}
private: System::Void btnAnterior_Click(System::Object^  sender, System::EventArgs^  e) {
	if (indexImgActual > 0) {
		vector<int> nullIntVector;
		vector<Rect> nullRectVector;

		indexImgActual--;

		archivoTemporalActual = "";
		ruta = rutas.at(indexImgActual);
		nombreArchivoActual = nombreArchivos.at(indexImgActual);
		rutaConImagen = ruta + nombreArchivoActual;

		System::String^ auxRuta = gcnew System::String(ruta.c_str());
		auxRuta = auxRuta + "temp";
		diTemp = Directory::CreateDirectory(gcnew System::String(auxRuta));
		auxRuta = gcnew System::String(ruta.c_str());
		auxRuta = auxRuta + "contadas";
		DirectoryInfo^ diContadas = Directory::CreateDirectory(gcnew System::String(auxRuta));

		rutaTemp = ruta + "temp\\";
		rutaContadas = ruta + "contadas\\";

		bounding_rects = nullRectVector;
		numeroGenes = 0;
		percentilSelecionado = 0;
		imgBounded = false;
		btnGuardar->Enabled = false;
		indiceASeparar = nullIntVector;
		numPartesASeparar = nullIntVector;

		imgBox->Image = System::Drawing::Image::FromFile(gcnew System::String(rutaConImagen.c_str()));

		indiceImagen->Text = System::String::Concat(indexImgActual + 1, " de ", nombreArchivos.size());
	}
	if (indexImgActual == 0) {
		btnAnterior->Enabled = false;
		btnSiguiente->Enabled = true;
	}
	else
	{
		btnSiguiente->Enabled = true;
		btnAnterior->Enabled = true;
	}
}
private: System::Void añadirImágenesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String^ rawRuta;
	System::String^ fileName;
	System::String^ path;
	string archivo;

	Stream^ stream;
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		stream = openFileDialog->OpenFile();
		if (stream != nullptr) {

			for each (System::String^ file in openFileDialog->FileNames)
			{
				rawRuta = file;
				fileName = Path::GetFileName(rawRuta);
				path = rawRuta->Substring(0, (rawRuta->Length) - (fileName->Length));
				MarshalString(path, ruta);
				MarshalString(fileName, archivo);

				rutas.push_back(ruta);
				nombreArchivos.push_back(archivo);
			}
		}
		stream->Close();
		indiceImagen->Text = System::String::Concat(indexImgActual + 1, " de ", nombreArchivos.size());
	}
}
private: System::Void btnReiniciar_Click(System::Object^  sender, System::EventArgs^  e) {
	imgBounded = false;
	btnGuardar->Enabled = false;
	ckBoxBorrar->Enabled = false;
	ckBoxSeparar->Enabled = false;
	ckBoxUnir->Enabled = false;
	imgBox->Image = System::Drawing::Image::FromFile(gcnew System::String(rutaConImagen.c_str()));
	LNuemroTotal->Text = System::String::Concat("", 0);

}
private: System::Void reiniciarImagenActualToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	imgBounded = false;
	btnGuardar->Enabled = false;
	ckBoxBorrar->Enabled = false;
	ckBoxSeparar->Enabled = false;
	ckBoxUnir->Enabled = false;
	imgBox->Image = System::Drawing::Image::FromFile(gcnew System::String(rutaConImagen.c_str()));
	LNuemroTotal->Text = System::String::Concat("", 0);
}
};
}

