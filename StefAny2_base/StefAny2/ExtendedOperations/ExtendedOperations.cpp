#include "stdafx.h"

namespace ExtendedOperations {

  using namespace System::ComponentModel::Composition;
  //using namespace SimpleCalculator;
  using namespace StefAny2;

  [Export(IOperation::typeid)]
  [ExportMetadata(L"Symbol", L"*")]
  ref class Multiple : IOperation {
  public:
    virtual int Operate(int left, int right) {
      return left * right;
    }
  };

  [Export(IOperation::typeid)]
  [ExportMetadata(L"Symbol", L"/")]
  ref class Devide : IOperation {
  public: 
    virtual int Operate(int left, int right) {
      return left / right;
    }
  };

}
