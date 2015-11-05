using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.ComponentModel.Composition;

namespace StefAny2
{
  [Export(typeof(ICalculator))]
  public class Calculator : ICalculator
  {
    [ImportMany]
    private IEnumerable<System.Lazy<IOperation, IOperationData>> operations_;

    // Symbolが一致するIOperationを見つけ、実行する
    public int Calculate(int left, System.String operation, int right) {
      foreach (Lazy<IOperation, IOperationData> item in operations_) {
        if ( item.Metadata.Symbol == operation ) 
          return item.Value.Operate(left, right);
      }
      throw new NotSupportedException(operation);
    }

    // Symbolの列挙を返す
    public IEnumerable<System.String> Symbols() {
      var result = new List<String>();
      foreach (Lazy<IOperation, IOperationData> item in operations_) {
        result.Add(item.Metadata.Symbol);
      }
      return result;      
    }
  }
}
