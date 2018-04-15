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
	using namespace msclr::interop;

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
		int numeroGenes = 0;
		int percentilSelecionado = 0;

	private: System::Windows::Forms::Label^  Lpercentil;
	private: System::Windows::Forms::TextBox^  txtBoxRuta;
	protected:


	private: System::Windows::Forms::Button^  btnContar;

	private: System::Windows::Forms::PictureBox^  imgBox;
	private: System::Windows::Forms::TrackBar^  trackBarPercentil;
	private: System::Windows::Forms::Label^  Ltotal;
	private: System::Windows::Forms::Label^  LNuemroTotal;
	private: System::Windows::Forms::Button^  btnGuardar;
	private: System::Windows::Forms::Label^  LrutaDir;
	private: System::Windows::Forms::Button^  btnMostrar;
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
			this->Lpercentil = (gcnew System::Windows::Forms::Label());
			this->txtBoxRuta = (gcnew System::Windows::Forms::TextBox());
			this->btnContar = (gcnew System::Windows::Forms::Button());
			this->imgBox = (gcnew System::Windows::Forms::PictureBox());
			this->trackBarPercentil = (gcnew System::Windows::Forms::TrackBar());
			this->Ltotal = (gcnew System::Windows::Forms::Label());
			this->LNuemroTotal = (gcnew System::Windows::Forms::Label());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->LrutaDir = (gcnew System::Windows::Forms::Label());
			this->btnMostrar = (gcnew System::Windows::Forms::Button());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarPercentil))->BeginInit();
			this->SuspendLayout();
			// 
			// Lpercentil
			// 
			this->Lpercentil->AutoSize = true;
			this->Lpercentil->Location = System::Drawing::Point(848, 365);
			this->Lpercentil->Name = L"Lpercentil";
			this->Lpercentil->Size = System::Drawing::Size(109, 13);
			this->Lpercentil->TabIndex = 0;
			this->Lpercentil->Text = L"Percentil empleado: 0";
			// 
			// txtBoxRuta
			// 
			this->txtBoxRuta->Location = System::Drawing::Point(12, 24);
			this->txtBoxRuta->Name = L"txtBoxRuta";
			this->txtBoxRuta->Size = System::Drawing::Size(217, 20);
			this->txtBoxRuta->TabIndex = 1;
			// 
			// btnContar
			// 
			this->btnContar->Location = System::Drawing::Point(886, 480);
			this->btnContar->Name = L"btnContar";
			this->btnContar->Size = System::Drawing::Size(75, 23);
			this->btnContar->TabIndex = 2;
			this->btnContar->Text = L"Contar";
			this->btnContar->UseVisualStyleBackColor = true;
			this->btnContar->Click += gcnew System::EventHandler(this, &MyForm::btnContar_Click);
			// 
			// imgBox
			// 
			this->imgBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgBox.Image")));
			this->imgBox->Location = System::Drawing::Point(12, 79);
			this->imgBox->Name = L"imgBox";
			this->imgBox->Size = System::Drawing::Size(693, 414);
			this->imgBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgBox->TabIndex = 3;
			this->imgBox->TabStop = false;
			// 
			// trackBarPercentil
			// 
			this->trackBarPercentil->LargeChange = 10;
			this->trackBarPercentil->Location = System::Drawing::Point(711, 381);
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
			this->Ltotal->Location = System::Drawing::Point(13, 500);
			this->Ltotal->Name = L"Ltotal";
			this->Ltotal->Size = System::Drawing::Size(37, 13);
			this->Ltotal->TabIndex = 11;
			this->Ltotal->Text = L"Total: ";
			// 
			// LNuemroTotal
			// 
			this->LNuemroTotal->AutoSize = true;
			this->LNuemroTotal->Location = System::Drawing::Point(45, 500);
			this->LNuemroTotal->Name = L"LNuemroTotal";
			this->LNuemroTotal->Size = System::Drawing::Size(13, 13);
			this->LNuemroTotal->TabIndex = 12;
			this->LNuemroTotal->Text = L"0";
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(805, 480);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(75, 23);
			this->btnGuardar->TabIndex = 13;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &MyForm::btnGuardar_Click);
			// 
			// LrutaDir
			// 
			this->LrutaDir->AutoSize = true;
			this->LrutaDir->Location = System::Drawing::Point(12, 5);
			this->LrutaDir->Name = L"LrutaDir";
			this->LrutaDir->Size = System::Drawing::Size(140, 13);
			this->LrutaDir->TabIndex = 14;
			this->LrutaDir->Text = L"Escribe la ruta de la imagen:";
			// 
			// btnMostrar
			// 
			this->btnMostrar->Location = System::Drawing::Point(246, 24);
			this->btnMostrar->Name = L"btnMostrar";
			this->btnMostrar->Size = System::Drawing::Size(75, 23);
			this->btnMostrar->TabIndex = 15;
			this->btnMostrar->Text = L"Mostrar";
			this->btnMostrar->UseVisualStyleBackColor = true;
			// 
			// textBoxUnion1
			// 
			this->textBoxUnion1->Location = System::Drawing::Point(851, 78);
			this->textBoxUnion1->Name = L"textBoxUnion1";
			this->textBoxUnion1->Size = System::Drawing::Size(42, 20);
			this->textBoxUnion1->TabIndex = 16;
			// 
			// textBoxUnion2
			// 
			this->textBoxUnion2->Location = System::Drawing::Point(913, 78);
			this->textBoxUnion2->Name = L"textBoxUnion2";
			this->textBoxUnion2->Size = System::Drawing::Size(42, 20);
			this->textBoxUnion2->TabIndex = 17;
			// 
			// LUnir
			// 
			this->LUnir->AutoSize = true;
			this->LUnir->Location = System::Drawing::Point(848, 62);
			this->LUnir->Name = L"LUnir";
			this->LUnir->Size = System::Drawing::Size(29, 13);
			this->LUnir->TabIndex = 18;
			this->LUnir->Text = L"Unir:";
			// 
			// LCon
			// 
			this->LCon->AutoSize = true;
			this->LCon->Location = System::Drawing::Point(910, 62);
			this->LCon->Name = L"LCon";
			this->LCon->Size = System::Drawing::Size(28, 13);
			this->LCon->TabIndex = 19;
			this->LCon->Text = L"con:";
			// 
			// ckBoxUnir
			// 
			this->ckBoxUnir->AutoSize = true;
			this->ckBoxUnir->Location = System::Drawing::Point(744, 80);
			this->ckBoxUnir->Name = L"ckBoxUnir";
			this->ckBoxUnir->Size = System::Drawing::Size(83, 17);
			this->ckBoxUnir->TabIndex = 20;
			this->ckBoxUnir->Text = L"Unir índices";
			this->ckBoxUnir->UseVisualStyleBackColor = true;
			// 
			// ckBoxBorrar
			// 
			this->ckBoxBorrar->AutoSize = true;
			this->ckBoxBorrar->Location = System::Drawing::Point(744, 121);
			this->ckBoxBorrar->Name = L"ckBoxBorrar";
			this->ckBoxBorrar->Size = System::Drawing::Size(90, 17);
			this->ckBoxBorrar->TabIndex = 21;
			this->ckBoxBorrar->Text = L"Borrar índice:";
			this->ckBoxBorrar->UseVisualStyleBackColor = true;
			// 
			// txtBoxBorrar
			// 
			this->txtBoxBorrar->Location = System::Drawing::Point(851, 119);
			this->txtBoxBorrar->Name = L"txtBoxBorrar";
			this->txtBoxBorrar->Size = System::Drawing::Size(42, 20);
			this->txtBoxBorrar->TabIndex = 22;
			// 
			// txtBoxSepararIndice
			// 
			this->txtBoxSepararIndice->Location = System::Drawing::Point(854, 178);
			this->txtBoxSepararIndice->Name = L"txtBoxSepararIndice";
			this->txtBoxSepararIndice->Size = System::Drawing::Size(41, 20);
			this->txtBoxSepararIndice->TabIndex = 23;
			// 
			// txtBoxSepararPartes
			// 
			this->txtBoxSepararPartes->Location = System::Drawing::Point(913, 178);
			this->txtBoxSepararPartes->Name = L"txtBoxSepararPartes";
			this->txtBoxSepararPartes->Size = System::Drawing::Size(42, 20);
			this->txtBoxSepararPartes->TabIndex = 24;
			// 
			// LSeparar
			// 
			this->LSeparar->AutoSize = true;
			this->LSeparar->Location = System::Drawing::Point(851, 159);
			this->LSeparar->Name = L"LSeparar";
			this->LSeparar->Size = System::Drawing::Size(47, 13);
			this->LSeparar->TabIndex = 25;
			this->LSeparar->Text = L"Separar:";
			// 
			// LSepararEn
			// 
			this->LSepararEn->AutoSize = true;
			this->LSepararEn->Location = System::Drawing::Point(913, 158);
			this->LSepararEn->Name = L"LSepararEn";
			this->LSepararEn->Size = System::Drawing::Size(23, 13);
			this->LSepararEn->TabIndex = 26;
			this->LSepararEn->Text = L"En:";
			// 
			// ckBoxSeparar
			// 
			this->ckBoxSeparar->AutoSize = true;
			this->ckBoxSeparar->Location = System::Drawing::Point(744, 180);
			this->ckBoxSeparar->Name = L"ckBoxSeparar";
			this->ckBoxSeparar->Size = System::Drawing::Size(96, 17);
			this->ckBoxSeparar->TabIndex = 27;
			this->ckBoxSeparar->Text = L"Separar índice";
			this->ckBoxSeparar->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(973, 525);
			this->Controls->Add(this->ckBoxSeparar);
			this->Controls->Add(this->LSepararEn);
			this->Controls->Add(this->LSeparar);
			this->Controls->Add(this->txtBoxSepararPartes);
			this->Controls->Add(this->txtBoxSepararIndice);
			this->Controls->Add(this->txtBoxBorrar);
			this->Controls->Add(this->ckBoxBorrar);
			this->Controls->Add(this->ckBoxUnir);
			this->Controls->Add(this->LCon);
			this->Controls->Add(this->LUnir);
			this->Controls->Add(this->textBoxUnion2);
			this->Controls->Add(this->textBoxUnion1);
			this->Controls->Add(this->btnMostrar);
			this->Controls->Add(this->LrutaDir);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->LNuemroTotal);
			this->Controls->Add(this->Ltotal);
			this->Controls->Add(this->trackBarPercentil);
			this->Controls->Add(this->imgBox);
			this->Controls->Add(this->btnContar);
			this->Controls->Add(this->txtBoxRuta);
			this->Controls->Add(this->Lpercentil);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarPercentil))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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

		Mat saturate(Mat img) {
			double alpha = 2.0; /*< Simple contrast control */
			int beta = 10;       /*< Simple brightness control */

			Mat new_image = Mat::zeros(img.size(), img.type());
			// << " Basic Linear Transforms " << endl;
			//cout << "-------------------------" << endl;
			//cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
			//cout << "* Enter the beta value [0-100]: ";    cin >> beta;
			for (int y = 0; y < img.rows; y++) {
				for (int x = 0; x < img.cols; x++) {
					for (int c = 0; c < 3; c++) {
						new_image.at<Vec3b>(y, x)[c] =
							saturate_cast<uchar>(alpha*(img.at<Vec3b>(y, x)[c]) + beta);
					}
				}
			}
			return new_image;
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
			vector<vector<cv::Point>> contours;
			vector<Vec4i> hierarchy;
			Rect bounding_rect;
			Mat dst, bin, img_gray;

			//Mat src = imread("./img/4.bmp", CV_LOAD_IMAGE_COLOR); // reads image from file

			cvtColor(src, img_gray, CV_BGR2GRAY);  // converts image from rgb(src) to gray level (dst) 

												   //convert to B&W
			dst = img_gray > 128;


			dst = negativo(dst);

			//namedWindow("128", CV_WINDOW_NORMAL);
			//imshow("128", dst);

			threshold(dst, bin, 20, 255, THRESH_BINARY); // Tresholds image with level = 40 from gray level(dst) to binary (bin)
			findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); // finds contours on bin image


			Scalar color(255, 255, 255);
			for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
			{
				if ((contourArea(contours[i], false))>100) { // if counter area >100 pixel draw it on ero which is new image variable
					drawContours(bin, contours, i, color, CV_FILLED, 8, hierarchy); //Draw contours on itself as filled

				}
			}

			findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

			vector<double> areas;
			//vector<double> longitudes;
			int area;
			//int longitud;
			for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
			{
				bounding_rect = boundingRect(contours[i]); //Bound and Draw rectangle each object which detected at the end on src(original image)
				area = bounding_rect.height*bounding_rect.width;
				areas.push_back(area);
				//longitud = 2 * (bounding_rect.height + bounding_rect.width);
				//longitudes.push_back(longitud);
			}

			double percentil = calcularPercentil(percentilSelecionado, areas);

			numeroGenes = 1;
			for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
			{
				bounding_rect = boundingRect(contours[i]); //Bound and Draw rectangle each object which detected at the end on src(original image)
				area = bounding_rect.height*bounding_rect.width;
				//longitud = 2 * (bounding_rect.height + bounding_rect.width);
				if (area>percentil) {
					rectangle(src, bounding_rect, Scalar(0, 255, 0), 3, 8, 0);
					putText(src, to_string(numeroGenes), Point2f(bounding_rect.x, bounding_rect.y+bounding_rect.height), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 255), 2);
					//putText(src, to_string(longitud), Point2f(bounding_rect.x, bounding_rect.y+30), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 255, 0), 1);
					//putText(src, to_string(area), Point2f(bounding_rect.x, bounding_rect.y + 50), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255, 255, 0), 1);
					numeroGenes++;
				}
			}

			return src;

	}
	Mat contarGenes(Mat src, vector<int> uniones, vector<int> borrar, vector<int> separar, vector<Rect> bounding_rects) {
			Rect bounding_rect;
			numeroGenes = 1;
			for (int i = 0; i< bounding_rects.size(); i++) // iterate through each bound. 
			{
				bounding_rect = bounding_rects.at(i); //Bound and Draw rectangle each object which detected at the end on src(original image)
					if (Contains(uniones, i + 1) || Contains(borrar, i + 1)) {

					}
					else if (separar.at(0) == numeroGenes) {
							for (int j = 0; j < separar.at(1); j++) {
								putText(src, to_string(numeroGenes), Point2f(bounding_rect.x, bounding_rect.y + bounding_rect.height - i * 10), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 255), 2);
								numeroGenes++;
							}
					}
					else {
						putText(src, to_string(numeroGenes), Point2f(bounding_rect.x, bounding_rect.y + bounding_rect.height), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 255), 2);
						numeroGenes++;
					}
			}
			return src;
	}
	vector<Rect> getBoundings(Mat src) {
		vector<vector<cv::Point>> contours;
		vector<Vec4i> hierarchy;
		vector<Rect> bounding_rects;
		Rect bounding_rect;
		Mat dst, bin, img_gray;

		cvtColor(src, img_gray, CV_BGR2GRAY);  // converts image from rgb(src) to gray level (dst)
		dst = img_gray > 128;		   //convert to B&W
		dst = negativo(dst);

		threshold(dst, bin, 20, 255, THRESH_BINARY); // Tresholds image with level = 40 from gray level(dst) to binary (bin)
		findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); // finds contours on bin image

		Scalar color(255, 255, 255);
		for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
		{
			if ((contourArea(contours[i], false))>100) { // if counter area >100 pixel draw it on ero which is new image variable
				drawContours(bin, contours, i, color, CV_FILLED, 8, hierarchy); //Draw contours on itself as filled
			}
		}

		findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
		vector<double> areas;
		int area;

		for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
		{
			bounding_rect = boundingRect(contours[i]); //Bound and Draw rectangle each object which detected at the end on src(original image)
			area = bounding_rect.height*bounding_rect.width;
			areas.push_back(area);
		}

		double percentil = calcularPercentil(percentilSelecionado, areas);
		for (int i = 0; i< contours.size(); i++) // iterate through each contour. 
		{
			bounding_rect = boundingRect(contours[i]); 
			area = bounding_rect.height*bounding_rect.width;
			if (area > percentil) {
				bounding_rects.push_back(bounding_rect);
			}
		}
		return bounding_rects;
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	void MarshalString(System::String^ s, string& os) {
				 using namespace Runtime::InteropServices;
				 const char* chars =
					 (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	vector<int> getBorrarList() {
		vector<int> borrar;
		if (ckBoxBorrar->Checked) {
			
			std::string texto;
			System::String^ systemText1 = txtBoxBorrar->Text;
			MarshalString(systemText1, texto);

			//texto = marshal_as<std::string>(txtBoxBorrar->Text);
			std::string delimiter = ";";

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
	private: System::Void btnContar_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat img = imread("./img/2.bmp", CV_LOAD_IMAGE_COLOR);
		vector<int> borrar;
		vector<int> uniones;
		vector<int> separaciones;
		uniones.push_back(0);
		separaciones.push_back(0);
		separaciones.push_back(0);
		borrar = getBorrarList();

		vector<Rect> bounding_rects;
		bounding_rects = getBoundings(img);

		if(ckBoxBorrar->Checked) {
			img = contarGenes(img, uniones, borrar, separaciones,bounding_rects);
			showImage(img);
		}
		else {
			img = contarGenes(img);
		}
		
		showImage(img);
		
	}
	private: System::Void OntrackBarPercentil_Scroll(System::Object^  sender, System::EventArgs^  e) {
		Lpercentil->Text = System::String::Concat("Percentil empleado: ", trackBarPercentil->Value);
		percentilSelecionado = trackBarPercentil->Value;
		if (percentilSelecionado == 100) {
			percentilSelecionado = 99;
		}
	}
	void showImage(Mat img) {
		int max = 1000;
		int min = 0;
		int range = max - min + 1;
		int num = rand() % range + min;

		imwrite("./img/temp/temp"+to_string(numeroGenes)+"_"+to_string(num)+".bmp", img);
		imgBox->Image = System::Drawing::Image::FromFile(System::String::Concat("./img/temp/temp", numeroGenes,"_",num,".bmp"));
		LNuemroTotal->Text = System::String::Concat("",numeroGenes);
		/*
		imgBox->Image = gcnew Bitmap(img.size().width,
									 img.size().height,
									 img.step,
									 Imaging::PixelFormat::Format24bppRgb,
									 (IntPtr)img.data);
		*/
	}
	void saveImage(string name,Mat img) {
		imwrite("./img/contadas/"+name+".bmp", img);
	}

	private: System::Void btnGuardar_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat img = imread("./img/5.bmp", CV_LOAD_IMAGE_COLOR);
		img = contarGenes(img);
		saveImage("contada1", img);
	}
			 
};
	
}
