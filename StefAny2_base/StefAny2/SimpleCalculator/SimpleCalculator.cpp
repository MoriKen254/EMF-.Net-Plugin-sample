#include "CalculatorForm.h"

using namespace System;

[STAThread]
int main(array<String^>^ args) {
  using namespace System::Windows::Forms;
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew SimpleCalculator::CalculatorForm());
  return 0;
}

