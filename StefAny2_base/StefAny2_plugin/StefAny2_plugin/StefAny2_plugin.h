// StefAny2_plugin.h

#pragma once

using namespace System;
using namespace System::ComponentModel::Composition;
using namespace StefAny2;

namespace StefAny2_plugin {

  [Export(IOperation::typeid)]
  [ExportMetadata(L"Symbol", L"++")]
  ref class AddAdd : IOperation {
  public:
    virtual int Operate(int left, int right) {
      return left + right + left;
    }
  };
}
