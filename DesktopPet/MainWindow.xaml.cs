using DesktopPet.Models;
using DesktopPet.Services;
using System.Drawing;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media.Imaging;
using Forms = System.Windows.Forms;

namespace DesktopPet;

public partial class MainWindow : Window
{
    private readonly AnimationPlayer _player;
    private readonly Dictionary<PetAction, List<BitmapImage>> _frames;
    private readonly Random _random = new();
    private readonly System.Windows.Threading.DispatcherTimer _aiTimer;
    private readonly Forms.NotifyIcon _notifyIcon;

    private bool _isDragging;
    private Point _dragMouseStart;
    private Point _windowStart;

    public MainWindow()
    {
        InitializeComponent();

        _player = new AnimationPlayer(PetImage);
        _frames = LoadActionFrames();

        _notifyIcon = CreateTrayIcon();
        Closed += (_, _) => _notifyIcon.Dispose();

        PlayAction(PetAction.Idle);

        _aiTimer = new System.Windows.Threading.DispatcherTimer
        {
            Interval = TimeSpan.FromSeconds(3)
        };
        _aiTimer.Tick += (_, _) => Think();
        _aiTimer.Start();
    }

    private Dictionary<PetAction, List<BitmapImage>> LoadActionFrames()
    {
        var root = System.IO.Path.Combine(AppContext.BaseDirectory, "Assets", "cat");
        return new Dictionary<PetAction, List<BitmapImage>>
        {
            [PetAction.Idle] = SpriteLoader.LoadFrames(System.IO.Path.Combine(root, "idle")),
            [PetAction.Walk] = SpriteLoader.LoadFrames(System.IO.Path.Combine(root, "walk"))
        };
    }

    private Forms.NotifyIcon CreateTrayIcon()
    {
        var menu = new Forms.ContextMenuStrip();
        menu.Items.Add("显示/隐藏", null, (_, _) => ToggleVisibility());
        menu.Items.Add("退出", null, (_, _) => Close());

        return new Forms.NotifyIcon
        {
            Text = "Desktop Pet",
            Icon = SystemIcons.Application,
            Visible = true,
            ContextMenuStrip = menu
        };
    }

    private void ToggleVisibility()
    {
        if (IsVisible)
        {
            Hide();
        }
        else
        {
            Show();
            Activate();
        }
    }

    private void Think()
    {
        if (_isDragging)
        {
            return;
        }

        if (_random.Next(100) < 45)
        {
            PlayAction(PetAction.Walk);
            Left = Math.Max(0, Left + _random.Next(-35, 36));
        }
        else
        {
            PlayAction(PetAction.Idle);
        }
    }

    private void PlayAction(PetAction action)
    {
        var frames = _frames[action];
        var fps = action == PetAction.Walk ? 10 : 6;
        _player.Play(frames, fps);
    }

    private void PetImage_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
    {
        _isDragging = true;
        _dragMouseStart = PointToScreen(e.GetPosition(this));
        _windowStart = new Point(Left, Top);
        PetImage.CaptureMouse();
    }

    private void PetImage_MouseMove(object sender, MouseEventArgs e)
    {
        if (!_isDragging)
        {
            return;
        }

        var current = PointToScreen(e.GetPosition(this));
        var delta = current - _dragMouseStart;
        Left = _windowStart.X + delta.X;
        Top = _windowStart.Y + delta.Y;
    }

    private void PetImage_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
    {
        _isDragging = false;
        PetImage.ReleaseMouseCapture();
    }
}
