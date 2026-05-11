using System.IO;
using System.Windows.Media.Imaging;

namespace DesktopPet.Services;

public static class SpriteLoader
{
    public static List<BitmapImage> LoadFrames(string folderPath)
    {
        if (!Directory.Exists(folderPath))
        {
            return new List<BitmapImage>();
        }

        var files = Directory.GetFiles(folderPath, "*.png")
            .OrderBy(path => path)
            .ToList();

        var frames = new List<BitmapImage>();
        foreach (var file in files)
        {
            var image = new BitmapImage();
            image.BeginInit();
            image.CacheOption = BitmapCacheOption.OnLoad;
            image.UriSource = new Uri(file, UriKind.Absolute);
            image.EndInit();
            image.Freeze();
            frames.Add(image);
        }

        return frames;
    }
}
