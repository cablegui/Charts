#pragma once
#include <string>
//#include <locale>

namespace Charts {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Data;
	using namespace System::Drawing;
	
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected: 
	private: System::Windows::Forms::Button^  button1;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea6->CursorX->LineColor = System::Drawing::Color::Lime;
			chartArea6->Name = L"Branch1";
			this->chart1->ChartAreas->Add(chartArea6);
			legend6->Name = L"Branch1";
			this->chart1->Legends->Add(legend6);
			this->chart1->Location = System::Drawing::Point(12, 49);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(381, 251);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(505, 273);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 27);
			this->button1->TabIndex = 1;
			this->button1->Text = L"tryout";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(642, 314);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				array<String ^> ^myString = gcnew array<String ^> {"Series1","Series2","Series3","Series4"};
				//setlocale(LC_CTYPE,""); 
				chart1->Series->Add(myString[0]);
				//chart1->BackColor = Color::Blue;

				//chart1->Series[myString[0]]->ChartArea = "Branch1";
				//chart1->ChartAreas["Branch1"]->AxisX->MinorGrid->Enabled = true;
				chart1->ChartAreas["Branch1"]->AxisX->MajorGrid->LineColor = Color::White;
				chart1->ChartAreas["Branch1"]->AxisY->MajorGrid->LineColor = Color::White;
				chart1->Legends["Branch1"]->Enabled = false;
				chart1->ChartAreas["Branch1"]->AxisX->Title = "Time";
				chart1->ChartAreas["Branch1"]->AxisX->IsStartedFromZero = true;
				chart1->ChartAreas["Branch1"]->AxisX->Minimum = 0;
				//chart1->ChartAreas["Branch1"]->Area3DStyle->Enable3D = true;
				chart1->ChartAreas["Branch1"]->AxisY->LineColor = Color::White;
				chart1->ChartAreas["Branch1"]->AxisY->LabelStyle->ForeColor = Color::White;
				//chart1->Series[myString[0]]->IsValueShownAsLabel = true;
 				chart1->Series[myString[0]]->ChartType = SeriesChartType::Line;
				//chart1->Series[myString[0]]->Label = "Y=#VALY\nX=#VALX";
 				//chart1->Series[myString[0]]->Points->AddXY(1,100);
				//chart1->Series[myString[0]]->Points[0]->AxisLabel = "MyAxisLabel";
				chart1->Series[myString[0]]->Points->AddXY(0,100);
				wchar_t orig = 0x2080; // for subscript
				chart1->Series[myString[0]]->Points[0]->Label = String::Concat("""","S",orig," =",100,"\n","C",orig, " = ",91.5,"""");
				chart1->Series[myString[0]]->Points->AddXY(1,150);
				orig++;
				chart1->Series[myString[0]]->Points[1]->Label = String::Concat("""","S",orig," =",150,"\n","C",orig, " = ",102,"""");
				//Problem? How do I place labels at every data point?

				chart1->Series->Add(myString[1]);
				chart1->Series[myString[1]]->ChartType = SeriesChartType::Line;
				chart1->Series[myString[1]]->Points->AddXY(0,100);
				
				chart1->Series[myString[1]]->Points->AddXY(1,50);
				chart1->Series[myString[1]]->Points[1]->Label = String::Concat("""","S",orig," =",50,"\n","C",orig, " = ",90,"""");
				chart1->Series->Add(myString[2]);
				chart1->Series->Add(myString[3]);
				chart1->Series[myString[2]]->ChartType = SeriesChartType::Line;
				chart1->Series[myString[3]]->ChartType = SeriesChartType::Line;
				chart1->Series[myString[2]]->Points->AddXY(1,150);
				chart1->Series[myString[2]]->Points->AddXY(2,100);
				orig++;
				chart1->Series[myString[2]]->Points[1]->Label = String::Concat("""","S",orig," =",100,"\n","C",orig, " = ",91.5,"""");
				chart1->Series[myString[3]]->Points->AddXY(1,50);				
				chart1->Series[myString[3]]->Points->AddXY(2,100);
				chart1->Series[myString[3]]->Points[1]->Label = String::Concat("""","S",orig," =",100,"\n","C",orig, " = ",91.5,"""");
			 }
	};
}

