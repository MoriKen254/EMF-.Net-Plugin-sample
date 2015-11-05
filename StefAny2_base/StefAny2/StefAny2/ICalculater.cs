using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StefAny2
{
  public interface ICalculator {
    int Calculate(int left, System.String opr, int right);
    System.Collections.Generic.IEnumerable<System.String> Symbols();
  };
}
