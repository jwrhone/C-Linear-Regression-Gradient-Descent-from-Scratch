#pragma once
#include "Func.h"

#include <string>
#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <vector>
#include <fstream>
#include <cmath>
using namespace Eigen;
using namespace std;

namespace MachineLearningProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ outputText;


	private: System::Windows::Forms::TextBox^ textBox4;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox5;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->outputText = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(20) {
				L"Austin, Texas", L"Charlotte, North Carolina",
					L"Chicago, Illinois", L"Columbus, Ohio", L"Dallas, Texas", L"Denver, Colorado", L"Fort Worth, Texas", L"Houston, Texas", L"Indianapolis, Indiana",
					L"Jacksonville, Florida", L"Los Angeles, California", L"New York, New York", L"Philadelphia, Pennsylvania", L"Phoenix, Arizona",
					L"San Antonio, Texas", L"San Diego, California", L"San Francisco, California", L"San Jose, California", L"Seattle, Washington",
					L"Washington, DC"
			});
			this->listBox1->Location = System::Drawing::Point(12, 41);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(224, 364);
			this->listBox1->Sorted = true;
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(383, 246);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 70);
			this->button1->TabIndex = 1;
			this->button1->Text = L"(6) Predict Temperature";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"(2) Location Select:";
			// 
			// listBox2
			// 
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 20;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->listBox2->Location = System::Drawing::Point(252, 158);
			this->listBox2->Name = L"listBox2";
			this->listBox2->ScrollAlwaysVisible = true;
			this->listBox2->Size = System::Drawing::Size(90, 84);
			this->listBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(249, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"(3) Select Month:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(414, 156);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(105, 31);
			this->textBox1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(384, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(189, 15);
			this->label3->TabIndex = 6;
			this->label3->Text = L"(4) Enter Mean Temperature (F‹):";
			// 
			// outputText
			// 
			this->outputText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputText->Location = System::Drawing::Point(255, 376);
			this->outputText->Name = L"outputText";
			this->outputText->ReadOnly = true;
			this->outputText->Size = System::Drawing::Size(315, 29);
			this->outputText->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(252, 262);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(252, 246);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(98, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Location Elevation:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(267, 93);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(280, 42);
			this->button2->TabIndex = 14;
			this->button2->Text = L"(1) Generate Linear Regression Gradient Descent Model";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(252, 339);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(315, 20);
			this->textBox2->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(252, 323);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Regression Formula:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(252, 360);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Max Temperature (F):";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(372, 191);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(210, 15);
			this->label7->TabIndex = 19;
			this->label7->Text = L"(5) Enter Minimum Temperature (F‹):";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(414, 209);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(105, 31);
			this->textBox3->TabIndex = 18;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(306, 0);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(179, 17);
			this->checkBox1->TabIndex = 20;
			this->checkBox1->Text = L"Use Pre-Generated Model (OLS)";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(306, 23);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(241, 17);
			this->checkBox2->TabIndex = 21;
			this->checkBox2->Text = L"Use Pre-Generated Model (Gradient Descent)";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(306, 46);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(210, 17);
			this->checkBox3->TabIndex = 22;
			this->checkBox3->Text = L"Exclude Elevation in Regression Model";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(315, 60);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(276, 26);
			this->label8->TabIndex = 23;
			this->label8->Text = L"*Note: Must be checked before button below is pressed. \r\nIf checked after, button"
				L" below will cause a crash\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(252, 285);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(106, 13);
			this->label9->TabIndex = 26;
			this->label9->Text = L"Mean Absolute Error:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(252, 301);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 25;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(585, 417);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->outputText);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"ML Project";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ currentTemp = textBox1->Text;
		String^ minTemp = textBox3->Text;
		String^ location = listBox1->SelectedItem->ToString();
		String^ mon = listBox2->SelectedItem->ToString();

		String^ elev = "No location selected";
		String^ lat = "No location selected";
		String^ lon = "No location selected";

		
		if (location->Contains("Austin"))
		{
			elev = "1,080";
			lat = "30.266666";
			lon = "-97.733330";
		}
		if (location->Contains("Charlotte"))
		{
			elev = "784";
			lat = "35.227085";
			lon = "-80.843124";
		}
		if (location->Contains("Chicago"))
		{
			elev = "673";
			lat = "41.881832";
			lon = "-87.623177";
		}
		if (location->Contains("Columbus"))
		{
			elev = "893";
			lat = "39.983334";
			lon = "-82.983330";
		}
		if (location->Contains("Dallas"))
		{
			elev = "686";
			lat = "32.779167";
			lon = "-96.808891";
		}
		if (location->Contains("Denver"))
		{
			elev = "5,470";
			lat = "39.742043";
			lon = "-104.991531";
		}
		if (location->Contains("Fort Worth"))
		{
			elev = "766";
			lat = "32.768799";
			lon = "-97.309341";
		}
		if (location->Contains("Houston"))
		{
			elev = "83";
			lat = "29.749907";
			lon = "-95.358421";
		}
		if (location->Contains("Indianapolis"))
		{
			elev = "845";
			lat = "39.791000";
			lon = "-86.148003";
		}
		if (location->Contains("Jacksonville"))
		{
			elev = "22";
			lat = "30.332184";
			lon = "-81.655647";
		}
		if (location->Contains("Los Angeles"))
		{
			elev = "5074";
			lat = "34.052235";
			lon = "-118.243683";
		}
		if (location->Contains("New York"))
		{
			elev = "410";
			lat = "40.730610";
			lon = "-73.935242";
		}
		if (location->Contains("Philadelphia"))
		{
			elev = "441";
			lat = "39.952583";
			lon = "-75.165222";
		}
		if (location->Contains("Phoenix"))
		{
			elev = "1160";
			lat = "33.448376";
			lon = "-112.074036";
		}
		if (location->Contains("San Antonio"))
		{
			elev = "1000";
			lat = "29.424349";
			lon = "-98.491142";
		}
		if (location->Contains("San Diego"))
		{
			elev = "823";
			lat = "32.715736";
			lon = "-117.161087";
		}
		if (location->Contains("San Francisco"))
		{
			elev = "934";
			lat = "37.773972";
			lon = "-122.431297";
		}
		if (location->Contains("San Jose"))
		{
			elev = "2125";
			lat = "37.335480";
			lon = "-121.893028";
		}
		if (location->Contains("Seattle"))
		{
			elev = "520";
			lat = "47.620422";
			lon = "-122.349358";
		}
		if (location->Contains("Washington"))
		{
			elev = "410";
			lat = "39.52";
			lon = "77.069";
		}

		textBox4->Text = elev + "ft.";
		//elev is in feet -> convert to meters for linear regression
		//Temp in F -> convert to C
		double current_temp = System::Convert::ToDouble(currentTemp);
		double min_temp = System::Convert::ToDouble(minTemp);
		double elevation = System::Convert::ToDouble(elev);
		double month = System::Convert::ToDouble(mon);

		elevation = feetToMeters(elevation);
		current_temp = FtoC(current_temp);
		min_temp = FtoC(min_temp);
		
		//MinTemp, MeanTemp, Month, Elevation, constant
		double output_temp;
		if(checkBox3->Checked)
			output_temp = (min_temp * coef0) + (current_temp * coef1) + (month * coef2) +  coef3;
		else
			output_temp = (min_temp * coef0) + (current_temp * coef1) + (month * coef2) + (elevation * coef3) + numCon;

		output_temp = CtoF(output_temp);

		outputText->Text = output_temp.ToString("##.#");
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		//loading csv dataset
		MatrixXd matrix_load;
		if (checkBox3->Checked) {
			matrix_load = openData("dataNoLatLonElev.csv");
			cout << "Using CSV without Eleavtion" << endl;
		}
		else {
			matrix_load = openData("dataNoLatLon.csv");
			cout << "Using CSV with Elevation" << endl;
		}

		//shuffle data
		MatrixXd matrix = matrixShuffle(matrix_load);

		MatrixXd norm = Normalize(matrix);

		MatrixXd X_train, y_train, X_test, y_test;

		tuple<MatrixXd, MatrixXd, MatrixXd, MatrixXd> split_data = trainTestSplit(norm, 0.8);
		tie(X_train, y_train, X_test, y_test) = split_data;

		VectorXd vec_train = VectorXd::Ones(X_train.rows());
		VectorXd vec_test = VectorXd::Ones(X_test.rows());

		X_train.conservativeResize(X_train.rows(), X_train.cols() + 1);
		X_train.col(X_train.cols() - 1) = vec_train;
		X_test.conservativeResize(X_test.rows(), X_test.cols() + 1);
		X_test.col(X_test.cols() - 1) = vec_test;

		VectorXd theta = VectorXd::Zero(X_train.cols());
		float alpha = 1;
		int iters = 5000;

		//flag to see if model has been generated yet
		bool modelGen, trained;
		if (trained == true)
			modelGen = true;
		else
			modelGen = false;

		bool withElevation = true;
		if (checkBox3->Checked)
			withElevation = false;

		double error;

		if (checkBox1->Checked) {
			//10k iters:
			coef0 = -8.75527599e-01;
			coef1 = 1.86719359e+00;
			coef2 = -2.99238203e-03;
			coef3 = -2.56420115e-06;
			numCon = 0.7439530370933625;
			//OLS Pre-trained
			cout << "Model Generated" << endl;
			cout << "Regression Parameters:" << endl;
			cout << "coef0: " << coef0 << endl;
			cout << "coef1: " << coef1 << endl;
			cout << "coef2: " << coef2 << endl;
			cout << "coef3: " << coef3 << endl;
			cout << "Constant: " << numCon << endl;

			error = meanAbsoluteError(y_test, X_test, coef0, coef1, coef2, coef3, numCon, withElevation);
		}
		else if (checkBox2->Checked) {
			//5k iters:
			coef0 = 0.4296;
			coef1 = 0.6325;
			coef2 = -0.0229;
			coef3 = 0.0739;
			numCon = 0.0123;
			//GD Pre-trained
			cout << "Model Generated" << endl;
			cout << "Regression Parameters:" << endl;
			cout << "coef0: " << coef0 << endl;
			cout << "coef1: " << coef1 << endl;
			cout << "coef2: " << coef2 << endl;
			cout << "coef3: " << coef3 << endl;
			cout << "Constant: " << numCon << endl;

			error = meanAbsoluteError(y_test, X_test, coef0, coef1, coef2, coef3, numCon, withElevation);
		}
		else {

			if (modelGen == true) {// if regression model has been trained, use those trained parameter values:
				coef0 = gdc0;
				coef1 = gdc1;
				coef2 = gdc2;
				coef3 = gdc3;
				numCon = gdcNumCon;
				cout << "Model Generated" << endl;
				cout << "Regression Parameters:" << endl;
				cout << "coef0: " << coef0 << endl;
				cout << "coef1: " << coef1 << endl;
				cout << "coef2: " << coef2 << endl;
				cout << "coef3: " << coef3 << endl;
				cout << "Constant: " << numCon << endl;
				error = gdError;
			}

			if (modelGen == false) {// if regression model has not been trained do this:
				
				trained = true;

				VectorXd thetaOut;
				vector<float> cost;

				tuple<VectorXd, vector<float>> gd = GradDescent(X_train, y_train, theta, alpha, iters);
				tie(thetaOut, cost) = gd;

				gdc0 = coef0 = thetaOut(0);
				gdc1 = coef1 = thetaOut(1);
				gdc2 = coef2 = thetaOut(2);
				gdc3 = coef3 = thetaOut(3);
				gdcNumCon = numCon = thetaOut(4);

				modelGen = true;

				cout << "Model Generated" << endl;
				cout << "Regression Parameters:" << endl;
				cout << "coef0: " << coef0 << endl;
				cout << "coef1: " << coef1 << endl;
				cout << "coef2: " << coef2 << endl;
				cout << "coef3: " << coef3 << endl;
				cout << "Constant: " << numCon << endl;

				error = meanAbsoluteError(y_test, X_test, coef0, coef1, coef2, coef3, numCon, withElevation);
				gdError = error;
			}
		}
		if(checkBox3-> Checked)
			textBox2->Text = "y = x0(" + coef0.ToString("##.####") + ") + x1(" + coef1.ToString("##.####") + ") + x2(" + coef2.ToString("##.####") + ") + " + coef3.ToString("##.####");
		else
			textBox2->Text = "y = x0(" + coef0.ToString("##.####") + ") + x1(" + coef1.ToString("##.####") + ") + x2(" + coef2.ToString("##.####") + ") + x3(" + coef3.ToString("##.####") + ") + " + numCon.ToString("##.####");

		textBox5->Text = error.ToString("##.#####");

	}
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
