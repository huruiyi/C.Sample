using System;
using System.Collections.Generic;

namespace _00CSDemoFun
{
    internal class Program
    {
        public static List<int> YuList = new List<int>();

        private static void Qiuyu(int num, int wei)
        {
            int m = num;
            int n = num % wei;
            num = num / wei;

            Console.WriteLine("{0}÷{3} ={1}。。。{2}", m.ToString().PadLeft(7, ' '), num.ToString().PadLeft(7, ' '), n, wei);
            if (num > 0)
            {
                Qiuyu(num, wei);
            }
            //YuList.Reverse
            YuList.Add(n);
        }

        private static void PrintResult(int num, int wei)
        {
            YuList = new List<int>();
            Qiuyu(num, wei);

            if (wei == 16)
            {
                YuList.ForEach(i => Console.Write(Convert.ToString(i, 16).ToUpper()));
            }
            else
            {
                YuList.ForEach(i => Console.Write(i));
            }
            Console.WriteLine();
        }

        private unsafe static void Main(string[] args)
        {
            unsafe
            {
                int a = 10;
                int* p = &a;
            }
            //年月日，位数
            PrintResult(Convert.ToInt32(args[0]), Convert.ToInt32(args[1]));
            Console.ReadKey();
        }
    }
}