#include "Interface.h"

using namespace System::ComponentModel::Composition;

namespace SimpleCalculator {

  [Export(IOperation::typeid)]
  [ExportMetadata(L"Symbol", L"+")]
  ref class Add : IOperation {
  public:
    virtual int Operate(int left, int right) {
      return left + right;
    }
  };

  [Export(IOperation::typeid)]
  [ExportMetadata(L"Symbol", L"-")]
  ref class Subtract : IOperation {
  public: 
    virtual int Operate(int left, int right) {
      return left - right;
    }
  };
 
}
