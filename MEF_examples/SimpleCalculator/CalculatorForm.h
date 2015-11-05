#pragma once
#include "Interface.h"

namespace SimpleCalculator {

  public ref class CalculatorForm : public System::Windows::Forms::Form
  {
  public:
    CalculatorForm();

  protected:
    ~CalculatorForm();

  private: System::Windows::Forms::TextBox^  tbxLeft;
  private: System::Windows::Forms::ComboBox^  cbxOpr;
  private: System::Windows::Forms::TextBox^  tbxRight;
  private: System::Windows::Forms::Button^  btnExec;
  private: System::Windows::Forms::Label^  lblResult;

  private:
    System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
    /// コード エディターで変更しないでください。
    /// </summary>
    void InitializeComponent(void)
    {
      System::Windows::Forms::Label^  label2;
      System::Windows::Forms::Label^  label3;
      System::Windows::Forms::Label^  label4;
      this->tbxLeft = (gcnew System::Windows::Forms::TextBox());
      this->cbxOpr = (gcnew System::Windows::Forms::ComboBox());
      this->tbxRight = (gcnew System::Windows::Forms::TextBox());
      this->btnExec = (gcnew System::Windows::Forms::Button());
      this->lblResult = (gcnew System::Windows::Forms::Label());
      label2 = (gcnew System::Windows::Forms::Label());
      label3 = (gcnew System::Windows::Forms::Label());
      label4 = (gcnew System::Windows::Forms::Label());
      this->SuspendLayout();
      // 
      // label2
      // 
      label2->AutoSize = true;
      label2->Location = System::Drawing::Point(12, 9);
      label2->Name = L"label2";
      label2->Size = System::Drawing::Size(22, 12);
      label2->TabIndex = 5;
      label2->Text = L"left";
      // 
      // label3
      // 
      label3->AutoSize = true;
      label3->Location = System::Drawing::Point(85, 9);
      label3->Name = L"label3";
      label3->Size = System::Drawing::Size(23, 12);
      label3->TabIndex = 6;
      label3->Text = L"opr.";
      // 
      // label4
      // 
      label4->AutoSize = true;
      label4->Location = System::Drawing::Point(167, 9);
      label4->Name = L"label4";
      label4->Size = System::Drawing::Size(28, 12);
      label4->TabIndex = 7;
      label4->Text = L"right";
      // 
      // tbxLeft
      // 
      this->tbxLeft->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(128)));
      this->tbxLeft->Location = System::Drawing::Point(12, 32);
      this->tbxLeft->Name = L"tbxLeft";
      this->tbxLeft->Size = System::Drawing::Size(69, 31);
      this->tbxLeft->TabIndex = 0;
      // 
      // cbxOpr
      // 
      this->cbxOpr->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
      this->cbxOpr->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(128)));
      this->cbxOpr->FormattingEnabled = true;
      this->cbxOpr->Location = System::Drawing::Point(87, 32);
      this->cbxOpr->Name = L"cbxOpr";
      this->cbxOpr->Size = System::Drawing::Size(76, 32);
      this->cbxOpr->Sorted = true;
      this->cbxOpr->TabIndex = 1;
      // 
      // tbxRight
      // 
      this->tbxRight->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(128)));
      this->tbxRight->Location = System::Drawing::Point(169, 33);
      this->tbxRight->Name = L"tbxRight";
      this->tbxRight->Size = System::Drawing::Size(69, 31);
      this->tbxRight->TabIndex = 2;
      // 
      // btnExec
      // 
      this->btnExec->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(128)));
      this->btnExec->Location = System::Drawing::Point(244, 30);
      this->btnExec->Name = L"btnExec";
      this->btnExec->Size = System::Drawing::Size(29, 33);
      this->btnExec->TabIndex = 3;
      this->btnExec->Text = L"=";
      this->btnExec->UseVisualStyleBackColor = true;
      this->btnExec->Click += gcnew System::EventHandler(this, &CalculatorForm::btnExec_Click);
      // 
      // lblResult
      // 
      this->lblResult->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
      this->lblResult->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(128)));
      this->lblResult->Location = System::Drawing::Point(12, 77);
      this->lblResult->Name = L"lblResult";
      this->lblResult->Size = System::Drawing::Size(259, 71);
      this->lblResult->TabIndex = 4;
      this->lblResult->Text = L"0";
      this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      // 
      // CalculatorForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(283, 168);
      this->Controls->Add(label4);
      this->Controls->Add(label3);
      this->Controls->Add(label2);
      this->Controls->Add(this->lblResult);
      this->Controls->Add(this->btnExec);
      this->Controls->Add(this->tbxRight);
      this->Controls->Add(this->cbxOpr);
      this->Controls->Add(this->tbxLeft);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
      this->MaximizeBox = false;
      this->Name = L"CalculatorForm";
      this->Text = L"Calculator";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion

  private:
    // '='ボタン・クリックのハンドラ
    System::Void btnExec_Click(System::Object^  sender, System::EventArgs^  e);

    [System::ComponentModel::Composition::Import(ICalculator::typeid)]
    ICalculator^ calculator_;
  };

}
