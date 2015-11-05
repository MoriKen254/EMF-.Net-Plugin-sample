#include "Interface.h"

using namespace System;
using namespace System::ComponentModel::Composition;
using namespace System::Collections::Generic;

namespace SimpleCalculator {

  [Export(ICalculator::typeid)]
  ref class Calculator : ICalculator {
  private:
    [ImportMany]
    IEnumerable<System::Lazy<IOperation^, IOperationData^>^>^ operations_;

  public:
    // Symbol����v����IOperation�������A���s����
    virtual int Calculate(int left, System::String^ operation, int right) {
      for each (Lazy<IOperation^, IOperationData^>^ item in operations_) {
        if ( item->Metadata->Symbol == operation ) 
          return item->Value->Operate(left, right);
      }
      throw gcnew NotSupportedException(operation);
    }

    // Symbol�̗񋓂�Ԃ�
    virtual IEnumerable<System::String^>^ Symbols() {
      auto result = gcnew List<String^>();
      for each (Lazy<IOperation^, IOperationData^>^ item in operations_) {
        result->Add(item->Metadata->Symbol);
      }
      return result;      
    }

  };

}
