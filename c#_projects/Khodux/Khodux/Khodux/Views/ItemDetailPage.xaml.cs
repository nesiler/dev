using System.ComponentModel;
using Xamarin.Forms;
using Khodux.ViewModels;

namespace Khodux.Views
{
    public partial class ItemDetailPage : ContentPage
    {
        public ItemDetailPage()
        {
            InitializeComponent();
            BindingContext = new ItemDetailViewModel();
        }
    }
}
