using System.Windows.Controls;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace DesktopPet.Services;

public sealed class AnimationPlayer
{
    private readonly Image _target;
    private readonly DispatcherTimer _timer;
    private List<BitmapImage> _frames = new();
    private int _index;

    public AnimationPlayer(Image target)
    {
        _target = target;
        _timer = new DispatcherTimer();
        _timer.Tick += (_, _) => NextFrame();
    }

    public void Play(List<BitmapImage> frames, int fps)
    {
        _frames = frames;
        _index = 0;

        if (_frames.Count == 0)
        {
            _timer.Stop();
            _target.Source = null;
            return;
        }

        _target.Source = _frames[0];
        _timer.Interval = TimeSpan.FromMilliseconds(1000.0 / Math.Max(fps, 1));
        _timer.Start();
    }

    private void NextFrame()
    {
        if (_frames.Count == 0)
        {
            return;
        }

        _index = (_index + 1) % _frames.Count;
        _target.Source = _frames[_index];
    }
}
