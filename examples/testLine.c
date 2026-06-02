#include "../turtlec.h"
#include <math.h>

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;

  int r = (depth * 80) % 200 + 55;
  int g = (depth * 120 + 30) % 200 + 55;
  int b = (depth * 160 + 60) % 200 + 55;

  turtleSetColor(turtle, r, g, b);

  turtleForward(turtle, length);

  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.8, depth - 1);

  turtleRight(turtle, 30);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleRight(turtle, 30);
  fractalTree(turtle, length * 0.6, depth - 1);

  turtleSetColor(turtle, r, g, b);

  turtleLeft(turtle, 30);
  turtleBackward(turtle, length);
}

void levy(Turtle *turtle, float length, int depth) {
  if (depth == 0) {
    turtleForward(turtle, length);
    return;
  }

  int r = (depth * 80) % 200 + 55;
  int g = (depth * 120 + 30) % 200 + 55;
  int b = (depth * 160 + 60) % 200 + 55;
  turtleSetColor(turtle, r, g, b);

  turtleLeft(turtle, 45);
  levy(turtle, length / sqrt(2), depth - 1);

  r = (depth * 70 + 140) % 200 + 55;
  g = (depth * 50 + 30) % 200 + 55;
  b = (depth * 100 + 160) % 200 + 55;
  turtleSetColor(turtle, r, g, b);

  turtleRight(turtle, 90);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleLeft(turtle, 45);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(1000, 1000, "Test Line");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  /*fractalTree(t, 80, 4);*/
  levy(t, 150, 6);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 0.1);

  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
