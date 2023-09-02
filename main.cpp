#include <iostream>
#include <vector>
using namespace std;

void linearSearch(vector<string> grid, int &botPositionX, int &botPositionY, int &princessPositionX, int &princessPositionY)
{
  int n = grid.size();

  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < n; x++)
    {
      if (grid[y][x] == 'm')
      {
        botPositionX = x;
        botPositionY = y;
      }
      else if (grid[y][x] == 'p')
      {
        princessPositionX = x;
        princessPositionY = y;
      }
    }
  }
}

void displayPathtoPrincess(int n, vector<string> grid)
{
  int botPositionX, botPositionY, princessPositionX, princessPositionY;

  cout << "ANALISIS: " << endl;

  // ALGORITMO DE BUSQUEDA LINEAL PARA ENCONTRAR LA POSICION DE LA PRINCESA Y EL ROBOT
  cout << "Buscando posicion de princesa y robot..." << endl;
  linearSearch(grid, botPositionX, botPositionY, princessPositionX, princessPositionY);
  cout << "Posicion del robot: (" << botPositionX << "," << botPositionY << ")" << endl;
  cout << "Posicion de la princesa: (" << princessPositionX << "," << princessPositionY << ")" << endl;

  // Calcular diferencia de posiciones de la princesa y el robot
  int dX = princessPositionX - botPositionX;
  int dY = princessPositionY - botPositionY;

  cout << "Calculando diferencia de posiciones..." << endl;
  cout << "dX: " << dX << endl;
  cout << "dY: " << dY << endl;

  // calcular variables para contar el numero de movimientos, tanto en X como en Y.
  int movementsInX = 0;
  int movementsInY = 0;

  cout << "Realizando movimientos..." << endl
       << "Resultados:" << endl
       << endl;

  // movimientos en Y
  if (dY > 0)
  {
    for (int i = 0; i < dY; i++)
    {
      cout << "DOWN" << endl;
      movementsInY++;
    }
  }
  else if (dY < 0)
  {
    for (int i = 0; i < -dY; i++)
    {
      cout << "UP" << endl;
      movementsInY++;
    }
  }

  // movimientos en X
  if (dX > 0)
  {
    for (int i = 0; i < dX; i++)
    {
      cout << "RIGHT" << endl;
      movementsInX++;
    }
  }
  else if (dX < 0)
  {
    for (int i = 0; i < -dX; i++)
    {
      cout << "LEFT" << endl;
      movementsInX++;
    }
  }

  float score = (n * n - (movementsInX + movementsInY)) / 10.0;
  cout << "Tu puntuacion es: " << score;
}

bool validateGrid(vector<string> grid)
{
  int botCount = 0;
  int princessCount = 0;

  for (string row : grid)
  {
    for (char cell : row)
    {
      if (cell == 'm')
      {
        botCount++;
      }
      else if (cell == 'p')
      {
        princessCount++;
      }
    }
  }

  return botCount == 1 && princessCount == 1;
}

int main(void)
{
  vector<string> grid;
  int n;

  do
  {
    cout << "Ingrese el numero de columnas y filas: ";
    cin >> n;
    if (!(n >= 3 && n > 100) && n % 2 == 0)
    {
      cout << "n, debe ser un numero entero impar y (3 <= N < 100)."
           << endl
           << "Ingreselo nuevamente." << endl;
    }
  } while (!(n >= 3 && n > 100) && n % 2 == 0);

  cout << endl
       << "||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
  cout << "Ingrese el tablero: " << endl;
  cout << "Cada celda se indica con '-' (valor ascii: 45)." << endl;
  cout << "La posición del bot se indica con 'm'" << endl;
  cout << "la posición de la princesa se indica con 'p'." << endl;
  cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl
       << endl;

  do
  {
    grid.clear();
    for (int i = 0; i < n; i++)
    {
      string s;
      do
      {
        cout << "[" << i + 1 << "] ";
        cin >> s;
        if (s.length() != n)
        {
          cout << "Esta fila tiene que tener " << n << " caracteres. " << endl
               << "Ingresela nuevamente." << endl;
        }
      } while (s.length() != n);
      grid.push_back(s);
    }
    if (!validateGrid(grid))
    {
      cout << "La matriz debe contener una sola posición para el robot y una para la princesa." << endl
           << "Ingresela nuevamente." << endl;
    }
  } while (!validateGrid(grid));

  displayPathtoPrincess(n, grid);

  return 0;
}
