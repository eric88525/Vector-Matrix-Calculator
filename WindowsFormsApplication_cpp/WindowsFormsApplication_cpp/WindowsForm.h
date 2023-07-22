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
	/// WindowsForm 的摘要
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
		/// 清除任何使用中的資源。
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^ LoadVectorToolStripMenuItem;



	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Label^ OutputLabel;
	private: System::Windows::Forms::TextBox^ Output;

	private: System::Windows::Forms::Label^ InputLabel;

	private: System::Windows::Forms::Label^ VectorLabel;




	protected:
	protected:

	private:
		/// <summary>
		DataManager* dataManager;
		String^ userInput;
		int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::Button^ clearBtn;
	private: System::Windows::Forms::ListBox^ VectorList;
	private: System::Windows::Forms::TextBox^ Input;
	private: System::Windows::Forms::Button^ runBtn;
	private: System::Windows::Forms::Button^ clearOutputBtn;


		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		   /// 這個方法的內容。
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WindowsForm::typeid));
			   this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			   this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->VectorLabel = (gcnew System::Windows::Forms::Label());
			   this->clearBtn = (gcnew System::Windows::Forms::Button());
			   this->VectorList = (gcnew System::Windows::Forms::ListBox());
			   this->InputLabel = (gcnew System::Windows::Forms::Label());
			   this->Input = (gcnew System::Windows::Forms::TextBox());
			   this->runBtn = (gcnew System::Windows::Forms::Button());
			   this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->OutputLabel = (gcnew System::Windows::Forms::Label());
			   this->clearOutputBtn = (gcnew System::Windows::Forms::Button());
			   this->Output = (gcnew System::Windows::Forms::TextBox());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->menuStrip2->SuspendLayout();
			   this->tableLayoutPanel1->SuspendLayout();
			   this->flowLayoutPanel1->SuspendLayout();
			   this->flowLayoutPanel2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip2
			   // 
			   this->menuStrip2->BackColor = System::Drawing::SystemColors::ButtonFace;
			   this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			   this->menuStrip2->Location = System::Drawing::Point(0, 0);
			   this->menuStrip2->Name = L"menuStrip2";
			   this->menuStrip2->Size = System::Drawing::Size(1455, 33);
			   this->menuStrip2->TabIndex = 1;
			   this->menuStrip2->Text = L"menuStrip2";
			   // 
			   // FileToolStripMenuItem
			   // 
			   this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->LoadVectorToolStripMenuItem });
			   this->FileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			   this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			   this->FileToolStripMenuItem->Size = System::Drawing::Size(78, 29);
			   this->FileToolStripMenuItem->Text = L"Open";
			   this->FileToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::FileToolStripMenuItem_Click);
			   // 
			   // LoadVectorToolStripMenuItem
			   // 
			   this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			   this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(194, 30);
			   this->LoadVectorToolStripMenuItem->Text = L"Load Data";
			   this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->AutoSize = true;
			   this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			   this->tableLayoutPanel1->ColumnCount = 2;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   38.87489F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   61.12511F)));
			   this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 30);
			   this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 1;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 614)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1460, 719);
			   this->tableLayoutPanel1->TabIndex = 2;
			   // 
			   // flowLayoutPanel1
			   // 
			   this->flowLayoutPanel1->AutoSize = true;
			   this->flowLayoutPanel1->BackColor = System::Drawing::Color::LightSteelBlue;
			   this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			   this->flowLayoutPanel1->Controls->Add(this->clearBtn);
			   this->flowLayoutPanel1->Controls->Add(this->VectorList);
			   this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			   this->flowLayoutPanel1->Controls->Add(this->Input);
			   this->flowLayoutPanel1->Controls->Add(this->runBtn);
			   this->flowLayoutPanel1->Location = System::Drawing::Point(571, 4);
			   this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			   this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			   this->flowLayoutPanel1->Size = System::Drawing::Size(855, 711);
			   this->flowLayoutPanel1->TabIndex = 0;
			   // 
			   // VectorLabel
			   // 
			   this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->VectorLabel->AutoSize = true;
			   this->VectorLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->VectorLabel->Location = System::Drawing::Point(4, 15);
			   this->VectorLabel->Margin = System::Windows::Forms::Padding(4, 0, 2, 0);
			   this->VectorLabel->Name = L"VectorLabel";
			   this->VectorLabel->Size = System::Drawing::Size(113, 38);
			   this->VectorLabel->TabIndex = 2;
			   this->VectorLabel->Text = L"Vector";
			   // 
			   // clearBtn
			   // 
			   this->clearBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearBtn.BackgroundImage")));
			   this->clearBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->clearBtn->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->clearBtn->Location = System::Drawing::Point(146, 4);
			   this->clearBtn->Margin = System::Windows::Forms::Padding(27, 4, 4, 4);
			   this->clearBtn->Name = L"clearBtn";
			   this->clearBtn->Size = System::Drawing::Size(60, 60);
			   this->clearBtn->TabIndex = 6;
			   this->clearBtn->UseVisualStyleBackColor = true;
			   this->clearBtn->Click += gcnew System::EventHandler(this, &WindowsForm::clearBtn_Click);
			   // 
			   // VectorList
			   // 
			   this->VectorList->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->VectorList->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->VectorList->FormattingEnabled = true;
			   this->VectorList->ItemHeight = 24;
			   this->VectorList->Location = System::Drawing::Point(10, 72);
			   this->VectorList->Margin = System::Windows::Forms::Padding(10, 4, 10, 4);
			   this->VectorList->Name = L"VectorList";
			   this->VectorList->Size = System::Drawing::Size(835, 340);
			   this->VectorList->TabIndex = 7;
			   // 
			   // InputLabel
			   // 
			   this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->InputLabel->AutoSize = true;
			   this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->InputLabel->Location = System::Drawing::Point(4, 416);
			   this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->InputLabel->Name = L"InputLabel";
			   this->InputLabel->Size = System::Drawing::Size(95, 38);
			   this->InputLabel->TabIndex = 0;
			   this->InputLabel->Text = L"Input";
			   // 
			   // Input
			   // 
			   this->Input->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Input->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(26) {
				   L"printv", L"calv", L"norm", L"normal",
					   L"cross", L"com", L"proj", L"area", L"isparallel", L"isorthogonal", L"angle", L"pn", L"isli", L"ob", L"cal<Matrix>", L"printm", L"rank",
					   L"trans", L"sol", L"det", L"inverse", L"adj", L"pm", L"eigen", L"rref", L"leastsquare"
			   });
			   this->Input->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			   this->Input->BackColor = System::Drawing::SystemColors::Window;
			   this->Input->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->Input->Location = System::Drawing::Point(10, 458);
			   this->Input->Margin = System::Windows::Forms::Padding(10, 4, 10, 4);
			   this->Input->Multiline = true;
			   this->Input->Name = L"Input";
			   this->Input->Size = System::Drawing::Size(835, 188);
			   this->Input->TabIndex = 8;
			   this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			   // 
			   // runBtn
			   // 
			   this->runBtn->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->runBtn->Location = System::Drawing::Point(27, 654);
			   this->runBtn->Margin = System::Windows::Forms::Padding(27, 4, 4, 4);
			   this->runBtn->Name = L"runBtn";
			   this->runBtn->Size = System::Drawing::Size(171, 53);
			   this->runBtn->TabIndex = 9;
			   this->runBtn->Text = L"Run";
			   this->runBtn->UseVisualStyleBackColor = true;
			   this->runBtn->Click += gcnew System::EventHandler(this, &WindowsForm::runBtn_Click);
			   // 
			   // flowLayoutPanel2
			   // 
			   this->flowLayoutPanel2->BackColor = System::Drawing::Color::LightSteelBlue;
			   this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			   this->flowLayoutPanel2->Controls->Add(this->clearOutputBtn);
			   this->flowLayoutPanel2->Controls->Add(this->Output);
			   this->flowLayoutPanel2->Location = System::Drawing::Point(4, 4);
			   this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			   this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			   this->flowLayoutPanel2->Size = System::Drawing::Size(557, 710);
			   this->flowLayoutPanel2->TabIndex = 1;
			   // 
			   // OutputLabel
			   // 
			   this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->OutputLabel->AutoSize = true;
			   this->OutputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OutputLabel->Location = System::Drawing::Point(4, 15);
			   this->OutputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->OutputLabel->Name = L"OutputLabel";
			   this->OutputLabel->Size = System::Drawing::Size(118, 38);
			   this->OutputLabel->TabIndex = 0;
			   this->OutputLabel->Text = L"Output";
			   // 
			   // clearOutputBtn
			   // 
			   this->clearOutputBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearOutputBtn.BackgroundImage")));
			   this->clearOutputBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->clearOutputBtn->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->clearOutputBtn->Location = System::Drawing::Point(153, 4);
			   this->clearOutputBtn->Margin = System::Windows::Forms::Padding(27, 4, 4, 4);
			   this->clearOutputBtn->Name = L"clearOutputBtn";
			   this->clearOutputBtn->Size = System::Drawing::Size(60, 60);
			   this->clearOutputBtn->TabIndex = 10;
			   this->clearOutputBtn->UseVisualStyleBackColor = true;
			   this->clearOutputBtn->Click += gcnew System::EventHandler(this, &WindowsForm::clearOutputBtn_Click);
			   // 
			   // Output
			   // 
			   this->Output->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Output->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Output->Location = System::Drawing::Point(4, 72);
			   this->Output->Margin = System::Windows::Forms::Padding(4);
			   this->Output->Multiline = true;
			   this->Output->Name = L"Output";
			   this->Output->ReadOnly = true;
			   this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			   this->Output->Size = System::Drawing::Size(543, 644);
			   this->Output->TabIndex = 1;
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			   // 
			   // WindowsForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1455, 748);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->Controls->Add(this->menuStrip2);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"WindowsForm";
			   this->Text = L"VectorExample";
			   this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			   this->menuStrip2->ResumeLayout(false);
			   this->menuStrip2->PerformLayout();
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->flowLayoutPanel1->ResumeLayout(false);
			   this->flowLayoutPanel1->PerformLayout();
			   this->flowLayoutPanel2->ResumeLayout(false);
			   this->flowLayoutPanel2->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void WindowsForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//開啟Dialog
		openFileDialog1->ShowDialog();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		//在Dialog按下OK便會進入此函式
		//字串轉制string^ to string
		std::string tempFileName;
		MarshalString(openFileDialog1->FileName, tempFileName);
		//將檔案路徑名稱傳入dataManager
		dataManager->SetFileName(tempFileName);
		//從讀取讀取向量資料
		if (dataManager->LoadData())
		{
			//將VectorList中項目先做清除
			VectorList->Items->Clear();
			//取得所有向量資料
			std::vector<Vector> vectors = dataManager->GetVectors();
			std::vector<Matrix> m_lookup = dataManager->GetMatrices();
			if (vectors.size()) {
				for (unsigned int i = 0; i < vectors.size(); i++)
				{
					//將檔案名稱存入暫存
					std::string tempString = vectors[i].name;
					//將輸出格式存入暫存
					tempString += " [";
					//將輸出資料存入暫存
					for (unsigned int j = 0; j < vectors[i].data.size(); j++)
					{
						std::string scalarString = std::to_string(vectors[i].data[j]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (j != vectors[i].data.size() - 1)
							tempString += ", ";
					}
					//將輸出格式存入暫存
					tempString += "]";
					//將項目加入VectorList中
					VectorList->Items->Add(gcnew String(tempString.c_str()));
				}
				Output->Text += "[INFO] File loaded successfully" + nL;
			}
			else if (m_lookup.size()) {
				for (auto i : m_lookup)
				{
					std::string tempString = i.name;
					tempString += " [";
					for (int row = 0; row < i.row; row++) {
						for (int col = 0; col < i.col; col++) {
							std::string scalarString = std::to_string(i.data[row][col]);
							tempString += scalarString.substr(0, scalarString.size() - 5);
							if (!(row == i.row - 1 && col == i.col - 1))
								tempString += ",";
						}
					}
					tempString += "]";
					VectorList->Items->Add(gcnew String(tempString.c_str()));
				}
				Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
			}
		}
	}
	private: System::Void FileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void clearBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		VectorList->Items->Clear();
		dataManager->clear();
		Input->Text = "";
	}
	private: void ProcessInput() {

		//將使用者輸入字串(在userInput中)，依空白作切割
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
		//字串比較，若指令為"print"的情況
		Output->Text += userInput + nL;

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

			if (command == "printv" || command == "cal<Vector>") {
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
			else if (command == "cal<Matrix>" || command == "printm") {
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

		//將使用者輸入字串(在Text box中)，依'\n'作切割
		auto input_lines = Input->Text->Split('\n');

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
	};
}
