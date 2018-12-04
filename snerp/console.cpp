
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "console.h"

void initConsole() {
  if (AttachConsole(ATTACH_PARENT_PROCESS) || AllocConsole()) {
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
  }
}
