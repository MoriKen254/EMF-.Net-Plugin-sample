#include "CalculatorForm.h"

using namespace System;
using namespace System::ComponentModel::Composition;
using namespace System::ComponentModel::Composition::Hosting;

namespace SimpleCalculator {

  CalculatorForm::CalculatorForm() {
    InitializeComponent();

    // Import/Export �J�^���O������ 
    auto catalog = gcnew AggregateCatalog();
    // �܂��͎������g�̃A�Z���u������
    catalog->Catalogs->Add(gcnew AssemblyCatalog(CalculatorForm::typeid->Assembly));

    // �����Ď������g�̒u���ꂽ�f�B���N�g�����猩���Ă���
    String^ myLocation = System::IO::Path::GetDirectoryName(
                           System::Reflection::MethodBase::GetCurrentMethod()
                           ->DeclaringType->Assembly->Location);
    catalog->Catalogs->Add(gcnew DirectoryCatalog(myLocation));

    // �J�^���O������ꂽ�R���e�i�����Import/Export�����т���
    AttributedModelServices::ComposeParts(gcnew CompositionContainer(catalog), this);

    // ����ꂽ���Z�q(Symbol)��ComboBox�ɒǉ�����
    for each ( String^ symbol in calculator_->Symbols() ) {
      cbxOpr->Items->Add(symbol);
    }
    cbxOpr->SelectedIndex = 0;
  }

  CalculatorForm::~CalculatorForm() {
    if (components) {
      delete components;
    }
  }

  System::Void CalculatorForm::btnExec_Click(System::Object^  sender, System::EventArgs^  e) {
    Int32 left;
    Int32 right;
    // �t�H�[������ ����/�E��/���Z�q�����o���A�v�Z���Č��ʂ�\������
    if ( Int32::TryParse(tbxLeft->Text, left) && Int32::TryParse(tbxRight->Text, right) ) {
      try {
        int result = calculator_->Calculate(left, cbxOpr->SelectedItem->ToString(), right);
        lblResult->Text = result.ToString();
      } catch ( Exception^  ) {
        lblResult->Text = L"error";
      }
    } else {
      lblResult->Text = L"?";
    }
  }

}
