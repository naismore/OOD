namespace testApp
{
    public partial class MainPage : ContentPage
    {
        int count = 0;

        public MainPage()
        {
            InitializeComponent();
        }

        private void OnCounterClicked(object sender, EventArgs e)
        {
            count++;

            if (count == 1)
                CounterBtn.Text = $"Вы нажали {count} раз";
            else
                CounterBtn.Text = $"Вы нажали {count} раз";

            SemanticScreenReader.Announce(CounterBtn.Text);
        }
    }

}
