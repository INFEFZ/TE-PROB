enum Fahrzeugtyp {
  TYP_PKW,
  TYP_LKW,
};

struct Auto {
  enum Fahrzeugtyp fahrzeugtyp;
  char             marke[20];
  double           maxv;
};

struct Lastwagen {
  enum Fahrzeugtyp fahrzeugtyp;
  int              achsen;
  double           gewicht;
};
