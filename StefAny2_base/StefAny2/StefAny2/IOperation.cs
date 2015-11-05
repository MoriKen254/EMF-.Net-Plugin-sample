using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StefAny2
{
  public interface IOperation {
    int Operate(int left, int right);
  };

  public interface IOperationData {
    System.String Symbol { get; }
  };
}
