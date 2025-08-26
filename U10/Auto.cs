using System;

namespace _09_Klassen_2
{
    public class Auto
    {
        /// <summary>
        /// Farbe
        /// </summary>
        public string Farbe { get; set; }

        /// <summary>
        /// Marke
        /// </summary>
        public string Marke { get; set; }

        /// <summary>
        /// Default Konstruktor
        /// </summary>
        public Auto()
        {
            Marke = "Smart";
            Farbe = "Schwarz";
        }

        public Auto(string marke, string farbe)
        {
            Marke = marke;
            Farbe = farbe;
        }        

        /// <summary>
        /// Fahren
        /// </summary>
        /// <param name="km"></param>
        public void Fahren(int km)
        {
            Console.WriteLine($"Marke={Marke}, Fahren. KM={km}");
        }

        /// <summary>
        /// Tanken
        /// </summary>
        /// <param name="liter"></param>
        public void Tanken(int liter)
        {
            Console.WriteLine($"Marke={Marke}, Tanken. Liter={liter}");
        }
    }
}