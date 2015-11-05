using System.ComponentModel.Composition;
using SimpleCalculator;

namespace ExtendedOperations {

  [Export(typeof(IOperation))]
  [ExportMetadata("Symbol", "%")]
  class Modulus : IOperation {
    public int Operate(int left, int right) {
      return left % right;
    }
  };

  [Export(typeof(IOperation))]
  [ExportMetadata("Symbol", "MIN")]
  class Minimum : IOperation {
    public int Operate(int left, int right) {
      return left < right ? left : right;
    }
  };

  [Export(typeof(IOperation))]
  [ExportMetadata("Symbol", "MAX")]
  class Maxumum : IOperation {
    public int Operate(int left, int right) {
      return left > right ? left : right;
    }
  };
}
