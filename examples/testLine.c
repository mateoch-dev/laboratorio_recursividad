#include "../turtlec.h"
#include <math.h>

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

void fractalTree(Turtle *turtle, float length, int depth, int color) {
  if (depth == 0 || length < 5)
    return;

  turtleForward(turtle, length);

  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.8, depth - 1, ++color);

  turtleRight(turtle, 30);
  fractalTree(turtle, length * 0.7, depth - 1, ++color);

  turtleRight(turtle, 30);
  fractalTree(turtle, length * 0.6, depth - 1, ++color);

  if (depth < color)
    turtleSetColor(turtle, 20 + (color * 10), color * 10, 30 + (color * 10));

  turtleLeft(turtle, 30);
  turtleBackward(turtle, length);
}

void levy(Turtle *turtle, float length, int depth) {
  if (depth == 0) {
    turtleForward(turtle, length);
    return;
  }

  turtleLeft(turtle, 45);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleRight(turtle, 90);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleLeft(turtle, 45);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(600, 600, "Test Line");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  fractalTree(t, 80, 5, 1);
  /*levy(t, 50, 6);*/

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 0.1);

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
