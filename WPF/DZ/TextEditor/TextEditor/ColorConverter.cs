﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using System.Windows.Media;

namespace TextEditor
{
    public class ColorConverter : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (value != null)
            {
                return new SolidColorBrush((Color)value);
            }
            else
                return Colors.Black;
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (value != null)
            {
                Color color = (Color)value;
                return new SolidColorBrush(color);
            }
            else
                return new SolidColorBrush(Colors.Black);
        }
    }
}
