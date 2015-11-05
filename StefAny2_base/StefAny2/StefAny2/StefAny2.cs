using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.ComponentModel.Composition;
using System.ComponentModel.Composition.Hosting;

namespace StefAny2
{
  public partial class StefAny2 : Form
  {
    public StefAny2()
    {
      InitializeComponent();
      // Import/Export カタログをつくる 
      var catalog = new AggregateCatalog();
      // まずは自分自身のアセンブリから
      catalog.Catalogs.Add(new AssemblyCatalog(typeof(StefAny2).Assembly));

      // そして自分自身の置かれたディレクトリから見つけてくる
      String myLocation = System.IO.Path.GetDirectoryName(
                             System.Reflection.MethodBase.GetCurrentMethod()
                             .DeclaringType.Assembly.Location);
      catalog.Catalogs.Add(new DirectoryCatalog(myLocation));

      // カタログから作られたコンテナを基にImport/Exportを結びつける
      //AttributedModelServices.ComposeParts(new CompositionContainer(catalog), this);
      CompositionContainer container_ = new CompositionContainer(catalog);
      try
      {
        container_.ComposeParts(this);
      }
      catch (CompositionException compositionException)
      {
        String a = compositionException.ToString();
      }
    }

    private void button1_Click(object sender, EventArgs e)
    {
    Int32 left = 1;
    Int32 right = 2;
    // フォームから 左辺/右辺/演算子を取り出し、計算して結果を表示する
      try {
        int result;
        result = calculator_.Calculate(left, "++", right);
        result = calculator_.Calculate(left, "+", right);
        result = calculator_.Calculate(left, "-", right);
        result = calculator_.Calculate(left, "/", right);
        result = calculator_.Calculate(left, "*", right);
        result = calculator_.Calculate(left, "%", right);
        result = calculator_.Calculate(left, "MIN", right);
        result = calculator_.Calculate(left, "MAX", right);
      } catch ( Exception ) {
      }
    }

    [System.ComponentModel.Composition.Import(typeof(ICalculator))]
    private ICalculator calculator_;
  }
}
