#include "../turtlec.h"

int main(void) {
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 100.0f);
  turtlePenDown(t);

  for (int i = 0; i < 5; i++) {
    turtleForward(t, 50.0f);
    turtleRight(t, 144.0f);
  }
  turtleSetColor(t, 255, 255, 255);
  turtleSetSpeed(t, 5.0f);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
