#include "CalculatorForm.h"

using namespace System;
using namespace System::ComponentModel::Composition;
using namespace System::ComponentModel::Composition::Hosting;

namespace SimpleCalculator {

  CalculatorForm::CalculatorForm() {
    InitializeComponent();

    // Import/Export カタログをつくる 
    auto catalog = gcnew AggregateCatalog();
    // まずは自分自身のアセンブリから
    catalog->Catalogs->Add(gcnew AssemblyCatalog(CalculatorForm::typeid->Assembly));

    // そして自分自身の置かれたディレクトリから見つけてくる
    String^ myLocation = System::IO::Path::GetDirectoryName(
                           System::Reflection::MethodBase::GetCurrentMethod()
                           ->DeclaringType->Assembly->Location);
    catalog->Catalogs->Add(gcnew DirectoryCatalog(myLocation));

    // カタログから作られたコンテナを基にImport/Exportを結びつける
    AttributedModelServices::ComposeParts(gcnew CompositionContainer(catalog), this);

    // 得られた演算子(Symbol)をComboBoxに追加する
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
    // フォームから 左辺/右辺/演算子を取り出し、計算して結果を表示する
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
