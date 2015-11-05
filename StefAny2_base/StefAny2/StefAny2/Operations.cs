using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.ComponentModel.Composition;

namespace StefAny2
{
  [Export(typeof(IOperation))]
  [ExportMetadata("Symbol", "+")]
  class Add : IOperation {
  public int Operate(int left, int right) {
      return left + right;
    }
  };
  
  [Export(typeof(IOperation))]
  [ExportMetadata("Symbol", "-")]
  class Subtract : IOperation {
  public int Operate(int left, int right) {
      return left - right;
    }
  };
}
