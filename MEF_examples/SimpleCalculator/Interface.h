#ifndef INTERFACE_H_
#define INTERFACE_H_

namespace SimpleCalculator {

  public interface class IOperation {
    int Operate(int left, int right);
  };

  public interface class IOperationData {
    property System::String^ Symbol { System::String^ get(); }
  };

  public interface class ICalculator {
    int Calculate(int left, System::String^ opr, int right);
    System::Collections::Generic::IEnumerable<System::String^>^ Symbols();
  };

}

#endif
