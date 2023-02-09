using System;
using System.Collections.Generic;
using System.Text;

namespace кр
{

	public class Point
	{
		private int x;
		private int y;
		private int z;
		public int X { get; set; }
		public int Y { get; set; }
		public int Z { get; set; }

		public static Point operator +(Point p1, Point p2)
		{
			return new Point { X = p1.X + p2.X, Y = p1.Y + p2.Y, Z = p1.Z + p2.Z };
		}
		public static Point operator -(Point p1, Point p2)
		{
			return new Point { X = p1.X - p2.X, Y = p1.Y - p2.Y, Z = p1.Z - p2.Z };
		}
	}
}


