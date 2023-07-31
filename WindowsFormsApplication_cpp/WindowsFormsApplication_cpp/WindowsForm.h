#pragma once
#include "Command.h"
#include"DataManager.h"
#include "Operation.h"
#include <string>
#include <stack>
#include <unordered_map>
#include <regex>
#include <iostream>
#include <sstream>

//#define DEBUG

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
			data_manager = new DataManager();

			InitializeCommands();

			lastInputLength = -1;
		}

		void InitializeCommands() {
			command_factory = new CommandFactory();
			// vector
			command_factory->RegisterCommand("dot", std::make_shared<DotCommand>());
			command_factory->RegisterCommand("norm", std::make_shared<NormCommand>());
			command_factory->RegisterCommand("normal", std::make_shared<NormalizationCommand>());
			command_factory->RegisterCommand("cross", std::make_shared<CrossProductCommand>());
			command_factory->RegisterCommand("com", std::make_shared<ComponentCommand>());
			command_factory->RegisterCommand("proj", std::make_shared<ProjectionCommand>());
			command_factory->RegisterCommand("area", std::make_shared<AreaCommand>());
			command_factory->RegisterCommand("isparallel", std::make_shared<IsParallelCommand>());
			command_factory->RegisterCommand("isorthogonal", std::make_shared<IsOrthogonalCommand>());
			command_factory->RegisterCommand("angle", std::make_shared<AngleCommand>());
			command_factory->RegisterCommand("pn", std::make_shared<PNCommand>());
			command_factory->RegisterCommand("isli", std::make_shared<IsLICommand>());
			command_factory->RegisterCommand("ob", std::make_shared<ObCommand>());
			// matrix
		/*	command_factory->RegisterCommand("printm", std::make_shared<PrintmCommand>());
			command_factory->RegisterCommand("rank", std::make_shared<RankCommand>());
			command_factory->RegisterCommand("trans", std::make_shared<TransposeCommand>());
			command_factory->RegisterCommand("solve", std::make_shared<SolveMCommand>());
			command_factory->RegisterCommand("det", std::make_shared<DeterminantsCommand>());
			command_factory->RegisterCommand("inverse", std::make_shared<InverseCommand>());
			command_factory->RegisterCommand("adj", std::make_shared<AdjCommand>());
			command_factory->RegisterCommand("pm", std::make_shared<PmCommand>());
			command_factory->RegisterCommand("eigen", std::make_shared<EigenCommand>());
			command_factory->RegisterCommand("rref", std::make_shared<RrefCommand>());
			command_factory->RegisterCommand("leastsquare", std::make_shared<LeastSquareCommand>());*/
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
		DataManager* data_manager;
		String^ userInput;
		int lastInputLength;
		CommandFactory* command_factory;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;












	private: System::Windows::Forms::ToolStripMenuItem^ FileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LoadVectorToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::Button^ runBtn;











	private: System::Windows::Forms::Label^ InputLabel;
	private: System::Windows::Forms::TextBox^ Input;


	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::DataGridView^ dataTable;


	private: System::Windows::Forms::ToolStripMenuItem^ ClearDataBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ ClearOutputBtn;
	private: System::Windows::Forms::TextBox^ outputTextBox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Variable;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Value;
	private: System::Windows::Forms::Button^ deleteBtn;




































		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		   /// �o�Ӥ�k�����e�C
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ClearDataBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ClearOutputBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			   this->runBtn = (gcnew System::Windows::Forms::Button());
			   this->InputLabel = (gcnew System::Windows::Forms::Label());
			   this->Input = (gcnew System::Windows::Forms::TextBox());
			   this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			   this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			   this->deleteBtn = (gcnew System::Windows::Forms::Button());
			   this->dataTable = (gcnew System::Windows::Forms::DataGridView());
			   this->Variable = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
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
			   this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->LoadVectorToolStripMenuItem,
					   this->ClearDataBtn, this->ClearOutputBtn
			   });
			   this->FileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			   this->FileToolStripMenuItem->Size = System::Drawing::Size(102, 32);
			   this->FileToolStripMenuItem->Text = L"Function";
			   this->FileToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::FileToolStripMenuItem_Click);
			   // 
			   // LoadVectorToolStripMenuItem
			   // 
			   this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			   this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(210, 32);
			   this->LoadVectorToolStripMenuItem->Text = L"Load Data";
			   this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			   // 
			   // ClearDataBtn
			   // 
			   this->ClearDataBtn->Name = L"ClearDataBtn";
			   this->ClearDataBtn->Size = System::Drawing::Size(210, 32);
			   this->ClearDataBtn->Text = L"Clear Data";
			   this->ClearDataBtn->Click += gcnew System::EventHandler(this, &WindowsForm::ClearDataBtn_Click);
			   // 
			   // ClearOutputBtn
			   // 
			   this->ClearOutputBtn->Name = L"ClearOutputBtn";
			   this->ClearOutputBtn->Size = System::Drawing::Size(210, 32);
			   this->ClearOutputBtn->Text = L"Clear Output";
			   this->ClearOutputBtn->Click += gcnew System::EventHandler(this, &WindowsForm::ClearOutputBtn_Click_1);
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
			   this->runBtn->AutoEllipsis = true;
			   this->runBtn->BackColor = System::Drawing::SystemColors::Window;
			   this->runBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->runBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->runBtn->Location = System::Drawing::Point(958, 17);
			   this->runBtn->Margin = System::Windows::Forms::Padding(27, 4, 4, 4);
			   this->runBtn->Name = L"runBtn";
			   this->runBtn->Size = System::Drawing::Size(146, 48);
			   this->runBtn->TabIndex = 9;
			   this->runBtn->Text = L"Execute";
			   this->runBtn->UseVisualStyleBackColor = false;
			   this->runBtn->Click += gcnew System::EventHandler(this, &WindowsForm::runBtn_Click);
			   // 
			   // InputLabel
			   // 
			   this->InputLabel->AutoSize = true;
			   this->InputLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->InputLabel->Location = System::Drawing::Point(8, 5);
			   this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->InputLabel->Name = L"InputLabel";
			   this->InputLabel->Size = System::Drawing::Size(124, 31);
			   this->InputLabel->TabIndex = 0;
			   this->InputLabel->Text = L"Command";
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
			   this->splitContainer1->Panel1->Controls->Add(this->outputTextBox);
			   this->splitContainer1->Panel1->Controls->Add(this->label2);
			   // 
			   // splitContainer1.Panel2
			   // 
			   this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			   this->splitContainer1->Size = System::Drawing::Size(1125, 538);
			   this->splitContainer1->SplitterDistance = 375;
			   this->splitContainer1->TabIndex = 14;
			   // 
			   // outputTextBox
			   // 
			   this->outputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->outputTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->outputTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->outputTextBox->Location = System::Drawing::Point(0, 49);
			   this->outputTextBox->Multiline = true;
			   this->outputTextBox->Name = L"outputTextBox";
			   this->outputTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->outputTextBox->Size = System::Drawing::Size(373, 487);
			   this->outputTextBox->TabIndex = 10;
			   // 
			   // label2
			   // 
			   this->label2->Dock = System::Windows::Forms::DockStyle::Top;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(0, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(373, 49);
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
			   this->splitContainer2->Panel1->Controls->Add(this->deleteBtn);
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
			   // deleteBtn
			   // 
			   this->deleteBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->deleteBtn->Location = System::Drawing::Point(619, 5);
			   this->deleteBtn->Name = L"deleteBtn";
			   this->deleteBtn->Size = System::Drawing::Size(117, 39);
			   this->deleteBtn->TabIndex = 10;
			   this->deleteBtn->Text = L"Delete";
			   this->deleteBtn->UseVisualStyleBackColor = true;
			   this->deleteBtn->Click += gcnew System::EventHandler(this, &WindowsForm::deleteBtn_Click);
			   // 
			   // dataTable
			   // 
			   this->dataTable->AllowUserToAddRows = false;
			   this->dataTable->AllowUserToOrderColumns = true;
			   dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			   this->dataTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle11;
			   this->dataTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->dataTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			   dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle12->BackColor = System::Drawing::SystemColors::Control;
			   dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::WindowText;
			   dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->dataTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle12;
			   this->dataTable->ColumnHeadersHeight = 40;
			   this->dataTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Variable, this->Value });
			   this->dataTable->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->dataTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			   this->dataTable->Location = System::Drawing::Point(0, 48);
			   this->dataTable->Name = L"dataTable";
			   dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			   dataGridViewCellStyle15->BackColor = System::Drawing::SystemColors::Control;
			   dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   dataGridViewCellStyle15->ForeColor = System::Drawing::SystemColors::WindowText;
			   dataGridViewCellStyle15->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle15->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle15->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->dataTable->RowHeadersDefaultCellStyle = dataGridViewCellStyle15;
			   this->dataTable->RowHeadersWidth = 51;
			   this->dataTable->RowTemplate->Height = 27;
			   this->dataTable->Size = System::Drawing::Size(744, 181);
			   this->dataTable->TabIndex = 9;
			   this->dataTable->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &WindowsForm::dataTable_CellContentClick_1);
			   // 
			   // Variable
			   // 
			   this->Variable->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			   dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Variable->DefaultCellStyle = dataGridViewCellStyle13;
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
			   dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Value->DefaultCellStyle = dataGridViewCellStyle14;
			   this->Value->HeaderText = L"Value";
			   this->Value->MinimumWidth = 6;
			   this->Value->Name = L"Value";
			   this->Value->ReadOnly = true;
			   // 
			   // label1
			   // 
			   this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(0, 0);
			   this->label1->Name = L"label1";
			   this->label1->Padding = System::Windows::Forms::Padding(0, 4, 0, 4);
			   this->label1->Size = System::Drawing::Size(744, 48);
			   this->label1->TabIndex = 8;
			   this->label1->Text = L"Data";
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
			   this->splitContainer3->Panel2->Controls->Add(this->runBtn);
			   this->splitContainer3->Size = System::Drawing::Size(1133, 630);
			   this->splitContainer3->SplitterDistance = 546;
			   this->splitContainer3->TabIndex = 15;
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
			   this->Text = L"Linear Calculator";
			   this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			   this->menuStrip2->ResumeLayout(false);
			   this->menuStrip2->PerformLayout();
			   this->splitContainer1->Panel1->ResumeLayout(false);
			   this->splitContainer1->Panel1->PerformLayout();
			   this->splitContainer1->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			   this->splitContainer1->ResumeLayout(false);
			   this->splitContainer2->Panel1->ResumeLayout(false);
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
		data_manager->SetFileName(tempFileName);
		//�qŪ��Ū���V�q���
		if (data_manager->LoadData())
		{
			//�NVectorList�����إ����M��
			this->dataTable->Rows->Clear();
			//���o�Ҧ��V�q���
			auto vectors = data_manager->GetVectors();
			auto matrices = data_manager->GetMatrices();

			if (vectors.size()) {
				for (const auto& v : vectors)
				{
					Vector vec = v.second;
					this->dataTable->Rows->Add(
						gcnew array<String^>{
						gcnew String(v.first.c_str()),
							vec.GetResult()}
					);
				}
			}
			if (matrices.size()) {
				for (const auto& m : matrices)
				{
					Matrix matrix = m.second;
					this->dataTable->Rows->Add(
						gcnew array<String^>{
						gcnew String(m.first.c_str()),
							matrix.GetResult()}
					);
				}
			}
			outputTextBox->Text += "[INFO] File loaded successfully" + NL;
		}
	}
	private: System::Void FileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private:std::string trim(std::string& s) {
		if (s.empty())
			return s;
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		return s;
	}
	private:std::vector<std::string> SplitString(const std::string& input, char delimiter) {
		std::vector<std::string> result;
		std::stringstream ss(input);
		std::string item;

		while (std::getline(ss, item, delimiter)) {
			result.push_back(item);
		}

		return result;
	}
	private:void ReadInput(std::string& command, std::vector<std::string>& params) {

		std::string input_str = "";
		MarshalString(userInput, input_str);
		trim(input_str);
		std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::tolower);

		std::vector<std::string> commands;
		//commands.push_back(input_str.substr(0, input_str.find_first_of(" ")));
		command = input_str.substr(0, input_str.find_first_of(" "));

		std::string param_str = input_str.substr(input_str.find_first_of(" ") + 1);
		std::vector<std::string> splits = SplitString(param_str, ',');

		if (splits.size() >= 2) {
			splits[0].erase(0, 1);
			splits.back().pop_back();
		}
		params.clear();
		params.insert(params.end(), splits.begin(), splits.end());
	}

	private: void ProcessInput() {

		std::vector<std::string> params;
		std::string command = "";

		//ReadInput(command, params);

		//�r�����A�Y���O��"print"�����p
		// Output->Text
		System::String^ output_temp = "[USER] " + userInput + NL;

		try {
			auto v_lookup = data_manager->GetVectors();
			auto m_lookup = data_manager->GetMatrices();

			Calculator calculator(*command_factory);

			std::string input_str = "";
			MarshalString(userInput, input_str);
			std::vector<Token> tokens = calculator.Lex(input_str);
			std::vector<Token> postfix_tokens = calculator.IntoPost(tokens);

			System::String^ operate_result = "";
			auto result = calculator.calculate<Vector>(postfix_tokens, v_lookup, operate_result);

			int length = operate_result->Length;
			if (length > 0) {
				output_temp += operate_result;
			}
			else {
				output_temp += result.GetResult();
			}
			output_temp += NL;
			int x = 10;
		}
		catch (std::invalid_argument& e) {
			// https://learn.microsoft.com/zh-tw/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170
			output_temp += gcnew String(e.what());
		}
		outputTextBox->Text += output_temp;
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
	}
	private: System::Void clearOutputBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		outputTextBox->Text = "";
	}
	private: System::Void Input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ClearDataBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		dataTable->Rows->Clear();
		data_manager->clear();
	}
	private: System::Void ClearOutputBtn_Click_1(System::Object^ sender, System::EventArgs^ e) {
		outputTextBox->Text = "";
	}
	private: System::Void dataTable_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		auto x = e->RowIndex;
		auto row = dataTable->Rows[x];

		//outputTextBox->Text += x;
	}
	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {


		//dataTable->get

	}
	};
}




