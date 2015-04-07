#include <stdio.h>
#include "vms.h"
int errors = 1;
int main(){
  setup();
  while(1){
  redo:
    error = camera_update();
    if(error == 0) goto redo;
    x = set_vars();
    if(x.errors != 0){
      goto redo;
    }
    else{
      printf("area: %f, height: %f, width: %f, normal width: %f, easy distance: %f, angle: %f, true distance: %f", x.area, x.height, x.width, x.normal_width, x.easy_di\
             stance, x.angle, x.true_distance);
    }
    msleep(100);
  }
}
