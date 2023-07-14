#pragma once
#include"DataManager.h"
#define nL System::Environment::NewLine
//#define DEBUG
Vector calV(std::string str, std::vector<Vector> vectors);
Matrix calM(std::string str, std::vector<Matrix> matrices);
Vector getV(std::string str, std::vector<Vector> vectors);
Matrix getM(std::string str, std::vector<Matrix> matrices);
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


		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		   /// 這個方法的內容。
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			   this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->VectorLabel = (gcnew System::Windows::Forms::Label());
			   this->VectorList = (gcnew System::Windows::Forms::ListBox());
			   this->InputLabel = (gcnew System::Windows::Forms::Label());
			   this->Input = (gcnew System::Windows::Forms::TextBox());
			   this->clearBtn = (gcnew System::Windows::Forms::Button());
			   this->runBtn = (gcnew System::Windows::Forms::Button());
			   this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->OutputLabel = (gcnew System::Windows::Forms::Label());
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
			   this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			   this->menuStrip2->Location = System::Drawing::Point(0, 0);
			   this->menuStrip2->Name = L"menuStrip2";
			   this->menuStrip2->Size = System::Drawing::Size(1091, 28);
			   this->menuStrip2->TabIndex = 1;
			   this->menuStrip2->Text = L"menuStrip2";
			   // 
			   // FileToolStripMenuItem
			   // 
			   this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->LoadVectorToolStripMenuItem });
			   this->FileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			   this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			   this->FileToolStripMenuItem->Size = System::Drawing::Size(58, 24);
			   this->FileToolStripMenuItem->Text = L"Load";
			   this->FileToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::FileToolStripMenuItem_Click);
			   // 
			   // LoadVectorToolStripMenuItem
			   // 
			   this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			   this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(155, 24);
			   this->LoadVectorToolStripMenuItem->Text = L"Load Data";
			   this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 2;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   38.87489F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   61.12511F)));
			   this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 1;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 491)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1093, 590);
			   this->tableLayoutPanel1->TabIndex = 2;
			   // 
			   // flowLayoutPanel1
			   // 
			   this->flowLayoutPanel1->BackColor = System::Drawing::Color::Gainsboro;
			   this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			   this->flowLayoutPanel1->Controls->Add(this->VectorList);
			   this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			   this->flowLayoutPanel1->Controls->Add(this->Input);
			   this->flowLayoutPanel1->Controls->Add(this->clearBtn);
			   this->flowLayoutPanel1->Controls->Add(this->runBtn);
			   this->flowLayoutPanel1->Location = System::Drawing::Point(427, 3);
			   this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			   this->flowLayoutPanel1->Size = System::Drawing::Size(652, 584);
			   this->flowLayoutPanel1->TabIndex = 0;
			   // 
			   // VectorLabel
			   // 
			   this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->VectorLabel->AutoSize = true;
			   this->VectorLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->VectorLabel->Location = System::Drawing::Point(3, 0);
			   this->VectorLabel->Name = L"VectorLabel";
			   this->VectorLabel->Size = System::Drawing::Size(90, 31);
			   this->VectorLabel->TabIndex = 2;
			   this->VectorLabel->Text = L"Vector";
			   // 
			   // VectorList
			   // 
			   this->VectorList->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->VectorList->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->VectorList->FormattingEnabled = true;
			   this->VectorList->ItemHeight = 19;
			   this->VectorList->Location = System::Drawing::Point(5, 34);
			   this->VectorList->Margin = System::Windows::Forms::Padding(5, 3, 5, 3);
			   this->VectorList->Name = L"VectorList";
			   this->VectorList->Size = System::Drawing::Size(642, 251);
			   this->VectorList->TabIndex = 7;
			   // 
			   // InputLabel
			   // 
			   this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->InputLabel->AutoSize = true;
			   this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->InputLabel->Location = System::Drawing::Point(3, 288);
			   this->InputLabel->Name = L"InputLabel";
			   this->InputLabel->Size = System::Drawing::Size(76, 31);
			   this->InputLabel->TabIndex = 0;
			   this->InputLabel->Text = L"Input";
			   this->InputLabel->Click += gcnew System::EventHandler(this, &WindowsForm::InputLabel_Click);
			   // 
			   // Input
			   // 
			   this->Input->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Input->BackColor = System::Drawing::SystemColors::Menu;
			   this->Input->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->Input->Location = System::Drawing::Point(3, 322);
			   this->Input->Multiline = true;
			   this->Input->Name = L"Input";
			   this->Input->Size = System::Drawing::Size(648, 200);
			   this->Input->TabIndex = 8;
			   this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			   // 
			   // clearBtn
			   // 
			   this->clearBtn->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->clearBtn->Location = System::Drawing::Point(20, 528);
			   this->clearBtn->Margin = System::Windows::Forms::Padding(20, 3, 3, 3);
			   this->clearBtn->Name = L"clearBtn";
			   this->clearBtn->Size = System::Drawing::Size(128, 44);
			   this->clearBtn->TabIndex = 6;
			   this->clearBtn->Text = L"Clear";
			   this->clearBtn->UseVisualStyleBackColor = true;
			   this->clearBtn->Click += gcnew System::EventHandler(this, &WindowsForm::clearBtn_Click);
			   // 
			   // runBtn
			   // 
			   this->runBtn->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->runBtn->Location = System::Drawing::Point(171, 528);
			   this->runBtn->Margin = System::Windows::Forms::Padding(20, 3, 3, 3);
			   this->runBtn->Name = L"runBtn";
			   this->runBtn->Size = System::Drawing::Size(128, 44);
			   this->runBtn->TabIndex = 9;
			   this->runBtn->Text = L"Run";
			   this->runBtn->UseVisualStyleBackColor = true;
			   this->runBtn->Click += gcnew System::EventHandler(this, &WindowsForm::runBtn_Click);
			   // 
			   // flowLayoutPanel2
			   // 
			   this->flowLayoutPanel2->BackColor = System::Drawing::Color::Gainsboro;
			   this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			   this->flowLayoutPanel2->Controls->Add(this->Output);
			   this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			   this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			   this->flowLayoutPanel2->Size = System::Drawing::Size(418, 577);
			   this->flowLayoutPanel2->TabIndex = 1;
			   // 
			   // OutputLabel
			   // 
			   this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->OutputLabel->AutoSize = true;
			   this->OutputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OutputLabel->Location = System::Drawing::Point(3, 0);
			   this->OutputLabel->Name = L"OutputLabel";
			   this->OutputLabel->Size = System::Drawing::Size(96, 30);
			   this->OutputLabel->TabIndex = 0;
			   this->OutputLabel->Text = L"Output";
			   // 
			   // Output
			   // 
			   this->Output->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Output->Location = System::Drawing::Point(3, 33);
			   this->Output->Multiline = true;
			   this->Output->Name = L"Output";
			   this->Output->ReadOnly = true;
			   this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			   this->Output->Size = System::Drawing::Size(415, 544);
			   this->Output->TabIndex = 1;
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			   // 
			   // WindowsForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1091, 616);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->Controls->Add(this->menuStrip2);
			   this->Name = L"WindowsForm";
			   this->Text = L"VectorExample";
			   this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			   this->menuStrip2->ResumeLayout(false);
			   this->menuStrip2->PerformLayout();
			   this->tableLayoutPanel1->ResumeLayout(false);
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
	private: System::Void Input_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
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
			std::vector<Matrix> matrices = dataManager->GetMatrices();
			if (vectors.size()) {
				for (unsigned int i = 0; i < vectors.size(); i++)
				{
					//將檔案名稱存入暫存
					std::string tempString = vectors[i].Name;
					//將輸出格式存入暫存
					tempString += " [";
					//將輸出資料存入暫存
					for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
					{
						std::string scalarString = std::to_string(vectors[i].Data[j]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (j != vectors[i].Data.size() - 1)
							tempString += ", ";
					}
					//將輸出格式存入暫存
					tempString += "]";
					//將項目加入VectorList中
					VectorList->Items->Add(gcnew String(tempString.c_str()));
				}
				Output->Text += "[INFO] File loaded successfully" + nL;
			}
			else if (matrices.size()) {
				for (auto i : matrices)
				{
					std::string tempString = i.Name;
					tempString += " [";
					for (int row = 0; row < i.row; row++) {
						for (int col = 0; col < i.col; col++) {
							std::string scalarString = std::to_string(i.Data[row][col]);
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
	private: System::Void InputLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void FileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void clearBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		VectorList->Items->Clear();
		dataManager->clear();
		Input->Text = "";
	}
	private: System::Void runBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		std::vector<Vector> vectors = dataManager->GetVectors();
		std::vector<Matrix> matrices = dataManager->GetMatrices();

		userInput = Input->Text;

		if (userInput->Length - 1 >= 0)
		{
			//將使用者輸入字串(在userInput中)，依空白作切割
			array<String^>^ inp = userInput->Split(' ', ',');
			std::vector<std::string> userCommand(inp->Length), str;

			for (int s = 0; s < inp->Length; s++) {
				MarshalString(inp[s], userCommand[s]);
			}
			if (inp->Length > 2) {
				userCommand[1].erase(0, 1);
				userCommand[userCommand.size() - 1].pop_back();
			}
			Vector v, v1, vResult;
			Matrix m, m1, mResult;
			//字串比較，若指令為"print"的情況
			Output->Text += userInput + nL;
			try {
				if (userCommand[0] == "printV" || userCommand[0] == "calV") {
					vResult = calV(userCommand[1], vectors);
					Output->Text += vResult.getResult();
				}
				else if (userCommand[0] == "Norm") {
					vResult = calV(userCommand[1], vectors);
					double db = norm(vResult);
					Output->Text += db + nL;
				}
				else if (userCommand[0] == "Normal") {
					vResult = calV(userCommand[1], vectors);
					vResult = normalization(vResult);
					Output->Text += vResult.getResult();
				}
				else if (userCommand[0] == "Cross" || userCommand[0] == "Com" || userCommand[0] == "Proj") {
					v = calV(userCommand[1], vectors);
					v1 = calV(userCommand[2], vectors);
					if (userCommand[0] == "Cross") {
						vResult = crossProduct(v, v1);
					}
					else if (userCommand[0] == "Com") {
						vResult = component(v, v1);
					}
					else {
						vResult = projection(v, v1);
					}
					Output->Text += vResult.getResult();
				}
				else if (userCommand[0] == "Area") {
					v = calV(userCommand[1], vectors);
					v1 = calV(userCommand[2], vectors);
					double db = area(v, v1);
					Output->Text += db + nL;
				}
				else if (userCommand[0] == "isParallel" || userCommand[0] == "isOrthogonal") {
					v = calV(userCommand[1], vectors);
					v1 = calV(userCommand[2], vectors);
					if (userCommand[0] == "isParallel") {
						Output->Text += (isParallel(v, v1) ? "Yes" : "No") + nL;
					}
					else {
						Output->Text += (isOrthogonal(v, v1) ? "Yes" : "No") + nL;
					}
				}
				else if (userCommand[0] == "angle") {
					v = calV(userCommand[1], vectors);
					v1 = calV(userCommand[2], vectors);
					double db = angle(v, v1);
					Output->Text += "theta = " + db + nL;
				}
				else if (userCommand[0] == "pN" || userCommand[0] == "IsLI") {
					v = calV(userCommand[1], vectors);
					v1 = calV(userCommand[2], vectors);
					if (userCommand[0] == "pN") {
						vResult = pN(v, v1);
						Output->Text += vResult.getResult();
					}
					else {
						Output->Text += (isLI(v, v1) ? "Yes" : "No") + nL;
					}
				}
				else if (userCommand[0] == "Ob") {
					std::vector<Vector> varr;
					std::vector<Vector> op;
					for (int i = 1; i < userCommand.size(); i++) {
						varr.push_back(calV(userCommand[i], vectors));
					}
					op = Ob(varr);
					for (auto i : op) {
						Output->Text += i.getResult();
					}
				}
				else if (userCommand[0] == "calM" || userCommand[0] == "printM") {
					mResult = calM(userCommand[1], matrices);
					Output->Text += mResult.getResult();
				}
				else if (userCommand[0] == "Rank") {
					mResult = calM(userCommand[1], matrices);
					int rk = rank(mResult);
					Output->Text += rk + nL;
				}
				else if (userCommand[0] == "trans") {
					mResult = calM(userCommand[1], matrices);
					mResult = transpose(mResult);
					Output->Text += mResult.getResult();
				}
				else if (userCommand[0] == "Sol") {
					m = calM(userCommand[1], matrices);
					m1 = calM(userCommand[2], matrices);
					mResult = m / m1;
					Output->Text += mResult.getResult();
				}
				else if (userCommand[0] == "det") {
					mResult = calM(userCommand[1], matrices);
					double db = determinants(mResult);
					Output->Text += db + nL;
				}
				else if (userCommand[0] == "Inverse") {
					mResult = calM(userCommand[1], matrices);
					mResult = inverse(mResult);
					Output->Text += mResult.getResult();
				}
				else if (userCommand[0] == "Adj") {
					mResult = calM(userCommand[1], matrices);
					mResult = Adj(mResult);
					Output->Text += mResult.getResult();
				}
				else if (userCommand[0] == "PM") {
					mResult = calM(userCommand[1], matrices);
					double db = 0;
					mResult = pm(mResult, db);
					Output->Text += "v=" + nL + mResult.getResult() + nL;
					Output->Text += "d=" + nL + db + nL;
				}
				else if (userCommand[0] == "eigen") {
					std::vector<double> eigenValues;
					mResult = calM(userCommand[1], matrices);
					mResult = eigen(mResult, eigenValues);
					Output->Text += "v =" + nL + mResult.getResult() + nL + "d =" + nL;
					for (int i = 0; i < eigenValues.size(); i++) {
						for (int j = 0; j < eigenValues.size(); j++) {
							Output->Text += (i == j ? eigenValues[i] : 0);
							Output->Text += "   ";
						}
						Output->Text += nL;
					}
				}
				else if (userCommand[0] == "rref") {
					mResult = calM(userCommand[1], matrices);
					std::vector<Matrix> result = rref(mResult);
					Output->Text += result[1].getResult() + nL;
					Output->Text += result[0].getResult() + nL;
				}
				else if (userCommand[0] == "LeastSquare") {
					m = calM(userCommand[1], matrices);
					m1 = calM(userCommand[2], matrices);
					mResult = LeastSquare(m, m1);
					Output->Text += mResult.getResult();
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
					Output->Text += "[ERROR] No matrices list." + nL;
					break;
				default:
					break;
				}
			}


		}
		else
		{
			//將使用者輸入字串(在Text box中)，依'\n'作切割
			array<String^>^ userCommand = Input->Text->Split('\n');
			//並將最後一行，作為目前使用者輸入指令
			userInput = userCommand[userCommand->Length - 1];
		}

	}
	};
}
