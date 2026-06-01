
#include "../turtlec.h"

int main(void) {
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtlePenDown(t);

  for (int i = 0; i < 12; i++) {
    turtlePenUp(t);
    turtleForward(t, 48.0f);
    turtlePenDown(t);
    turtleForward(t, 2);
    turtleRight(t, i * (360.0f / 12.0f));
    turtleHome(t);
  }
  turtleSetColor(t, 255, 255, 255);
  turtleSetSpeed(t, 5.0f);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
