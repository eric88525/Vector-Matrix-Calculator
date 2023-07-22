#pragma once
#include"DataManager.h"
#include <string>
#include <stack>
#include <unordered_map>
#define nL System::Environment::NewLine
//#define DEBUG

template <typename T>
T cal(std::string polynomial, std::unordered_map<std::string, T>);

namespace WindowsFormsApplication_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm ���K�n
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			lastInputLength = -1;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}





















	protected:
	protected:

	private:
		/// <summary>
		DataManager* dataManager;
		String^ userInput;
		int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;












	private: System::Windows::Forms::ToolStripMenuItem^ FileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LoadVectorToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::Button^ runBtn;



	private: System::Windows::Forms::Button^ clearBtn;

	private: System::Windows::Forms::TextBox^ Output;





	private: System::Windows::Forms::Label^ InputLabel;
	private: System::Windows::Forms::TextBox^ Input;


	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::DataGridView^ dataTable;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Variable;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Value;


























		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		   /// �o�Ӥ�k�����e�C
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WindowsForm::typeid));
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			   this->runBtn = (gcnew System::Windows::Forms::Button());
			   this->clearBtn = (gcnew System::Windows::Forms::Button());
			   this->Output = (gcnew System::Windows::Forms::TextBox());
			   this->InputLabel = (gcnew System::Windows::Forms::Label());
			   this->Input = (gcnew System::Windows::Forms::TextBox());
			   this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			   this->dataTable = (gcnew System::Windows::Forms::DataGridView());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			   this->Variable = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->menuStrip2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			   this->splitContainer1->Panel1->SuspendLayout();
			   this->splitContainer1->Panel2->SuspendLayout();
			   this->splitContainer1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			   this->splitContainer2->Panel1->SuspendLayout();
			   this->splitContainer2->Panel2->SuspendLayout();
			   this->splitContainer2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataTable))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			   this->splitContainer3->Panel1->SuspendLayout();
			   this->splitContainer3->Panel2->SuspendLayout();
			   this->splitContainer3->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			   // 
			   // FileToolStripMenuItem
			   // 
			   this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->LoadVectorToolStripMenuItem });
			   this->FileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			   this->FileToolStripMenuItem->Size = System::Drawing::Size(74, 32);
			   this->FileToolStripMenuItem->Text = L"Open";
			   this->FileToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::FileToolStripMenuItem_Click);
			   // 
			   // LoadVectorToolStripMenuItem
			   // 
			   this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			   this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(187, 32);
			   this->LoadVectorToolStripMenuItem->Text = L"Load Data";
			   this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			   // 
			   // menuStrip2
			   // 
			   this->menuStrip2->BackColor = System::Drawing::SystemColors::HighlightText;
			   this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			   this->menuStrip2->Location = System::Drawing::Point(0, 0);
			   this->menuStrip2->Name = L"menuStrip2";
			   this->menuStrip2->Size = System::Drawing::Size(1133, 36);
			   this->menuStrip2->TabIndex = 1;
			   this->menuStrip2->Text = L"menuStrip2";
			   // 
			   // runBtn
			   // 
			   this->runBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->runBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->runBtn->Location = System::Drawing::Point(957, 17);
			   this->runBtn->Margin = System::Windows::Forms::Padding(27, 4, 4, 4);
			   this->runBtn->Name = L"runBtn";
			   this->runBtn->Size = System::Drawing::Size(162, 48);
			   this->runBtn->TabIndex = 9;
			   this->runBtn->Text = L"Execute";
			   this->runBtn->UseVisualStyleBackColor = true;
			   this->runBtn->Click += gcnew System::EventHandler(this, &WindowsForm::runBtn_Click);
			   // 
			   // clearBtn
			   // 
			   this->clearBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearBtn.BackgroundImage")));
			   this->clearBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->clearBtn->Font = (gcnew System::Drawing::Font(L"�L�n������", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->clearBtn->Location = System::Drawing::Point(8, 16);
			   this->clearBtn->Margin = System::Windows::Forms::Padding(27, 4, 4, 4);
			   this->clearBtn->Name = L"clearBtn";
			   this->clearBtn->Size = System::Drawing::Size(50, 48);
			   this->clearBtn->TabIndex = 6;
			   this->clearBtn->UseVisualStyleBackColor = true;
			   this->clearBtn->Click += gcnew System::EventHandler(this, &WindowsForm::clearBtn_Click);
			   // 
			   // Output
			   // 
			   this->Output->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->Output->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Output->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->Output->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Output->Location = System::Drawing::Point(4, 57);
			   this->Output->Margin = System::Windows::Forms::Padding(4);
			   this->Output->Multiline = true;
			   this->Output->Name = L"Output";
			   this->Output->ReadOnly = true;
			   this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			   this->Output->Size = System::Drawing::Size(367, 475);
			   this->Output->TabIndex = 1;
			   // 
			   // InputLabel
			   // 
			   this->InputLabel->AutoSize = true;
			   this->InputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->InputLabel->Location = System::Drawing::Point(8, 5);
			   this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->InputLabel->Name = L"InputLabel";
			   this->InputLabel->Size = System::Drawing::Size(134, 31);
			   this->InputLabel->TabIndex = 0;
			   this->InputLabel->Text = L"Commands";
			   // 
			   // Input
			   // 
			   this->Input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->Input->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(26) {
				   L"printv", L"calv", L"norm", L"normal",
					   L"cross", L"com", L"proj", L"area", L"isparallel", L"isorthogonal", L"angle", L"pn", L"isli", L"ob", L"cal<Matrix>", L"printm",
					   L"rank", L"trans", L"sol", L"det", L"inverse", L"adj", L"pm", L"eigen", L"rref", L"leastsquare"
			   });
			   this->Input->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			   this->Input->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			   this->Input->BackColor = System::Drawing::SystemColors::Window;
			   this->Input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->Input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Input->Location = System::Drawing::Point(7, 43);
			   this->Input->Margin = System::Windows::Forms::Padding(0);
			   this->Input->Multiline = true;
			   this->Input->Name = L"Input";
			   this->Input->Size = System::Drawing::Size(730, 257);
			   this->Input->TabIndex = 8;
			   this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			   // 
			   // splitContainer1
			   // 
			   this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->splitContainer1->Location = System::Drawing::Point(3, 3);
			   this->splitContainer1->Name = L"splitContainer1";
			   // 
			   // splitContainer1.Panel1
			   // 
			   this->splitContainer1->Panel1->Controls->Add(this->label2);
			   this->splitContainer1->Panel1->Controls->Add(this->Output);
			   // 
			   // splitContainer1.Panel2
			   // 
			   this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			   this->splitContainer1->Size = System::Drawing::Size(1125, 538);
			   this->splitContainer1->SplitterDistance = 375;
			   this->splitContainer1->TabIndex = 14;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(7, 13);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(91, 31);
			   this->label2->TabIndex = 9;
			   this->label2->Text = L"Output";
			   // 
			   // splitContainer2
			   // 
			   this->splitContainer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->splitContainer2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->splitContainer2->Location = System::Drawing::Point(0, 0);
			   this->splitContainer2->Name = L"splitContainer2";
			   this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			   // 
			   // splitContainer2.Panel1
			   // 
			   this->splitContainer2->Panel1->Controls->Add(this->dataTable);
			   this->splitContainer2->Panel1->Controls->Add(this->label1);
			   // 
			   // splitContainer2.Panel2
			   // 
			   this->splitContainer2->Panel2->Controls->Add(this->Input);
			   this->splitContainer2->Panel2->Controls->Add(this->InputLabel);
			   this->splitContainer2->Size = System::Drawing::Size(746, 538);
			   this->splitContainer2->SplitterDistance = 231;
			   this->splitContainer2->TabIndex = 0;
			   // 
			   // dataTable
			   // 
			   this->dataTable->AllowUserToDeleteRows = false;
			   this->dataTable->AllowUserToOrderColumns = true;
			   dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			   this->dataTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			   this->dataTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->dataTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->dataTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			   dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->dataTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			   this->dataTable->ColumnHeadersHeight = 40;
			   this->dataTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Variable, this->Value });
			   this->dataTable->Location = System::Drawing::Point(3, 55);
			   this->dataTable->Name = L"dataTable";
			   dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			   dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Control;
			   dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			   dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->dataTable->RowHeadersDefaultCellStyle = dataGridViewCellStyle5;
			   this->dataTable->RowHeadersWidth = 51;
			   this->dataTable->RowTemplate->Height = 27;
			   this->dataTable->Size = System::Drawing::Size(734, 162);
			   this->dataTable->TabIndex = 9;
			   this->dataTable->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &WindowsForm::dataGridView1_CellContentClick);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(10, 13);
			   this->label1->Name = L"label1";
			   this->label1->Padding = System::Windows::Forms::Padding(0, 4, 0, 4);
			   this->label1->Size = System::Drawing::Size(74, 39);
			   this->label1->TabIndex = 8;
			   this->label1->Text = L"Datas";
			   // 
			   // splitContainer3
			   // 
			   this->splitContainer3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->splitContainer3->BackColor = System::Drawing::Color::Transparent;
			   this->splitContainer3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->splitContainer3->Location = System::Drawing::Point(0, 39);
			   this->splitContainer3->Name = L"splitContainer3";
			   this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			   // 
			   // splitContainer3.Panel1
			   // 
			   this->splitContainer3->Panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			   this->splitContainer3->Panel1->Controls->Add(this->splitContainer1);
			   // 
			   // splitContainer3.Panel2
			   // 
			   this->splitContainer3->Panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			   this->splitContainer3->Panel2->Controls->Add(this->clearBtn);
			   this->splitContainer3->Panel2->Controls->Add(this->runBtn);
			   this->splitContainer3->Size = System::Drawing::Size(1133, 630);
			   this->splitContainer3->SplitterDistance = 546;
			   this->splitContainer3->TabIndex = 15;
			   // 
			   // Variable
			   // 
			   this->Variable->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			   dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Variable->DefaultCellStyle = dataGridViewCellStyle3;
			   this->Variable->HeaderText = L"Variable";
			   this->Variable->MaxInputLength = 20;
			   this->Variable->MinimumWidth = 6;
			   this->Variable->Name = L"Variable";
			   this->Variable->ReadOnly = true;
			   this->Variable->Width = 125;
			   // 
			   // Value
			   // 
			   this->Value->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			   dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Value->DefaultCellStyle = dataGridViewCellStyle4;
			   this->Value->HeaderText = L"Value";
			   this->Value->MinimumWidth = 6;
			   this->Value->Name = L"Value";
			   // 
			   // WindowsForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1133, 668);
			   this->Controls->Add(this->splitContainer3);
			   this->Controls->Add(this->menuStrip2);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"WindowsForm";
			   this->Text = L"VectorExample";
			   this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			   this->menuStrip2->ResumeLayout(false);
			   this->menuStrip2->PerformLayout();
			   this->splitContainer1->Panel1->ResumeLayout(false);
			   this->splitContainer1->Panel1->PerformLayout();
			   this->splitContainer1->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			   this->splitContainer1->ResumeLayout(false);
			   this->splitContainer2->Panel1->ResumeLayout(false);
			   this->splitContainer2->Panel1->PerformLayout();
			   this->splitContainer2->Panel2->ResumeLayout(false);
			   this->splitContainer2->Panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			   this->splitContainer2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataTable))->EndInit();
			   this->splitContainer3->Panel1->ResumeLayout(false);
			   this->splitContainer3->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			   this->splitContainer3->ResumeLayout(false);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void WindowsForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//�}��Dialog
		openFileDialog1->ShowDialog();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		//�bDialog���UOK�K�|�i�J���禡
		//�r�����string^ to string
		std::string tempFileName;
		MarshalString(openFileDialog1->FileName, tempFileName);
		//�N�ɮ׸��|�W�ٶǤJdataManager
		dataManager->SetFileName(tempFileName);
		//�qŪ��Ū���V�q���
		if (dataManager->LoadData())
		{
			//�NVectorList�����إ����M��
			this->dataTable->Rows->Clear();
			//���o�Ҧ��V�q���
			std::vector<Vector> vectors = dataManager->GetVectors();
			std::vector<Matrix> matrices = dataManager->GetMatrices();
			if (vectors.size()) {
				for (auto const &v : vectors)
				{
					//�N�ɮצW�٦s�J�Ȧs
					std::string tempString="";
					//�N��X�榡�s�J�Ȧs
					tempString += "[";
					//�N��X��Ʀs�J�Ȧs
					for (unsigned int j = 0; j < v.data.size(); j++)
					{
						std::string scalarString = std::to_string(v.data[j]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (j != v.data.size() - 1)
							tempString += ", ";
					}
					//�N��X�榡�s�J�Ȧs
					tempString += "]";
					//�N���إ[�JVectorList��
					//VectorList->Items->Add(gcnew String(tempString.c_str()));

					this->dataTable->Rows->Add(
						gcnew array<String^>{gcnew String(v.name.c_str()),
						gcnew String(tempString.c_str())}
					);
				}
			}
			if (matrices.size()) {
				for (auto m : matrices)
				{
					std::string tempString="";
					tempString += "[";
					for (int row = 0; row < m.row; row++) {
						for (int col = 0; col < m.col; col++) {
							std::string scalarString = std::to_string(m.data[row][col]);
							tempString += scalarString.substr(0, scalarString.size() - 5);
							if (!(row == m.row - 1 && col == m.col - 1))
								tempString += ",";
						}
					}
					tempString += "]";
					//VectorList->Items->Add(gcnew String(tempString.c_str()));
					this->dataTable->Rows->Add(
						gcnew array<String^>{gcnew String(m.name.c_str()),
						gcnew String(tempString.c_str())}
					);
				}

			}
			Output->Text += "[INFO] File loaded successfully" + nL;
		}
	}
	private: System::Void FileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void clearBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		dataTable->Rows->Clear();
		dataManager->clear();
		Input->Text = "";
	}
	private: void ProcessInput() {

		//�N�ϥΪ̿�J�r��(�buserInput��)�A�̪ťէ@����
		array<String^>^ inp = userInput->Split(' ', ',');

		// convert to std::string
		std::vector<std::string> userCommand(inp->Length);
		for (int s = 0; s < inp->Length; s++)
			MarshalString(inp[s], userCommand[s]);

		if (inp->Length > 2) {
			userCommand[1].erase(0, 1);
			userCommand[userCommand.size() - 1].pop_back();
		}
		Vector v, v1, vResult;
		Matrix m, m1, mResult;
		//�r�����A�Y���O��"print"�����p
		Output->Text += "[CMD] " + userInput + nL;

		std::string command = userCommand[0];

		for (auto& c : command)
			c = tolower(c);

		try {

			std::unordered_map<std::string, Vector> v_lookup;
			std::unordered_map<std::string, Matrix> m_lookup;

			for (auto const& item : dataManager->GetVectors())
				v_lookup[item.name] = item;

			for (auto const& item : dataManager->GetMatrices())
				m_lookup[item.name] = item;

			std::transform(command.begin(), command.end(), command.begin(), ::tolower);

			if (command == "printv") {
				vResult = cal<Vector>(userCommand[1], v_lookup);
				Output->Text += vResult.GetResult();
			}
			else if (command == "norm") {
				vResult = cal<Vector>(userCommand[1], v_lookup);
				double db = Norm(vResult);
				Output->Text += db + nL;
			}
			else if (command == "normal") {
				vResult = cal<Vector>(userCommand[1], v_lookup);
				vResult = Normalization(vResult);
				Output->Text += vResult.GetResult();
			}
			else if (command == "cross" || command == "com" || command == "proj") {
				v = cal<Vector>(userCommand[1], v_lookup);
				v1 = cal<Vector>(userCommand[2], v_lookup);
				if (command == "cross") {
					vResult = CrossProduct(v, v1);
				}
				else if (command == "com") {
					vResult = ::Component(v, v1);
				}
				else {
					vResult = Projection(v, v1);
				}
				Output->Text += vResult.GetResult();
			}
			else if (command == "area") {
				v = cal<Vector>(userCommand[1], v_lookup);
				v1 = cal<Vector>(userCommand[2], v_lookup);
				double db = Area(v, v1);
				Output->Text += db + nL;
			}
			else if (command == "isparallel" || command == "isorthogonal") {
				v = cal<Vector>(userCommand[1], v_lookup);
				v1 = cal<Vector>(userCommand[2], v_lookup);
				if (command == "isparallel") {
					Output->Text += (IsParallel(v, v1) ? "Yes" : "No") + nL;
				}
				else {
					Output->Text += (IsOrthogonal(v, v1) ? "Yes" : "No") + nL;
				}
			}
			else if (command == "angle") {
				v = cal<Vector>(userCommand[1], v_lookup);
				v1 = cal<Vector>(userCommand[2], v_lookup);
				double db = Angle(v, v1);
				Output->Text += "theta = " + db + nL;
			}
			else if (command == "pn" || command == "isli") {
				v = cal<Vector>(userCommand[1], v_lookup);
				v1 = cal<Vector>(userCommand[2], v_lookup);
				if (command == "pn") {
					vResult = PN(v, v1);
					Output->Text += vResult.GetResult();
				}
				else {
					Output->Text += (IsLI(v, v1) ? "Yes" : "No") + nL;
				}
			}
			else if (command == "ob") {
				std::vector<Vector> varr;
				std::vector<Vector> op;
				for (int i = 1; i < userCommand.size(); i++) {
					varr.push_back(cal<Vector>(userCommand[i], v_lookup));
				}
				op = Ob(varr);
				for (auto i : op) {
					Output->Text += i.GetResult();
				}
			}
			else if (command == "printm") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				Output->Text += mResult.GetResult();
			}
			else if (command == "rank") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				int rk = Rank(mResult);
				Output->Text += rk + nL;
			}
			else if (command == "trans") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				mResult = Transpose(mResult);
				Output->Text += mResult.GetResult();
			}
			else if (command == "sol") {
				m = cal<Matrix>(userCommand[1], m_lookup);
				m1 = cal<Matrix>(userCommand[2], m_lookup);
				mResult = m / m1;
				Output->Text += mResult.GetResult();
			}
			else if (command == "det") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				double db = Determinants(mResult);
				Output->Text += db + nL;
			}
			else if (command == "inverse") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				mResult = Inverse(mResult);
				Output->Text += mResult.GetResult();
			}
			else if (command == "adj") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				mResult = Adj(mResult);
				Output->Text += mResult.GetResult();
			}
			else if (command == "pm") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				double db = 0;
				mResult = Pm(mResult, db);
				Output->Text += "v=" + nL + mResult.GetResult() + nL;
				Output->Text += "d=" + nL + db + nL;
			}
			else if (command == "eigen") {
				std::vector<double> eigenValues;
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				mResult = Eigen(mResult, eigenValues);
				Output->Text += "v =" + nL + mResult.GetResult() + nL + "d =" + nL;
				for (int i = 0; i < eigenValues.size(); i++) {
					for (int j = 0; j < eigenValues.size(); j++) {
						Output->Text += (i == j ? eigenValues[i] : 0);
						Output->Text += "   ";
					}
					Output->Text += nL;
				}
			}
			else if (command == "rref") {
				mResult = cal<Matrix>(userCommand[1], m_lookup);
				std::vector<Matrix> result = Rref(mResult);
				Output->Text += result[1].GetResult() + nL;
				Output->Text += result[0].GetResult() + nL;
			}
			else if (command == "leastsquare") {
				m = cal<Matrix>(userCommand[1], m_lookup);
				m1 = cal<Matrix>(userCommand[2], m_lookup);
				mResult = LeastSquare(m, m1);
				Output->Text += mResult.GetResult();
			}
			else {
				Output->Text += "[ERROR] Command not exist." + nL;
			}
			userInput = "";
		}
		catch (Error err) {
			switch (err) {
			case Vector_name_error:
				Output->Text += "[ERROR] Vector name error." + nL;
				break;
			case Matrix_name_error:
				Output->Text += "[ERROR] Matrix name error." + nL;
				break;
			case V_rankdiff:
				Output->Text += "[ERROR] Vector rank difference." + nL;
				break;
			case M_Rank_different:
				Output->Text += "[ERROR] Matrix rank difference." + nL;
				break;
			case no_Inverse:
				Output->Text += "[ERROR] Matrix no Inverse." + nL;
				break;
			case eigen_Cant_zero:
				Output->Text += "[ERROR] Eigen value can not be 0." + nL;
				break;
			case Vectors_empty:
				Output->Text += "[ERROR] No vectors list." + nL;
				break;
			case Matrices_empty:
				Output->Text += "[ERROR] No m_lookup list." + nL;
				break;
			default:
				break;
			}
		}
	}
	private: System::Void runBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		userInput = Input->Text;

		//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
		auto input_lines = Input->Text->Split(gcnew array<String^> { "\r\n" }, StringSplitOptions::None);

		for (int i = 0; i < input_lines->Length; i++) {
			userInput = input_lines[i];
			if (userInput->Length < 1)
				continue;
			ProcessInput();
		}

		Input->Text = "";
	}
	private: System::Void clearOutputBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Output->Text = "";
	}
	private: System::Void Input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}



	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	};
}
