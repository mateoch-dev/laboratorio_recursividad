#include "../turtlec.h"

void clock(Turtle *t) {
  for (int i = 0; i < 13; i++) {
    turtlePenUp(t);
    turtleForward(t, 15);
    turtlePenDown(t);
    turtleForward(t, 5);
    turtleDraw(t);
    turtleUpdateDisplay(t);
    turtleHome(t);
    turtleRight(t, i * (360.0 / 12.0));
  }
}

void star(Turtle *t) {
  for (int i = 0; i < 5; i++) {
    turtleForward(t, 50.0f);
    turtleRight(t, 144.0f);
  }
}

void recursive_star(Turtle *t, int p) {
  if (p == 0)
    return;

  turtleForward(t, 50);
  turtleRight(t, 144);

  return recursive_star(t, p - 1);
}

void recursive_clock(Turtle *t, int p) {
  if (p == 0)
    return;

  turtlePenUp(t);
  turtleForward(t, 15);
  turtlePenDown(t);
  turtleForward(t, 5);
  turtleHome(t);
  turtleRight(t, p * 30.0);

  return recursive_clock(t, p - 1);
}

void recursive_tree(Turtle *t, int n, float tam) {
  if (n == 0)
    return;

  turtleForward(t, tam);

  turtleLeft(t, 30);
  recursive_tree(t, n - 1, 0.75 * tam);

  turtleRight(t, 60);
  recursive_tree(t, n - 1, 0.75 * tam);

  turtleLeft(t, 30);
  turtleBackward(t, tam);
}

void triangulo(Turtle *t, int n, float tam) {
  if (n == 0)
    return;

  turtleForward(t, tam);
  turtleLeft(t, 120);
  turtleForward(t, tam);
  turtleLeft(t, 120);
  turtleForward(t, tam);
  turtleLeft(t, 120);
  turtleForward(t, 2 * tam);
  turtleLeft(t, 120);
  turtleForward(t, tam);
  triangulo(t, n - 1, tam / 2);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(600, 600, "Test Line");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  triangulo(t, 5, 100);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 0.0001);

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
